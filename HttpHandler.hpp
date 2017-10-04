#ifndef HTTPHANDLER_H
#define HTTPHANDLER_H

#include <QtNetwork>
#include <QTemporaryFile>
#include <QDebug>

struct download
{

    download()
    {
        title = "";
        size = 0;
        currentProgress = 0;
        progress = 0;
        chunked = false;
        finished = false;
        async = false;
        redirectLevel = 0;
        tempFile = NULL;
        reply = NULL;
        _previousStatus = -2;
    }

    QNetworkReply* reply;

    QTemporaryFile* tempFile;

    QString title;

    qint64 size;
    qint64 progress;

    QStringList segments;
    int segmentPosition;

    qint64 currentProgress;
    bool chunked;

    int redirectLevel;
    bool finished;
    bool async;

    qint64 getProgress()
    {
        return currentProgress + progress;
    }

    int currentStatus()
    {
        if (reply)
        {
            return reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        }
        return -2;
    }

    int _previousStatus;
    int previousStatus()
    {
        return _previousStatus;
    }
};

class HttpHandler : public QObject
{
    Q_OBJECT

    public:
        HttpHandler();


        QNetworkReply* addDownload(QString, bool chunked=false, QByteArray postData=NULL, QStringList segments=QStringList(), QString title="");
        QNetworkReply* addDownload(QString initUrl, QStringList segments);
        void clearDownloads();
        QList<download*> downloads;

        QNetworkAccessManager* networkAccessManager;

        QNetworkRequest createRequest(QUrl);
        download* getDownload(QNetworkReply*);

        //QString serializeCookies(QList<QNetworkCookie>);
        //QList<QNetworkCookie> deserializeCookies(QString);

        protected slots:
            void dataHandler();
        void handleFinishedDownload(download* );
        void handleNetworkReply(QNetworkReply*);
        void handleSSLError(QNetworkReply* reply, const QList<QSslError> & errors);


signals:
        void error(QString);
        void downloadProgress(qint64, qint64);

        void downloadFinished(download*);
        void allDownloadsFinished();
        void progressChanged(qint64 bytesReceived, qint64 bytesTotal);
};

#endif // HttpHandler_H
