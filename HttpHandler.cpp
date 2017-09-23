#include "HttpHandler.hpp"

HttpHandler::HttpHandler()
{
    networkAccessManager = new QNetworkAccessManager;
    connect (networkAccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(handleNetworkReply(QNetworkReply*)));
    connect (this, SIGNAL(downloadFinished(download*)), this, SLOT(handleFinishedDownload(download*)));
    connect (networkAccessManager, SIGNAL(sslErrors(QNetworkReply*,QList<QSslError>)), this, SLOT(handleSSLError(QNetworkReply*,QList<QSslError>)));
}

//Create a new QNetworkRequest
QNetworkRequest HttpHandler::createRequest(QUrl url)
{
    QNetworkRequest request;
    request.setUrl(url);
    request.setRawHeader("Accept", "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8");

    return request;
}

//Start a new download with the download handler
QNetworkReply* HttpHandler::addDownload(QString url, bool chunked, QByteArray postData, QStringList segments)
{
    download* newDownload = new download;
    QNetworkRequest request = createRequest(QUrl::fromEncoded(url.toLatin1()));
    newDownload->tempFile = new QTemporaryFile(QDir::tempPath() + "/clipgrab-download-XXXXXX");
    newDownload->size = 0;
    newDownload->redirectLevel = 0;
    newDownload->chunked = chunked;
    if (newDownload->chunked)
    {
        request.setRawHeader("Range", QString("bytes=0-1397760").toLatin1());
    }
    if (!segments.isEmpty())
    {
        newDownload->segments = QStringList(segments);
        newDownload->segmentPosition = -1;
    }

    if (postData.isEmpty())
    {
        newDownload->reply = this->networkAccessManager->get(request);
    }
    else
    {
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
        newDownload->reply = this->networkAccessManager->post(request, postData);
    }
    connect(newDownload->reply, SIGNAL(readyRead()), this, SLOT(dataHandler()));

    downloads.append(newDownload);
    return newDownload->reply;
}

//Overloaded method for segmented downloads
QNetworkReply* HttpHandler::addDownload(QString initUrl, QStringList segments)
{
    return this->addDownload(initUrl, false, NULL, segments);
}

//Continue the download after a redirection or successful range request
void HttpHandler::continueDownload(download* dl)
{
    QNetworkRequest request;
    dl->reply->close();

    //In case of redirection
    if (!dl->reply->attribute(QNetworkRequest::RedirectionTargetAttribute).toString().isEmpty() && dl->redirectLevel < 16)
    {
        request = createRequest(dl->reply->attribute(QNetworkRequest::RedirectionTargetAttribute).toUrl());
        dl->redirectLevel ++;
    }

    //In case of 206 status (successful range request)
    //or continuing aborted chunked request
    else if (dl->currentStatus() == 206 ||  ((dl->previousStatus() == 206) && (dl->currentStatus() == 0 || dl->currentStatus() == 5)))
    {
        request = createRequest(dl->reply->url());
        dl->progress = dl->getProgress();
        dl->currentProgress = 0;
        dl->redirectLevel = 0;

        qint64 downloadChunk = 1397760;//925696;
        qint64 targetBytes = dl->progress+downloadChunk;


        if (targetBytes >= dl->size-downloadChunk)
        {
            targetBytes = dl->size;
        }

        //If the download is complete already
        if (targetBytes <= dl->progress)
        {
            emit downloadFinished(dl);
            return;
        }
        //If more parts need to be downloaded
        else
        {
#if QT_VERSION < QT_VERSION_CHECK(5,0,0)
            request.setRawHeader("Range", QString("bytes=" + QString::number(dl->getProgress()) + "-" + QString::number(targetBytes)).toAscii());
#else
            request.setRawHeader("Range", QString("bytes=" + QString::number(dl->getProgress()) + "-" + QString::number(targetBytes)).toLatin1());
#endif
        }
    }

    //In case of continuing an aborted non-chunked request
    else if (dl->currentStatus() == 200 || ((dl->previousStatus() == 200) && (dl->currentStatus() == 0 || dl->currentStatus() == 5)))
    {
        request = createRequest(dl->reply->url());
        dl->progress = dl->getProgress();
        dl->currentProgress = 0;
        dl->redirectLevel = 0;
        qint64 targetBytes = dl->size;
#if QT_VERSION < QT_VERSION_CHECK(5,0,0)
        request.setRawHeader("Range", QString("bytes=" + QString::number(dl->getProgress()) + "-" + QString::number(targetBytes)).toAscii());
#else
        request.setRawHeader("Range", QString("bytes=" + QString::number(dl->getProgress()) + "-" + QString::number(targetBytes)).toLatin1());
#endif
    }


    if (!request.url().isEmpty())
    {
        //Continuing after pausing
        dl->_previousStatus = dl->currentStatus();
        dl->reply = networkAccessManager->get(request);
        connect(dl->reply, SIGNAL(readyRead()), this, SLOT(dataHandler()));
    }
}

