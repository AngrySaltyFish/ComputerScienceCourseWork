#ifndef PLAYERWINDOW_H
#define PLAYERWINDOW_H

#include <QWidget>
#include <QtAV/QtAV.h>
#include <QComboBox>
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
public Q_SLOTS:
    void openMedia(VideoYoutube*);
    void seekBySlider(int value);
    void seekBySlider();
    void playPause();
private Q_SLOTS:
    void changeQuality(int);
    void updateSlider(qint64 value);
    void updateSlider();
    void updateSliderUnit();

private:
    QtAV::VideoOutput *videoOutput;
    QtAV::AVPlayer *player;
    VideoYoutube *currentVideo;
    QSlider *slider;
    QPushButton *playBtn;
    QPushButton *stopBtn;
    QComboBox *quality;
    int unit;

    void init();
    void btns();
    void layout();
};

#endif // PLAYERWINDOW_H
