#include "DownloadTab.hpp"
#include <QBoxLayout>

#include <QWebFrame>
#include <QNetworkReply>

DownloadWidget::DownloadWidget(MainWidget *tabManger) :
    TabWidget(*tabManger, "Downloader")
{
    init();
    btns();
    textBars();
    layout();
}
void DownloadWidget::init()
{
    videoList = new SearchList();
    preview = new PlayerWindow(this);
    currentVideo = new VideoYoutube();

    connect(videoList, SIGNAL (itemSelectionChanged()), this, SLOT (itemSelectionChanged()));
}
void DownloadWidget::btns()
{
    searchBtn = new QPushButton("Search");
    connect(searchBtn, SIGNAL (released()), this, SLOT (search()));
}
void DownloadWidget::textBars()
{
    searchBar = new QLineEdit();
}
void DownloadWidget::layout()
{
    QGridLayout *grid = new QGridLayout(this);

    grid->addWidget(searchBar, 0, 0);
    grid->addWidget(searchBtn, 0, 1);
    grid->addWidget(videoList, 1, 0, 2, 2);

    grid->addWidget(preview, 0, 2, 3, 1);
}
void DownloadWidget::search()
{
    videoList->clear();
    QString text = searchBar->text();
    videoList->searchYoutube(text);
}
void DownloadWidget::itemSelectionChanged()
{
    if (!videoList->selectedItems().size())
        return;

    QListWidgetItem *currentItem = videoList->selectedItems()[0];

    QString url = QString("https://www.youtube.com");
    url.append(videoList->urlMap[QString(currentItem->text())]);

    currentVideo->setUrl(url);
    currentVideo->analyse();
    connect(currentVideo, SIGNAL (analysingFinished()), SLOT (getVideo()));
}

void DownloadWidget::getVideo()
{
    qDebug() << "Getting urls";
    preview->openMedia(currentVideo);
}


SearchList::SearchList()
{
    networkSetup();
}
void SearchList::networkSetup()
{
    networkManger = new QNetworkAccessManager(this);
    connect(networkManger, SIGNAL(finished(QNetworkReply*)), this, SLOT(requestReceived(QNetworkReply*)));
}

void SearchList::requestReceived(QNetworkReply *reply)
{
    QString html = QString(reply->readAll());
    QWebPage *page = new QWebPage();
    QWebFrame *frame = page->mainFrame();

    frame->setHtml(html, QUrl("www.youtube.com"));


    collection = frame->findAllElements(".yt-lockup-content");
    foreach (QWebElement element, collection)
    {
	    QString elementText = element.toPlainText();
	    elementText = elementText.section('\n', 0, 0);
	    urlMap[elementText] = element.firstChild().firstChild().attribute("href");
	    this->addItem(elementText);
    }

}
void SearchList::searchYoutube(QString text)
{
    QString searchUrl = QString("https://www.youtube.com/results?search_query=") + text;

    searchUrl.replace(QString(' '), QString('+'));
    networkManger->get(QNetworkRequest(QUrl(searchUrl)));
}