void HttpHandler::pauseAllDownloads()
{
    for (int i=0; i < this->downloads.size(); i++)
    {
        if (downloads.at(i)->reply)
        {
            downloads.at(i)->reply->disconnect();
            downloads.at(i)->reply->abort();
        }
    }
}

void HttpHandler::continueAllDownloads()
{
    for (int i=0; i < this->downloads.size(); i++)
    {
        continueDownload(downloads.at(i));
    }
}

download* HttpHandler::getDownload(QNetworkReply* reply)
{
    if (reply)
    {
        for (int i=0; i < this->downloads.size(); i++)
        {
            if (downloads.at(i)->reply == reply)
            {
                return downloads.at(i);
            }
        }
    }
    return NULL;
}


void HttpHandler::handleSSLError(QNetworkReply *reply, const QList<QSslError> &errors)
{
#ifdef MAC_LEGACY
    return;
#endif

    QSettings settings;
#ifdef Q_WS_MAC
    bool ignoreSSLErrors = settings.value("IgnoreSSLErrors", true).toBool();
#else
    bool ignoreSSLErrors = settings.value("IgnoreSSLErrors", false).toBool();
#endif

    if (ignoreSSLErrors)
    {
        reply->ignoreSslErrors();
    }

    foreach (QSslError SSLError, errors)
    {
        if (ignoreSSLErrors)
        {
            qDebug() << "Ignoring SSL error: " << SSLError;
        }
        else
        {
            emit error("An SSL error occurred: " + SSLError.errorString());
        }
    }
}

void HttpHandler::handleNetworkReply(QNetworkReply* reply)
{
    download* dl = getDownload(reply);

    if ((!dl->reply->attribute(QNetworkRequest::RedirectionTargetAttribute).toUrl().isEmpty() && dl->redirectLevel < 16) ||  (dl->currentStatus() == 206))
    {
        continueDownload(dl);
        return;
    }
    else if (!dl->segments.isEmpty() && dl->segmentPosition +1 < dl->segments.length())
    {
        reply->close();

        dl->redirectLevel = 0;
        dl->segmentPosition++;
#if QT_VERSION < QT_VERSION_CHECK(5,0,0)
        QNetworkRequest request = createRequest(QUrl::fromEncoded(dl->segments.at(dl->segmentPosition).toAscii()));
#else
        QNetworkRequest request = createRequest(QUrl::fromEncoded(dl->segments.at(dl->segmentPosition).toLatin1()));
#endif
        dl->progress = dl->getProgress();
        dl->currentProgress = 0;
        dl->reply = this->networkAccessManager->get(request);
        connect(dl->reply, SIGNAL(readyRead()), this, SLOT(dataHandler()));

        return;
    }
    else if (reply->error())
    {
        qDebug() << "Error!" << reply->errorString();

        if (dl->currentStatus() <= 206 && dl->currentStatus() >= 200)
        {
            qDebug() << "Continuing from error";
            continueDownload(dl);
            return;
        }
        else if ((dl->previousStatus() == 200 || dl->previousStatus() == 206) && dl->currentStatus() == 403)
        {
            qDebug() << "Unexpected 403 - maybe download link timed out?";
            //todo: Make video re-analyze and restart download
        }
        else
        {
            emit error(reply->errorString() + " Error code: " + QString::number(dl->currentStatus()));
            reply->close();
            handleFinishedDownload(dl);
        }
    }
    else {
        emit downloadFinished(dl);
    }
}

