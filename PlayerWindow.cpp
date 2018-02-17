#include "PlayerWindow.hpp"
#include "ExternalProcess.hpp"
#include <QPushButton>
#include <QSlider>
#include <QLayout>
#include <QMessageBox>
#include <QFileDialog>

#include <memory>
#include <iostream>

using namespace QtAV;

PlayerWindow::PlayerWindow(QWidget *parent) : QWidget(parent)
{
    unit = 1000;

    player = new AVPlayer(this);
    player->setBufferValue(1);

    slider = new QSlider();
    slider->setOrientation(Qt::Horizontal);

    progressBar = new QProgressBar();

    connect(slider, SIGNAL(sliderMoved(int)), SLOT(seekBySlider(int)));
    connect(slider, SIGNAL(sliderPressed()), SLOT(seekBySlider()));
    connect(player, SIGNAL(positionChanged(qint64)), SLOT(updateSlider(qint64)));
    connect(player, SIGNAL(started()), SLOT(updateSlider()));
    connect(player, SIGNAL(notifyIntervalChanged()), SLOT(updateSliderUnit()));
}

void PlayerWindow::init()
{
    setupOutput();
    btns();
    layout();

    this->currentVideo = NULL;
}

void PlayerWindow::setupOutput()
{
    videoOutput = new VideoOutput(this);
    if (!videoOutput->widget()) {
        QMessageBox::warning(0, QString::fromLatin1("QtAV error"), tr("Can not create video renderer"));
        return;
    }
    player->setRenderer(videoOutput);

}

void PlayerWindow::layout()
{
    QVBoxLayout *vl = new QVBoxLayout(this);
    vl->addWidget(videoOutput->widget());
    vl->addWidget(slider);

    QHBoxLayout *hb = new QHBoxLayout();

    vl->addLayout(hb);
    vl->addWidget(downloadBtn);
    vl->addWidget(progressBar);

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
    connect(currentVideo, SIGNAL(audioDownloadFinished(QString, QString)), this, SLOT (enableBtn(QString, QString)), Qt::UniqueConnection);
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
    if (!currentVideo)
        return;
    connect(currentVideo->getHandler(), SIGNAL(downloadProgress(qint64, qint64)), SLOT(changeDownloadProgress(qint64, qint64)));
    downloadBtn->setEnabled(false);
    currentVideo->download();
}

void PlayerWindow::enableBtn(QString _, QString __)
{
    downloadBtn->setEnabled(true);
}

void PlayerWindow::changeDownloadProgress(qint64 currentProgress, qint64 totalBytes)
{
    progressBar->setMaximum(totalBytes);
    progressBar->setValue(currentProgress);

    if (currentProgress == totalBytes)
        progressBar->reset();
}


AudioPlayer::AudioPlayer(QList < QString > tracks) :
    trackList(tracks)
{
    progressBar = new QProgressBar();

    setupOutput();
    btns();
    layout();
}
void AudioPlayer::openMedia(int index)
{
    this->index = index;
    qDebug() << "Song to play : " << trackList.at(index);

    player->setFile(trackList.at(index));
    player->play();
}
void AudioPlayer::updateTrackList(QList < QString > tracks)
{
    this->trackList = tracks;
}
void AudioPlayer::btns()
{
    backBtn = new QPushButton("<--");
    playBtn = new QPushButton("Play/Pause");
    forwardBtn = new QPushButton("-->");
    burnBtn = new QPushButton("Burn");

    connect(playBtn, SIGNAL(clicked()), SLOT(playPause()));
    connect(forwardBtn, SIGNAL(clicked()), SLOT(nextSong()));
    connect(backBtn, SIGNAL(clicked()), SLOT(previousSong()));
    connect(burnBtn, SIGNAL(clicked()), SLOT(burnPlaylist()));
}
void AudioPlayer::nextSong()
{
    index++;

    if (index == trackList.size())
        index = 0;

    player->setFile(trackList.at(index));
    player->play();
}
void AudioPlayer::previousSong()
{
    index--;

    if (index == -1)
        index = 0;
    player->setFile(trackList.at(index));
    player->play();
}
void AudioPlayer::burnPlaylist()
{
    if (!trackList.length())
        return;
    progressBar->reset();
    BurnerThread* burner = new BurnerThread(this->trackList, "cdrecord");
    progressBar->setMaximum(this->trackList.length());
    progressBar->setValue(0);

    connect(burner, SIGNAL(changeProgress()), this, SLOT(changeBurnProgress()));
}
void AudioPlayer::changeBurnProgress()
{
    qDebug() << "Progress Made " << currentProgress;
    currentProgress++;
    progressBar->setValue(currentProgress);
}
void AudioPlayer::layout()
{

    QVBoxLayout *vl = new QVBoxLayout(this);
    vl->addWidget(slider);

    QHBoxLayout *hb = new QHBoxLayout();

    vl->addLayout(hb);
    vl->addWidget(burnBtn);
    vl->addWidget(progressBar);

    hb->addWidget(backBtn);
    hb->addWidget(playBtn);
    hb->addWidget(forwardBtn);
}

