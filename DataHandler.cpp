#include "DataHandler.hpp"

#include <QDrag>
#include <QDataStream>
#include <QDir>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>
#include <QStringListModel>

DatabaseHandler::DatabaseHandler(QString name)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    const QString path( QDir::currentPath() + "/Downloads");
    QDir().mkdir(path);
    db.setDatabaseName(path + "/database.db");
    init();
}
void DatabaseHandler::init()
{
    QList <QString> defaultTables = {"artists", "albums"};

    for (int i = 0; i < defaultTables.size(); i++)
    {
        QHash < QString, QList <QString> > table;
        table[QString(defaultTables[i])] = {defaultTables[i] + " TEXT"};
        createTable(&table);
    }

    db.open();
    QSqlQuery query = db.exec("SELECT name FROM sqlite_master WHERE type = 'table';");

    while (query.next()) {
        QString playlist = query.value(0).toString();
        qDebug() << "The playslist grabeed: " << playlist;

        playlist.replace('"', "");
        if (!defaultTables.contains(playlist) && playlist != "sqlite_sequence")
            playlists.append(std::shared_ptr < Playlist > (new Playlist(playlist, 0, db)));
    }
    db.close();
    allSongs = createPlaylist("AllSongs", true);

}
void DatabaseHandler::insertSong(QString filename)
{
    QString query = "INSERT INTO AllSongs (trackName) VALUES ('" + filename + "')";
    db.open();
    qDebug() << query;
    db.exec(query);
    db.commit();
    allSongs->select();
    db.close();
}
void DatabaseHandler::addToPlaylist(QString tableName, QString trackid)
{
    db.open();
    db.exec("INSERT INTO " + tableName + " (TrackId) VALUES (" + trackid + ")");
    db.commit();
    db.close();
}

void DatabaseHandler::createTable(QHash <QString, QList <QString> > *table, bool id)
{
    QHashIterator< QString, QList <QString> > i(*table);

    while (i.hasNext())
    {

        i.next();
        QString name = i.key();
        QList <QString> columnsList = i.value();
        QString columns = "";

        qDebug() << "Creating table: " + name;

        int columnSize = columnsList.size();

        for (int x = 0; x < columnSize; x++)
        {

            if (x == 0)
            {
                columns += "(";
                if (id)
                {
                    columns += "id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE ";
                }
            }

            columns +=  ", " + columnsList[x];

            if (x == columnSize - 1)
            {
                columns += ")";
                continue;
            }
        }
        qDebug() << "CREATE TABLE IF NOT EXISTS " + name + columns;

        db.open();
        db.exec("CREATE TABLE IF NOT EXISTS " + name + columns);
        db.commit();
        db.close();
    }
}
std::shared_ptr< Playlist >  DatabaseHandler::createPlaylist(const QString &name, bool allSongs)
{
    QHash <QString, QList <QString> > playlistColumns;

    playlistColumns[name] = {"TrackId INTEGER"};

    if(allSongs)
        playlistColumns[name] = {"trackName TEXT", "artist INTEGER", "Genere INTEGER", "Duration DOUBLE"};

    createTable(&playlistColumns);

    if (allSongs)
        playlists.append(std::shared_ptr < Playlist > (new Playlist(name, 0, db)));

    emit playlistCreated();

    return playlists.last();
}
QList <std::shared_ptr<Playlist> > DatabaseHandler::getPlaylists()
{
    return playlists;
}

Playlist::Playlist(QString name, QObject *parent, QSqlDatabase database) :
    name(name),
    db(database)
{
    this->setJoinMode(QSqlRelationalTableModel::LeftJoin);

    if (name != "AllSongs")
    {
        this->update();
    }
    else
    {
        this->setTable(name);
        this->select();
    }

    view = new PlaylistView();
    connect(view, SIGNAL (deleteRow(int)), this, SLOT(removeRow(int)));
    connect(view, SIGNAL (reorderSong(int, int)), this, SLOT(reorderRow(int, int)));

    view->setModel(this);
    view->hideColumn(0);
    view->setEditTriggers(QAbstractItemView::NoEditTriggers); 
    view->setSelectionBehavior(QAbstractItemView::SelectRows);
    view->setSelectionMode(QAbstractItemView::SingleSelection);
    view->resizeRowsToContents();
}
void Playlist::removeRow(int id)
{
    QString query("DELETE FROM " + name + " WHERE id  IN (SELECT id FROM " + name + " ORDER BY id LIMIT 1 OFFSET " + QByteArray::number(id) + ")");
    qDebug() << query;
    db.open();
    db.exec(query);
    db.close();
    update();
}
void Playlist::reorderRow(int startId, int destinationId)
{
    startId--;
    db.open();

    QSqlQuery destquery = db.exec("SELECT id FROM " + name + " ORDER BY id LIMIT 1 OFFSET " + QByteArray::number(destinationId));
    destquery.next();
    int destId = destquery.value(0).toInt();

    QSqlQuery startquery = db.exec("SELECT id FROM " + name + " ORDER BY id LIMIT 1 OFFSET " + QByteArray::number(startId));
    startquery.next();
    int originalId = startquery.value(0).toInt();

    db.exec("UPDATE " + name + " SET id = 0 " + "WHERE id = " + QByteArray::number(destId));
    db.exec("UPDATE " + name + " SET id = " + QByteArray::number(destId)  + " WHERE id = " + QByteArray::number(originalId));
    db.exec("UPDATE " + name + " SET id = " + QByteArray::number(originalId) +  " WHERE id = 0");
    db.close();
    update();

}