void HttpHandler::cancelAllDownloads()
{

    for (int i=0; i < this->downloads.size(); i++)
    {
        if (downloads.at(i)->reply)
        {
            downloads.at(i)->reply->disconnect();
            downloads.at(i)->reply->abort();
        }
        if (downloads.at(i)->tempFile)
        {
            downloads.at(i)->tempFile->disconnect();
            downloads.at(i)->tempFile->close();
            downloads.at(i)->tempFile->deleteLater();
        }
    }
    downloads.clear();
}

void HttpHandler::dataHandler()
{
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(QObject::sender());
    download* dl = getDownload(reply);

    if (dl)
    {

        //Update current progress on chunk/download
        dl->currentProgress += reply->bytesAvailable();

        //Write data to temp files
        if (dl->tempFile && (dl->tempFile->isOpen() || dl->tempFile->open()))
        {
            dl->tempFile->write(reply->readAll());
        }

        //Update progress and file size

        if (reply->hasRawHeader("Content-Range"))
        {
            dl->size = QString(reply->rawHeader("Content-Range")).split("/").last().toLongLong();
        }
        else if (!dl->segments.isEmpty())
        {
            qlonglong currentSegmentSize = reply->header(QNetworkRequest::ContentLengthHeader).toLongLong();
            qlonglong previousSegmentsSize = dl->tempFile->size();
            dl->size =  (previousSegmentsSize - dl->currentProgress + currentSegmentSize)/(dl->segmentPosition+2)*dl->segments.length();
        }
        else {
            dl->size = reply->header(QNetworkRequest::ContentLengthHeader).toLongLong();
        }

        qint64 totalProgress = 0;
        qint64 totalBytes  = 0;
        for (int i=0; i < this->downloads.size(); i++)
        {
            totalProgress += this->downloads.at(i)->getProgress();
            totalBytes += this->downloads.at(i)->size;
        }
        emit downloadProgress(totalProgress, totalBytes);
    }
}

void HttpHandler::handleFinishedDownload(download* dl)
{
    dl->finished = true;

    bool allFinished = true;
    for (int i=0; i < this->downloads.size(); i++)
    {
        if (!this->downloads.at(i)->finished)
        {
            allFinished = false;
        }
    }
    if (allFinished)
    {
        emit allDownloadsFinished();
    }
}

void HttpHandler::clearDownloads()
{
    qDebug() << this->downloads;
    for (int i=0; i < this->downloads.size(); i++)
    {
        qDebug() << "Entering for loop";
        if (downloads.at(i)->reply)
        {
            downloads.at(i)->reply->close();
            downloads.at(i)->reply->deleteLater();
        }
        if (downloads.at(i)->tempFile)
        {
            downloads.at(i)->tempFile->deleteLater();
        }
    }
    downloads.clear();
}

/*
//Serializing and de-serializing cookies
QString HttpHandler::serializeCookies(QList<QNetworkCookie> cookies)
{
qDebug() << "serializing Cookies" << cookies.length() << cookies;
QStringList serializedCookies;
for (int i = 0; i < cookies.length(); i++)
{
serializedCookies << QUrl::toPercentEncoding(cookies.at(i).toRawForm());
}

return serializedCookies.join(";");
}


QList<QNetworkCookie> HttpHandler::deserializeCookies(QString serializedCookiesString)
{
QStringList serializedCookies = serializedCookiesString.split(";");
QList<QNetworkCookie> cookies;
for (int i = 0; i < serializedCookies.length(); i++)
{
#if QT_VERSION < QT_VERSION_CHECK(5,0,0)
QString cookieString = QUrl::fromPercentEncoding(serializedCookies.at(i).toAscii());
#else
QString cookieString = QUrl::fromPercentEncoding(serializedCookies.at(i).toLatin1());
#endif
#if QT_VERSION < QT_VERSION_CHECK(5,0,0)
QList<QNetworkCookie> parsedCookies = QNetworkCookie::parseCookies(cookieString.toAscii());
#else
QList<QNetworkCookie> parsedCookies = QNetworkCookie::parseCookies(cookieString.toLatin1());
#endif
for (int j = 0; j < parsedCookies.length(); j++)
{
cookies.append(parsedCookies.at(j));
}
}
return cookies;
}*/
