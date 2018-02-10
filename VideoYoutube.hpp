

#ifndef VIDEOYOUTUBE_H
#define VIDEOYOUTUBE_H

#include <qglobal.h>
#if QT_VERSION < QT_VERSION_CHECK(5,0,0)
#include <QtWebKit>
#else
#include <QtWebKit/QtWebKit>
#endif
#include <QtGui>
#include <QFile>
#include <QDomDocument>
#include "HttpHandler.hpp"

struct videoQuality
{
    QString quality;
    QString videoUrl;
    QString audioUrl;
    QStringList videoSegments;
    QStringList audioSegments;
    QString containerName;
    bool chunkedDownload;
    int resolution;

    videoQuality()
    {
        quality = "standard";
        chunkedDownload = false;
        resolution = 0;
    }

    videoQuality(QString Quality, QString VideoUrl)
    {
        quality = Quality;
        videoUrl = VideoUrl;
        chunkedDownload = false;
        resolution = 0;
    }

    videoQuality(QString Quality, QString VideoUrl, bool ChunkedDownload)
    {
        quality = Quality;
        videoUrl = VideoUrl;
        chunkedDownload = ChunkedDownload;
        resolution = 0;
    }

    bool operator<(videoQuality other) const
    {
        int thisQuality;
        int otherQuality;

        QRegExp expression("[0-9]+");

        if (expression.indexIn(this->quality) != -1)  {
            thisQuality = expression.cap().toInt();

            if (expression.indexIn(other.quality) != -1) {
                otherQuality = expression.cap().toInt();

                return thisQuality < otherQuality;
            }
        }

        return false;
    }
};

struct fmtQuality
{
    QString quality;
    int resolution;
    QString video;
    QString audio;
    QStringList videoSegments;
    QStringList audioSegments;

    fmtQuality(QString quality, int resolution, QString video, QString audio="")
    {
        this->quality = quality;
        this->resolution = resolution;
        this->video = video;
        if (!audio.isEmpty())
        {
            this->audio = audio;
        }
    }
};

struct jsMethod
{
    QString name;
    QString code;
};


class VideoYoutube : public QObject
{
    Q_OBJECT

    private:
        QList<videoQuality> supportedQualities;
        QList<QRegExp> urlRegExp;
        HttpHandler* handler;
        int currentQuality;
        int step;
        bool downloadIsVideo;

        QUrl currentUrl;

        QString title;


        QString parseSignature(QString s);
        QString getFmtLink(QStringList, QString fmt);
        QString getUrlFromFmtLink(QString link);
        QString getQualityFromFmtLink(QString link);
        QString quality();
        void parseJS(QString js);
        void extractJSMethod(QString name, QString js);
        void parseDashMpd(QString);
        QList<jsMethod> jsMethods;
        QString signatureMethodName;
        QString html;
        QString js;
        QString dashmpd;
        QList<QStringList> dashQualityLinks;
        QMap<QString, QString> requiredDownloads;
        QString downloading;
        QList<fmtQuality> fmtQualities;

    public:
        QList< QPair<QString, int> > getSupportedQualities();
        void analyse();
        void download();
        void setQuality(int);
        void parseVideo(QString);
        bool setUrl(QString);
        bool isReady();
        QString getVideoUrl();
        QString getAudioUrl();
        HttpHandler *getHandler();
        VideoYoutube();

        private slots:
            void handleDownloads();
        void slotAnalysingFinished();
        void networkError(QString error);
signals:
        void error(QString);
        void error(QString, VideoYoutube*);
        void analysingFinished();
        void audioDownloadFinished(QString, QString);
};

#endif
