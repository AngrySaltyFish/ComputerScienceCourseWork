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

    hb->addWidget(quality);
    hb->addWidget(playBtn);
    hb->addWidget(stopBtn);
}

void PlayerWindow::btns()
{
    playBtn = new QPushButton(tr("Play/Pause"));
    stopBtn = new QPushButton(tr("Stop"));
    quality = new QComboBox();

    connect(playBtn, SIGNAL(clicked()), SLOT(playPause()));
    connect(stopBtn, SIGNAL(clicked()), player, SLOT(stop()));
    connect(quality, SIGNAL(currentIndexChanged(int)), this, SLOT(changeQuality(int)));

    connect(slider, SIGNAL(sliderMoved(int)), SLOT(seekBySlider(int)));
    connect(slider, SIGNAL(sliderPressed()), SLOT(seekBySlider()));
    connect(player, SIGNAL(positionChanged(qint64)), SLOT(updateSlider(qint64)));
    connect(player, SIGNAL(started()), SLOT(updateSlider()));
    connect(player, SIGNAL(notifyIntervalChanged()), SLOT(updateSliderUnit()));
}

void PlayerWindow::openMedia(VideoYoutube *video)
{
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
    //TODO::Fix this so no seg fault and jump to appropiate time
    //qDebug() << index;
    //currentVideo->setQuality(index);
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
