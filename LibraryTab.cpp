#include "LibraryTab.hpp"
#include <QDebug>
#include <QGridLayout>

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
    QGridLayout *grid = new QGridLayout(this);
    PlaylistAdder *adder = new PlaylistAdder();
    PlayListView *playlistView = new PlayListView(dataHandler, tableView);

    connect(adder, SIGNAL(createPlaylist(QString)), dataHandler, SLOT(createPlaylist(QString)));
    connect(dataHandler, SIGNAL(playlistCreated()), playlistView, SLOT(extractFromDB()));

    grid->addWidget(playlistView, 0, 0);
    grid->addWidget(adder, 1, 0);
    grid->addWidget(tableView, 0, 1, 0, 2);
    grid->setColumnStretch(1, 3);
}

PlayListView::PlayListView(DatabaseHandler *dataHandler, QStackedWidget *tableView) :
    handler(dataHandler) ,
    stack(tableView)
{
    extractFromDB();

    this->viewport()->setAcceptDrops(true);
    this->setDragDropMode(QAbstractItemView::DragDrop);

    connect(this, SIGNAL(currentRowChanged(int)), this, SLOT(changePlaylist(int)));
}

void PlayListView::extractFromDB()
{
    QList <std::shared_ptr<Playlist>> playlists = handler->getPlaylists();

    for (int i = 0; i < playlists.size(); ++i) 
    {
        if (stack->indexOf(playlists.at(i)->getView()) == -1)
        {
            this->addItem(playlists.at(i)->getName());
            stack->addWidget(playlists.at(i)->getView());
        }
    }
}
void PlayListView::changePlaylist(int index)
{
    qDebug() << "The current index: " << index;
    stack->setCurrentIndex(index);
}
void PlayListView::dropEvent(QDropEvent *event)
{
    qDebug() << event->mimeData()->data("application/vnd.text.list");
    event->accept();
}
QStringList PlayListView::mimeTypes() const
{
    return handler->getPlaylists().at(0)->mimeTypes();
}
QMimeData* PlayListView::mimeData(const QModelIndexList &index) const
{
    return handler->getPlaylists().at(0)->mimeData(index);
}

PlaylistAdder::PlaylistAdder()
{
    text = new QLineEdit();
    QPushButton *btn = new QPushButton("Add");

    connect(btn, SIGNAL(clicked()), this, SLOT(btnPressed()));
    QHBoxLayout *hbox = new QHBoxLayout(this);

    hbox->addWidget(btn);
    hbox->addWidget(text);
}
void PlaylistAdder::btnPressed()
{
    QString name = text->text();
    emit createPlaylist(name);
}