Qt::DropActions Playlist::supportedDropActions() const
{
    return Qt::MoveAction;
}
PlaylistView* Playlist::getView()
{
    return view;
}
QString Playlist::getName() const
{
    return name;
}
Qt::ItemFlags Playlist::flags(const QModelIndex &index)
{
    QStringListModel *def = new QStringListModel();
    Qt::ItemFlags defaultFlags = def->flags(index);

    if (index.isValid())
    {
        return Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled;
    }
    else
        return Qt::ItemIsDropEnabled;
}
QStringList Playlist::mimeTypes() const
{
    QStringList types;
    types << "application/vnd.text.list";
    return types;
}

QMimeData *Playlist::mimeData(const QModelIndexList &indexes) const
{
    QMimeData *mimeData = new QMimeData();
    QByteArray encodedData;

    QDataStream stream(&encodedData, QIODevice::WriteOnly);

    foreach (const QModelIndex &index, indexes) {
        if (index.isValid()) {
            QString text = data(index, Qt::DisplayRole).toString();
            stream << text;
        }
    }

    mimeData->setData("application/vnd.text.list", encodedData);
    return mimeData;
}

void Playlist::update()
{
    db.open();
    QSqlQuery query = db.exec(
            "SELECT AllSongs.id, trackName, artist, Genere, Duration FROM AllSongs JOIN " + name + " ON AllSongs.id = " + name + ".TrackId;"
            );
    this->setQuery(query);
    this->select();
    db.close();
}

PlaylistView::PlaylistView()
{
    this->setSelectionMode(QAbstractItemView::SingleSelection);
    this->setDragDropMode(QAbstractItemView::DragDrop);
    this->setDragEnabled(true);
    this->setAcceptDrops(true);
    this->setDropIndicatorShown(true);
}

void PlaylistView::dragEnterEvent(QDragEnterEvent *e)
{
    e->accept();
}
void PlaylistView::dragMoveEvent(QDragMoveEvent *e)
{
    e->accept();
}
void PlaylistView::dropEvent(QDropEvent *event)
{
    qDebug() << event->mimeData()->data("application/vnd.text.list");
    event->setDropAction(Qt::MoveAction);

    //TODO:Allow reordering of the songs in the database
    int rowId = getRowId(event->pos().y());
    emit reorderSong(rowId, this->selectionModel()->selection().indexes().at(0).row());

    event->accept();
}
void PlaylistView::mousePressEvent(QMouseEvent *event)
{
    mouseStartPos = event->pos();
    QTableView::mousePressEvent(event);
    isDragging = false;

    qDebug() << "List gen";
    yPos.clear();
    int i = 0;
    while (this->rowViewportPosition(i) != -1)
    {
        yPos.append(this->rowViewportPosition(i));
        i++;
    }
}
void PlaylistView::keyPressEvent(QKeyEvent *key)
{
    qDebug() << "method is called!";
    if (key->key() == Qt::Key_Delete)
    {
        qDebug() << "delete triggered";
        int rowId = this->selectionModel()->selection().indexes().at(0).row();
        qDebug() << "rowid is " << rowId;

        emit deleteRow(rowId);
    }
}
void PlaylistView::mouseMoveEvent(QMouseEvent *event)
{
    if (event->pos() != mouseStartPos && event->buttons() ==  Qt::LeftButton && !isDragging)
    {
        //Init draggin
        isDragging = true;

        QDrag *drag = new QDrag(this);

        QMimeData *data = new QMimeData;
        data->setData("application/vnd.text.list", QByteArray::number(getRowId(event->pos().y())));
        drag->setMimeData(data);

        Qt::DropAction dropAction = drag->exec(Qt::MoveAction, Qt::MoveAction);

    }
}
int PlaylistView::getRowId(int pos)
{
    int i = 0;
    while (pos > yPos.at(i))
    {
        i++;
        if (i == yPos.size())
            break;
    }
    qDebug() << "Row id is: " << i;
    return i;
}
