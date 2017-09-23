#include "VideoYoutube.hpp"

#include "QMutableListIterator"
#if QT_VERSION >= QT_VERSION_CHECK(5,0,0)
#include <QtWebKitWidgets/QtWebKitWidgets>
#endif

VideoYoutube::VideoYoutube()
{
    handler = new HttpHandler;
    connect(handler, SIGNAL(allDownloadsFinished()), this, SLOT(handleDownloads()));
    connect(handler, SIGNAL(error(QString)), this, SLOT(networkError(QString)));
    this->_urlRegExp << QRegExp("http[s]?://\\w*\\.youtube\\.com/watch.*v\\=.*", Qt::CaseInsensitive);
    this->_urlRegExp << QRegExp("http[s]?://\\w*\\.youtube\\.com/view_play_list\\?p\\=.*&v\\=.*", Qt::CaseInsensitive);
    this->_urlRegExp << QRegExp("http[s]?://youtu.be/.*", Qt::CaseInsensitive);
    this->_urlRegExp << QRegExp("http[s]?://w*\\.youtube\\.com/embed/.*", Qt::CaseInsensitive);
}

bool VideoYoutube::setUrl(QString url)
{
    _quality = 0;
    this->downloading = "";
    this->_supportedQualities.clear();
    url.replace("#!", "?");
    url.replace("youtube.com/embed/", "youtube.com/watch?v=");
    this->_url = QUrl(url);
    if (_url.isValid())
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool VideoYoutube::isReady()
{
    if (!this->_supportedQualities.size())
        return true;
    return false;
}

void VideoYoutube::analyse()
{
    qDebug() << _url;

    if (this->_url.isValid())
    {
        _step = 1;
        handler->addDownload(_url.toString());
        connect(this, SIGNAL(analysingFinished()), this, SLOT(slotAnalysingFinished()));
    }
    else
    {
        qDebug() << "A Fatal exception has occured";
        emit error("Url is not valid");
    }
}

void VideoYoutube::slotAnalysingFinished()
{

    qDebug() << "Discovered: " << _title;
    for (int i = 0; i > _supportedQualities.size(); i++)
    {
        qDebug() << _supportedQualities.at(i).quality << _supportedQualities.at(i).containerName << _supportedQualities.at(i).videoUrl;
    }
    qDebug() << _supportedQualities.size();
    //handler->clearDownloads();
}

QString VideoYoutube::getFmtLink(QStringList qualityLinks, QString fmt)
{
    QRegExp urlExpression;
    urlExpression = QRegExp("(http[s]?[^,]+)");

    QRegExp itagExpression;
    itagExpression = QRegExp("[,]?itag=([^,]+)");

    for (int i=0; i < qualityLinks.size(); i++)
    {
        bool urlExpressionMatch = (urlExpression.indexIn(qualityLinks.at(i)) > -1);
        bool itagExpressionMatch = (itagExpression.indexIn(qualityLinks.at(i)) > -1 );

        if (urlExpressionMatch && itagExpressionMatch && itagExpression.cap(1) == fmt)
        {
            return qualityLinks.at(i);
        }
    }
    return "";
}

//Get pair of quality label QString and resolution int
QList< QPair<QString, int> > VideoYoutube::getSupportedQualities()
{
    QList< QPair<QString, int> > result;
    for (int i = 0; i < _supportedQualities.size(); ++i)
    {
        result << qMakePair(_supportedQualities.at(i).quality, _supportedQualities.at(i).resolution);
    }
    return result;
}

QString VideoYoutube::getUrlFromFmtLink(QString link)
{
    QRegExp urlExpression;
    urlExpression = QRegExp("(http[s]?[^,]+)");

    if (urlExpression.indexIn(link) > -1)
    {
        QString url = QUrl::fromPercentEncoding(QUrl::fromPercentEncoding(urlExpression.cap(1).toUtf8()).toUtf8());

        QRegExp sigExpression;
        sigExpression = QRegExp("(?:^|[^a-zA-Z])[,]?s(ig)?=([^,]+)");

        if (sigExpression.indexIn(link) > -1)
        {
            QString signature;
            if (sigExpression.cap(1) == "ig")
            {
                signature = sigExpression.cap(2);
            }
            else
            {
                signature = parseSignature(sigExpression.cap(2));
            }

            url = url.append("&signature=").append(signature);

        }

        return url;

    }

    return "";
}

void VideoYoutube::download()
{
    _step = 3;
    handler->clearDownloads();

    //connect(handler, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(changeProgress(qint64, qint64)));

    qDebug() << "About to enter if statement";
    if (!this->_supportedQualities.at(_quality).videoUrl.isEmpty())
    {
        if (this->_supportedQualities.at(_quality).videoSegments.isEmpty())
        {
            qDebug() << "Downloading video file: " << this->_supportedQualities.at(_quality).videoUrl;
            handler->addDownload(this->_supportedQualities.at(_quality).videoUrl, this->_supportedQualities.at(_quality).chunkedDownload);
        }
        else
        {
            qDebug() << "Downloading segmented video file: " << this->_supportedQualities.at(_quality).videoUrl;
            handler->addDownload(this->_supportedQualities.at(_quality).videoUrl, this->_supportedQualities.at(_quality).videoSegments);
        }
    }
    if (!this->_supportedQualities.at(_quality).audioUrl.isEmpty())
    {
        if (this->_supportedQualities.at(_quality).audioSegments.isEmpty())
        {
            qDebug() << "Downloading audio file: " << this->_supportedQualities.at(_quality).audioUrl;
            handler->addDownload(this->_supportedQualities.at(_quality).audioUrl, this->_supportedQualities.at(_quality).chunkedDownload);
        }
        else
        {
            qDebug() << "Downloading segmented audio file: " << this->_supportedQualities.at(_quality).audioUrl;
            handler->addDownload(this->_supportedQualities.at(_quality).audioUrl, this->_supportedQualities.at(_quality).audioSegments);
        }
    }
}

void VideoYoutube::handleDownloads()
{
    switch (this->_step)
    {
        case 1:
            {
                handler->downloads.at(0)->tempFile->close();
                handler->downloads.at(0)->tempFile->open();
                QByteArray data = handler->downloads.at(0)->tempFile->readAll();
                handler->downloads.at(0)->tempFile->close();
                QString html = QString::fromUtf8(data, data.size());
                handler->clearDownloads();
                parseVideo(html);
                break;
            }
    }
}

QString VideoYoutube::getQualityFromFmtLink(QString link)
{
    QRegExp qualityExpression;
    qualityExpression = QRegExp("quality_label=([^,]+)");

    if (qualityExpression.indexIn(link) > -1)
    {
        QString quality = qualityExpression.cap(1);
        if (quality == "1080p")
        {
            return tr("HD (1080p)");
        }
        else if (quality == "1440p")
        {
            return tr("HD (1440p)");
        }
        else if (quality == "2160p")
        {
            return tr("4K (2160p)");
        }
        else if (quality == "2880p")
        {
            return tr("5K (2880p)");
        }
        else if (quality == "4320p")
        {
            return tr("8K (4320p)");
        }

        return qualityExpression.cap(1);
    }

    return "";
}

void VideoYoutube::extractJSMethod(QString name, QString js) {
    for (int i = 0; i < this->jsMethods.length(); i++) {
        if (this->jsMethods.at(i).name == name) {
            return;
        }
    }

    QString escapedName = name;
    escapedName.replace("$", "\\$");
    QRegExp expression("((?:function\\s*" + escapedName + "|(var\\s*|,\\s*|\\n)" + escapedName + "\\s*=(?:\\s*function)?)\\s*(\\([\\w,\\s]*\\))?\\s*)(\\{.*\\})");
    expression.setCaseSensitivity(Qt::CaseSensitive);
    if (expression.indexIn((js)) != -1) {
        jsMethod method;
        method.name = name;
        QString descriptor = expression.cap(1);
        if (!expression.cap(2).isEmpty()) {
            descriptor = descriptor.right(descriptor.length() - expression.cap(2).length());
        }
        QString code = expression.cap(4);
        QString parameters = expression.cap(3).replace(QRegExp("[\\(\\)\\s]"), "");

        for (qint64 i = 1; i < code.length(); i++) {
            QString partial = code.left(i);
            if (partial.count("{") == partial.count("}")) {
                method.code = descriptor +  partial;
                break;
            }
        }
        if (!method.code.isEmpty()) {
            this->jsMethods.append(method);

            expression = QRegExp("([\\w\\$]+)(?:[\\w\\.\\$])*\\s*(\\([\\w\\s,\"\\$]*)\\)");
            int pos = expression.indexIn(method.code);
            QStringList expressions;
            expressions << "function" << "return" << "if" << "elseif";
            expressions.append(parameters.split(","));

            while (pos != -1) {
                if (expressions.indexOf(expression.cap(1)) == -1) {
                    this->extractJSMethod(expression.cap(1), js);
                }
                pos = expression.indexIn(method.code, pos + expression.cap(0).length());
            }
        }
    }
}

void VideoYoutube::parseJS(QString js)
{
    QString methodName;

    QRegExp expression("signature=|set\\(\"signature\",([$\\w]+)\\(");
    expression.setMinimal(true);
    if (expression.indexIn(js) != -1)
    {
        methodName = expression.cap(1);
        this->signatureMethodName = methodName;
        extractJSMethod(methodName, js);
    }
}

void VideoYoutube::parseDashMpd(QString xml)
{
    QDomDocument mpd;
    mpd.setContent(xml);
    QDomNodeList adaptionSets = mpd.elementsByTagName("AdaptationSet");

    for (int i = 0; i < adaptionSets.length(); i++) {
        QDomElement set = adaptionSets.at(i).toElement();
        if (set.attribute(("imeType")) == "video/mp4" || set.attribute(("mimeType")) == "audio/mp4") {
            QDomNodeList representations = set.elementsByTagName(("Representation"));
            for (int j = 0; j < representations.length(); j++) {
                QDomElement representation = representations.at(j).toElement();

                QString baseUrl;
                QStringList segments;
                if (representation.elementsByTagName("BaseURL").length() == 1) {
                    baseUrl = representation.elementsByTagName("BaseURL").at(0).toElement().text();
                    QDomNode initializationNode = representation.elementsByTagName("Initialization").at(0);
                    QDomNodeList segmentNodes = representation.elementsByTagName("SegmentURL");
                    if (initializationNode.isElement() && !segmentNodes.isEmpty())  {
                        segments << baseUrl + initializationNode.toElement().attribute("sourceURL");
                        for (int k = 0; k < segmentNodes.length(); k++) {
                            segments << baseUrl + segmentNodes.at(k).toElement().attribute("media");
                        }
                    }
                }
                if (!segments.empty()) {
                    this->dashQualityLinks << segments;
                }
            }
        }
    }
    adaptionSets.at(8).toDocument().elementsByTagName("Representation");
}

void VideoYoutube::parseVideo(QString html)
{
    QRegExp expression;

    //Obtain basic info from web page
    if (this->downloading.isEmpty() || this->downloading == "html")
    {
        this->html = html;
        qDebug() << "Inside parse video";

        //Is the access to the video restricted to authenticated users?
        /*
           if (html.contains("age-gate-content"))
           {
           expression = QRegExp("<div id=\"watch7-player-age-gate-content\">.*<button.*href=\"([^\"]+)\"");
           expression.setMinimal(true);
           if (expression.indexIn(html) != -1)
           {
           passwordDialog = new QDialog;

           if (passwordDialog->exec() == QDialog::Accepted)
           {
           handler->addDownload(this->_url.toString());
           }
           else
           {
           emit error("This video requires you to be signed in.", this);
           emit analysingFinished();
           }

           passwordDialog->deleteLater();
           return;
           }
           }*/

        //Does this video support MPEG-DASH?
        expression = QRegExp("\"dashmpd\": ?\"([^\"]*)");
        expression.setMinimal(false);
        bool hasMPDSignature = false;
        if (this->dashmpd.isEmpty() && expression.indexIn(html) != -1)
        {
            QString url = expression.cap(1).replace("\\", "");
            this->requiredDownloads["dashmpd"] = url;
            hasMPDSignature = url.split("/").contains("s");
        }

        //Is signature parsing required?
        expression = QRegExp("\"url_encoded_fmt_stream_map\": ?\"[^\"]*([^a-z])(s=)");
        expression.setMinimal(true);
        if (this->js.isEmpty() && (hasMPDSignature || expression.indexIn(html) != -1))
        {
            this->html = html;
            QString html5PlayerUrl;

            expression = QRegExp("html5player.+\\.js");
            expression.setMinimal(true);
            if (expression.indexIn(html) !=-1)
            {
                html5PlayerUrl = "http://s.ytimg.com/yts/jsbin/" + expression.cap(0).replace("\\/", "/");
            }
            if (html5PlayerUrl.isEmpty())
            {
                expression = QRegExp("//[^\"]*html5player[^\"]*\\.js");
                expression.setMinimal(true);
                if (expression.indexIn(html) !=-1)
                {
                    html5PlayerUrl = "https:" + expression.cap(0);
                }
            }
            if (html5PlayerUrl.isEmpty())
            {
                expression = QRegExp("(//?)[^\"]*player[^\"]*\\/base\\.js");
                expression.setMinimal(true);
                if (expression.indexIn(html) !=-1)
                {
                    if (expression.cap(1) == "//")
                    {
                        html5PlayerUrl = "https:" + expression.cap(0);
                    } else {
                        html5PlayerUrl = "https://www.youtube.com" + expression.cap(0);
                    }
                }
            }

            if (!html5PlayerUrl.isEmpty())
            {
                qDebug() << "Using player URL: " << html5PlayerUrl;
                this->requiredDownloads["js"] = html5PlayerUrl;
            }
            else
            {
                emit error("Could not retrieve player URL", this);
            }
        }
    }
    //Parse player JS
    else if (this->downloading == "js")
    {
        parseJS(html);
        this->js = "";

        for (int i = 0; i < this->jsMethods.length(); i++) {
            this->js.append(jsMethods.at(i).code).append(";");
        }
    }
    //Parse MPEG-DASH MPD
    else if (this->downloading == "dashmpd")
    {
        parseDashMpd(html);
        this->dashmpd = html;
    }

    //Check if additional urls need to be downloaded
    if (!this->requiredDownloads.empty()) {
        QString key;
        QString url;
        //Always download player first
        if (requiredDownloads.contains("js")) {
            key = "js";
            url = requiredDownloads["js"];
        }
        else {
            key = this->requiredDownloads.begin().key();
            url = this->requiredDownloads.begin().value();
        }

        //Signature parsing for MPEG-DASH MPD
        if (key == "dashmpd") {
            QStringList urlFragments = url.split("/");
            int signaturePosition = urlFragments.indexOf("s");
            if (signaturePosition > -1) {
                urlFragments.replace(signaturePosition, "signature");
                urlFragments.replace(signaturePosition + 1, this->parseSignature(urlFragments.at(signaturePosition + 1)));
                url = urlFragments.join("/");
            }
        }

        this->downloading = key;
        this->requiredDownloads.remove(key);
        handler->addDownload(url);
        return;
    }

    //Continue parsing the html
    if (!this->html.isEmpty())
    {
        html = this->html;
    }

    expression = QRegExp("<meta name=\"title\" content=\"(.*)\"");
    expression.setMinimal(true);
    if (expression.indexIn(html) !=-1)
    {
        _title = QString(expression.cap(1)).replace("&amp;quot;", "\"").replace("&amp;amp;", "&").replace("&#39;", "'").replace("&quot;", "\"").replace("&amp;", "&");
        QStringList qualityLinks;

        expression = QRegExp("\"adaptive_fmts\": ?\"(.*)\"");
        expression.setMinimal(true);
        if (expression.indexIn(html)!=-1 && expression.cap(1) != "")
        {
            qualityLinks << expression.cap(1).split(",");
        }

        expression = QRegExp("\"url_encoded_fmt_stream_map\": ?\"(.*)\"");
        expression.setMinimal(true);

        if (expression.indexIn(html)!=-1 && expression.cap(1) != "")
        {
            qualityLinks << expression.cap(1).split(",");
        }

        if (!qualityLinks.isEmpty() || ! this->dashQualityLinks.isEmpty())
        {

            qualityLinks.replaceInStrings("\\u0026", ",");
            fmtQualities << fmtQuality("240p", 240, "242", "172");

            fmtQualities << fmtQuality("360p", 360, "43");
            fmtQualities << fmtQuality("360p", 360, "243", "172");
            fmtQualities << fmtQuality("360p", 360, "167", "172");

            fmtQualities << fmtQuality("480p", 480, "44");
            fmtQualities << fmtQuality("480p", 480, "244", "172");
            fmtQualities << fmtQuality("480p", 480, "168", "172");

            fmtQualities << fmtQuality("HD (720p)", 720, "45");
            fmtQualities << fmtQuality("HD (720p)", 720, "247", "172");
            fmtQualities << fmtQuality("HD (720p)", 720, "169", "172");

            fmtQualities << fmtQuality("HD (1080p)", 1080, "46");
            fmtQualities << fmtQuality("HD (1080p)", 1080, "248", "172");
            fmtQualities << fmtQuality("HD (1080p)", 1080, "170", "172");

            fmtQualities << fmtQuality("HD (1440p)", 1440, "271", "172");

            fmtQualities << fmtQuality("4K (2160p)", 2160, "313", "172");

            fmtQualities << fmtQuality("HD (720p60)", 720, "302", "172");
            fmtQualities << fmtQuality("HD (1080p60)", 1080,"303", "172");
            fmtQualities << fmtQuality("HD (1440p60)", 1440, "308", "172");
            fmtQualities << fmtQuality("4K (2160p60)", 2160, "315", "172");

            fmtQualities << fmtQuality(tr("Original"), 3000, "272", "172");

            QMutableListIterator<fmtQuality> i(fmtQualities);
            i.toBack();
            while (i.hasPrevious())
            {
                fmtQuality q = i.previous();

                //Extract links
                bool videoIsFmt = true, audioIsFmt = true;
                QString videoLink = getFmtLink(qualityLinks, q.video);
                QString audioLink = !q.audio.isEmpty() ? getFmtLink(qualityLinks, q.audio) : "";
                QStringList videoLinkSegments, audioLinkSegments;

                //If preferred audio couldn’t be found
                if (!q.audio.isEmpty() && !videoLink.isEmpty() && audioLink.isEmpty())
                {
                    if (q.audio == "141")
                    {
                        audioLink = getFmtLink(qualityLinks, "140");
                    }
                    else if (q.audio == "172")
                    {
                        audioLink = getFmtLink(qualityLinks, "171");
                    }
                }

                //Try MPEG-Dash if Fmt link wasn’t found
                if (videoLink.isEmpty() || (!q.audio.isEmpty() && audioLink.isEmpty()))
                {
                    QRegExp itagExpression = QRegExp("[/]?itag/([^/]+)");

                    for (int j = 0; j < this->dashQualityLinks.length(); j++) {
                        if (!(itagExpression.indexIn(dashQualityLinks.at(j).at(0)) > -1))
                        {
                            continue;
                        }

                        if (videoLink.isEmpty() && itagExpression.cap(1) == q.video)
                        {
                            videoLink = dashQualityLinks.at(j).at(0);
                            videoLinkSegments = QStringList(dashQualityLinks.at(j));
                            videoLinkSegments.removeFirst();
                            videoIsFmt = false;
                        }
                        else if (audioLink.isEmpty() && itagExpression.cap(1) == q.audio)
                        {
                            audioLink = dashQualityLinks.at(j).at(0);
                            audioLinkSegments = QStringList(dashQualityLinks.at(j));
                            audioLinkSegments.removeFirst();
                            audioIsFmt = false;
                        }
                    }

                    //Look for alternative lower-quality audio
                    if (!videoLink.isEmpty() && !q.audio.isEmpty() && audioLink.isEmpty()) {
                        for (int j = 0; j < this->dashQualityLinks.length(); j++) {
                            if (!(itagExpression.indexIn(dashQualityLinks.at(j).at(0)) > -1))
                            {
                                continue;
                            }

                            if (q.audio == "141" && itagExpression.cap(1) == "140")
                            {
                                audioLink = dashQualityLinks.at(j).at(0);
                                audioLinkSegments = QStringList(dashQualityLinks.at(j));
                                audioLinkSegments.removeFirst();
                                audioIsFmt = false;
                            }
                        }

                    }
                }

                //If current quality set was found
                if ((!videoLink.isEmpty()) && (audioLink.isEmpty() == q.audio.isEmpty()))
                {
                    videoQuality newQuality;
                    newQuality.resolution = q.resolution;

                    QRegExp formatExpression = QRegExp("webm|flv");
                    newQuality.containerName = ".mp4";
                    if (formatExpression.indexIn(videoLink) > -1)
                    {
                        newQuality.containerName = "." + formatExpression.cap(0);
                    }

                    //Set quality name
                    newQuality.quality = q.quality;
                    if (q.quality == tr("Original")) {
                        newQuality.quality = getQualityFromFmtLink(videoLink);
                        if (newQuality.quality.isEmpty()){
                            newQuality.quality = tr("Original");
                        }
                    }

                    if (videoIsFmt)
                    {
                        newQuality.videoUrl = getUrlFromFmtLink(videoLink);
                    }
                    else
                    {
                        newQuality.videoUrl = videoLink;
                        newQuality.videoSegments = videoLinkSegments;
                    }

                    if (!audioLink.isEmpty() && audioIsFmt)
                    {
                        newQuality.audioUrl = getUrlFromFmtLink(audioLink);
                    }
                    else if (!audioLink.isEmpty()) {
                        newQuality.audioUrl = audioLink;
                        newQuality.audioSegments = audioLinkSegments;
                    }


                    newQuality.chunkedDownload = false;

                    _supportedQualities.append(newQuality);

                    QMutableListIterator<fmtQuality> ii(fmtQualities);
                    while (ii.hasNext())
                    {
                        if (ii.next().quality == newQuality.quality)
                        {
                            ii.value().video.clear();
                            ii.value().audio.clear();
                        }
                    }
                }
            }
        }
        else if (expression.indexIn(html)!=-1 && expression.cap(1) == "")
        {
            expression = QRegExp("\"t\": \"(.*)\"");
            expression.setMinimal(true);
            QRegExp expression2 = QRegExp("\"video_id\": \"(.*)\"");
            expression2.setMinimal(true);
            if (expression.indexIn(html) !=-1 && expression2.indexIn(html) !=-1)
            {
                videoQuality newQuality;
                newQuality.quality = tr("normal");
#if QT_VERSION < QT_VERSION_CHECK(5,0,0)
                newQuality.videoUrl = QUrl::fromEncoded(QString("http://www.youtube.com/get_video?video_id=" + expression2.cap(1) + "&t=" + expression.cap(1)).toAscii()).toString(QUrl::None);
#else
                newQuality.videoUrl = QUrl::fromEncoded(QString("http://www.youtube.com/get_video?video_id=" + expression2.cap(1) + "&t=" + expression.cap(1)).toLatin1()).toString(QUrl::None);
#endif
                _supportedQualities.append(newQuality);
            }
            else
            {
                emit error("Could not retrieve video link.", this);

            }
        }
        else
        {
            emit error("Could not retrieve video link.", this);

        }
    }
    else
    {
        emit error("Could not retrieve video title.", this);
    }

    emit analysingFinished();
}

QString VideoYoutube::parseSignature(QString s)
{
    qDebug() << "received signature: " << s;

    QWebView* view = new QWebView();
    view->setHtml("<script>" + this->js + "</script>");
    s = view->page()->mainFrame()->evaluateJavaScript(this->signatureMethodName + "(\"" + s + "\")").toString();
    view->deleteLater();

    return s;
}

QString VideoYoutube::getVideoUrl()
{
    return this->_supportedQualities.at(_quality).videoUrl;
}

QString VideoYoutube::getAudioUrl()
{
    return this->_supportedQualities.at(_quality).audioUrl;
}
void VideoYoutube::networkError(QString message)
{
    emit error(message, this);
}

void VideoYoutube::setQuality(int quality)
{
    qDebug() << quality;
    this->_quality = quality;
    qDebug() << "successfully set qual";
}

QString VideoYoutube::quality()
{
    return this->_supportedQualities.at(_quality).quality;
}

