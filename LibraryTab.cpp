#include "LibraryTab.hpp"
#include <QDebug>
#include <QVBoxLayout>

LibraryTab::LibraryTab(MainWidget *tabManager) :
    TabWidget(*tabManager, "Library")
{
    init(tabManager);
}
void LibraryTab::init(MainWidget *tabManager)
{
    dataHandler = new DatabaseHandler("Database.db");
    tableView = new QStackedWidget();
    playlistView = new QListWidget();

    tabManager->setFileManger(dataHandler);

    layout();
}
void LibraryTab::layout()
{
    QHBoxLayout *hbox = new QHBoxLayout(this);

    hbox->addWidget(new PlayListView(dataHandler, tableView));
    hbox->addWidget(tableView);
    hbox->setStretchFactor(tableView, 3);
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

    for (int i = 0; i < playlists.size(); ++i) 
    {
        this->addItem(playlists.at(i)->getName());
        stack->addWidget(playlists.at(i)->getView());
    }
}
void PlayListView::changePlaylist(int index)
{
    qDebug() << "The current index: " << index;
    stack->setCurrentIndex(index);
}
