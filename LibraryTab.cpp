#include "LibraryTab.hpp"
#include <QDebug>
#include <QVBoxLayout>

LibraryTab::LibraryTab(MainWidget *tabManager) :
    TabWidget(*tabManager, "Library")
{
    init();
}
void LibraryTab::init()
{
    dataHandler = new DatabaseHandler("Database.db");
    tableView = new QStackedWidget();
    playlistView = new QListWidget();

    layout();
}
void LibraryTab::layout()
{
    QHBoxLayout *hbox = new QHBoxLayout(this);

    hbox->addWidget(new PlayListView(dataHandler, tableView));
    hbox->addWidget(tableView);
}

PlayListView::PlayListView(DatabaseHandler *dataHandler, QStackedWidget *tableView) :
    handler(dataHandler) ,
    stack(tableView)
{
    extractFromDB(tableView);

    connect(this, SIGNAL(currentRowChanged(int)), this, SLOT(changePlaylist(int)));
}

void PlayListView::extractFromDB(QStackedWidget *tableView)
{
    QList <std::shared_ptr<Playlist>> playlists = handler->getPlaylists();
    qDebug() << playlists.at(0)->getName();

    for (int i = 0; i < playlists.size(); ++i) 
    {
        this->addItem(playlists.at(i)->getName());
        QTableView *view = new QTableView();
        view->setModel(playlists.at(i).get());
        tableView->addWidget(view);
    }
}
void PlayListView::changePlaylist(int index)
{
    qDebug() << "The current index: " << index;
    stack->setCurrentIndex(index);
}
