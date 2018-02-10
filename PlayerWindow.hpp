#ifndef PLAYERWINDOW_H
#define PLAYERWINDOW_H

#include <QWidget>
#include <QtAV/QtAV.h>
#include <QComboBox>
#include <QProgressBar>
#include "VideoYoutube.hpp"

QT_BEGIN_NAMESPACE
class QSlider;
class QPushButton;
QT_END_NAMESPACE
class PlayerWindow : public QWidget
{
    Q_OBJECT
public:
    explicit PlayerWindow(QWidget *parent = 0);

    void init();

public Q_SLOTS:
    virtual void openMedia(VideoYoutube*);
    void seekBySlider(int value);
    void seekBySlider();
    void playPause();

private Q_SLOTS:
    void startDownload();
    void changeQuality(int);
    void changeDownloadProgress(qint64, qint64);

protected Q_SLOTS:
    void updateSlider(qint64 value);
    void updateSlider();
    void updateSliderUnit();

private:
    QtAV::VideoOutput *videoOutput;
    VideoYoutube *currentVideo;
    QPushButton *downloadBtn;
    QPushButton *stopBtn;
    QComboBox *quality;

    void refresh();

protected:
    QtAV::AVPlayer *player;
    QPushButton *playBtn;
    QSlider *slider;
    QProgressBar *progressBar;
    int unit;

    void setupOutput();

    virtual void btns();
    virtual void layout();

};

class AudioPlayer : public PlayerWindow
{
    Q_OBJECT;

    public:
    explicit AudioPlayer();

    public Q_SLOTS:
        void openMedia(QList < QString >, int);

    private Q_SLOTS:
        void changeBurnProgress();
        void nextSong();
        void previousSong();
        void burnPlaylist();
    private:
    QPushButton *backBtn;
    QPushButton *forwardBtn;
    QPushButton *burnBtn;

    QList < QString > trackList;
    std::string runCmd(char * cmd);
    int index;
    int currentProgress;

    protected:
    void layout();
    void btns();

};

#endif // PLAYERWINDOW_H
