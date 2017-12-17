#include "DataHandler.hpp"

#include <QDataStream>
#include <QDir>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>

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
    allSongs = createPlaylist("AllSongs", false);

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
std::shared_ptr< Playlist >  DatabaseHandler::createPlaylist(const QString &name, bool autoAdd)
{
    QHash <QString, QList <QString> > playlistColumns;
    playlistColumns[name] = {"trackName TEXT", "artist INTEGER", "Genere INTEGER", "Duration DOUBLE"};

    createTable(&playlistColumns);

    if (autoAdd)
        playlists.append(std::shared_ptr < Playlist > (new Playlist(name, 0, db)));

    emit playlistCreated();

    return playlists.last();
}
QList <std::shared_ptr<Playlist> > DatabaseHandler::getPlaylists()
{
    return playlists;
}

Playlist::Playlist(QString name, QObject *parent, QSqlDatabase db) :
    name(name)
{
    this->setTable(name);
    this->select();
    this->setHeaderData(0, Qt::Horizontal, tr("ID"));

    view = new QTableView;

    view->setModel(this);
    view->hideColumn(0);
    view->setEditTriggers(QAbstractItemView::NoEditTriggers); 
    view->setSelectionBehavior(QAbstractItemView::SelectRows);
    view->setSelectionMode(QAbstractItemView::SingleSelection);
    view->resizeRowsToContents();
}
QTableView* Playlist::getView()
{
    return view;
}
QString Playlist::getName() const
{
    return name;
}
/*
   QStringList Playlist::mimeTypes() const
   {
   QStringList types;
   types << "application/vnd.text.list";
   return types;
   }

/*
QMimeData Playlist::mimeData(const QModelIndexList &indexes) const
{
QMimeData *mimeData = new QMimeData();
QByteArray encodedData;

QDataStream stream(&encodedData, QIODevice::WriteOnly);

foreach (QModelIndex index, indexes)
{
if (index.isValid())
{
QString text = data(index, Qt::DisplayRole).toString();
stream << text;
}
}

mimeData->setData("application/vnd.text.list", encodedData);
return mimeData;
}*/

/*
   bool Playlist::dropMimeData(const QMimeData *data, Qt::DropAction action,
   int row, int column, const QModelIndex &parent)
   {
   if (action == Qt::IgnoreAction)
   return true;
   else if (!data->hasFormat("application/vnd.text.list"))
   return false;
   else if (column > 0)
   return false;

   int beginRow;

   if (row != -1)
   beginRow = row;
   else if (parent.isValid())
   beginRow = parent.row();
   else
   beginRow = rowCount(QModelIndex());

   QByteArray encodedData = data->data("application/vnd.text.list");
   QDataStream stream(&encodedData, QIODevice::ReadOnly);
   QStringList newItems;
   int rows = 0;

   while (!stream.atEnd())
   {
   QString text;
   stream >> text;
   newItems << text;
   ++rows;
   }

   insertRows(beginRow, rows, QModelIndex());

   foreach (QString text, newItems)
   {
   QModelIndex idx = index(beginRow, 0, QModelIndex());
   setData(idx, text);
   ++beginRow;
   }
   return true;
   }
   */



