#ifndef DOWNLOADTAB_H
#define DOWNLOADTAB_H

#include "window.hpp"
#include <map>

#include <QtWebKitWidgets/QWebView>
#include <QListWidget>
#include <QWebElementCollection>


class SearchList : public QListWidget
{
    Q_OBJECT;

public:
    SearchList();
    void searchYoutube(const QString text, QWebView *preview);
    std::map<QString, QString> urlMap;
private slots:
    void requestReceived(QNetworkReply *reply);
private:
    QNetworkAccessManager *networkManger;
    QWebElementCollection collection;

    void networkSetup();
};

class DownloadWidget : public TabWidget
{
    Q_OBJECT;

public:
    DownloadWidget(MainWidget *tabManger);

private slots:
    void search();
    void itemSelectionChanged();

private:
    QPushButton *searchBtn;
    QLineEdit *searchBar;
    QWebView *preview;
    QNetworkAccessManager *manager;
    QWebElementCollection collection;

    SearchList *videoList;

    void init();
    void btns();
    void textBars();
    void layout();
    void setPreview();
};

#endif
