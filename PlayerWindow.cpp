#include "PlayerWindow.hpp"
#include <QPushButton>
#include <QSlider>
#include <QLayout>
#include <QMessageBox>
#include <QFileDialog>

using namespace QtAV;

PlayerWindow::PlayerWindow(QWidget *parent) : QWidget(parent)
{
    init();
    btns();
    layout();
}

void PlayerWindow::init()
{
    unit = 1000;
    player = new AVPlayer(this);
    player->setBufferValue(1);
    videoOutput = new VideoOutput(this);
    if (!videoOutput->widget()) {
        QMessageBox::warning(0, QString::fromLatin1("QtAV error"), tr("Can not create video renderer"));
        return;
    }
    player->setRenderer(videoOutput);

    downloadProgress = new QProgressBar();
    slider = new QSlider();
    slider->setOrientation(Qt::Horizontal);
}

void PlayerWindow::layout()
{
    QVBoxLayout *vl = new QVBoxLayout(this);
    vl->addWidget(videoOutput->widget());
    vl->addWidget(slider);

    QHBoxLayout *hb = new QHBoxLayout();

    vl->addLayout(hb);
    vl->addWidget(downloadBtn);
    vl->addWidget(downloadProgress);

    hb->addWidget(quality);
    hb->addWidget(playBtn);
    hb->addWidget(stopBtn);
}

void PlayerWindow::btns()
{
    downloadBtn = new QPushButton("Download");
    playBtn = new QPushButton(tr("Play/Pause"));
    stopBtn = new QPushButton(tr("Stop"));
    quality = new QComboBox();

    connect(playBtn, SIGNAL(clicked()), SLOT(playPause()));
    connect(stopBtn, SIGNAL(clicked()), player, SLOT(stop()));
    connect(downloadBtn, SIGNAL(clicked()), SLOT(startDownload()));
    connect(quality, SIGNAL(currentIndexChanged(int)), this, SLOT(changeQuality(int)));

    connect(slider, SIGNAL(sliderMoved(int)), SLOT(seekBySlider(int)));
    connect(slider, SIGNAL(sliderPressed()), SLOT(seekBySlider()));
    connect(player, SIGNAL(positionChanged(qint64)), SLOT(updateSlider(qint64)));
    connect(player, SIGNAL(started()), SLOT(updateSlider()));
    connect(player, SIGNAL(notifyIntervalChanged()), SLOT(updateSliderUnit()));
}

void PlayerWindow::openMedia(VideoYoutube *video)
{
    this->currentVideo = NULL;
    QList< QPair<QString, int> > qualities = video->getSupportedQualities();

    quality->clear();
    qDebug() << qualities.size();

    for (int i = 0; i< qualities.size(); i++)
        quality->addItem(qualities[i].first);

    player->play(video->getVideoUrl());
    player->setExternalAudio(video->getAudioUrl());
    currentVideo = video;
}

void PlayerWindow::changeQuality(int index)
{
    if (currentVideo)
    {
        currentVideo->setQuality(index);
        refresh();
    }
}

void PlayerWindow::refresh()
{
    player->play(currentVideo->getVideoUrl());
    player->setAudioStream(currentVideo->getAudioUrl(), 1);
}

void PlayerWindow::seekBySlider(int value)
{
    if (!player->isPlaying())
        return;
    player->seek(qint64(value*unit));
}

void PlayerWindow::seekBySlider()
{
    seekBySlider(slider->value());
}

void PlayerWindow::playPause()
{
    if (!player->isPlaying()) {
        player->play();
        return;
    }
    player->pause(!player->isPaused());
}

void PlayerWindow::updateSlider(qint64 value)
{
    slider->setRange(0, int(player->duration()/unit));
    slider->setValue(int(value/unit));
}

void PlayerWindow::updateSlider()
{
    updateSlider(player->position());
}

void PlayerWindow::updateSliderUnit()
{
    unit = player->notifyInterval();
    updateSlider();
}

void PlayerWindow::startDownload()
{
    connect(currentVideo->getHandler(), SIGNAL(downloadProgress(qint64, qint64)), SLOT(changeDownloadProgress(qint64, qint64)));
    currentVideo->download();
}

void PlayerWindow::changeDownloadProgress(qint64 currentProgress, qint64 totalBytes)
{
    downloadProgress->setMaximum(totalBytes);
    downloadProgress->setValue(currentProgress);
}
