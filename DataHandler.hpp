#ifndef DATAHANDLER_HPP
#define DATAHANDLER_HPP

#include <QSqlRelationalTableModel>
#include <QSqlDatabase>
#include <QHash>
#include <QMimeData>
#include <QModelIndexList>
#include <QTableView>
#include <QListWidget>
#include <QDragEnterEvent>
#include <QDragMoveEvent>


#include <memory>

class Playlist;

class DatabaseHandler : public QObject
{
    Q_OBJECT;
    public:
    explicit DatabaseHandler(QString);
    QList <std::shared_ptr<Playlist>>  getPlaylists();

    void insertSong(QString);
    void addToPlaylist(QString, QString);

    public slots:
    std::shared_ptr< Playlist > createPlaylist(const QString&, bool allSongs=false);

signals:
    void playlistCreated();

    private:
    QString dbName;
    QSqlDatabase db;
    QList <std::shared_ptr <Playlist> > playlists;

    void init();
    void setupDb();
    void createTable(QHash <QString, QList <QString> >*, bool id=true);

    std::shared_ptr< Playlist > allSongs;
};

class PlaylistView : public QTableView
{
    Q_OBJECT;

    public:
    explicit PlaylistView();

signals:
    void deleteRow(int);

    private:
    QList <int> yPos;
    QPoint mouseStartPos;

    bool isDragging;

    int getRowId(int);

    void keyPressEvent(QKeyEvent *);
    void dragEnterEvent(QDragEnterEvent *);
    void dragMoveEvent(QDragMoveEvent *);
    void dropEvent(QDropEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);

};

class Playlist : public QSqlRelationalTableModel
{
    Q_OBJECT;
    public:
    explicit Playlist(QString name, QObject *parent=0, QSqlDatabase db=QSqlDatabase());

    Qt::ItemFlags flags(const QModelIndex&);
    QMimeData* mimeData(const QModelIndexList&) const;
    QStringList mimeTypes() const;
    QString getName() const;
    PlaylistView* getView();
    void update();

    private slots:
        void removeRow(int);
    private:
    const QString name;
    QSqlDatabase db;
    Qt::DropActions supportedDropActions() const;
    PlaylistView *view;
};

#endif
