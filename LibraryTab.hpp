#ifndef LIBRARYTAB_H
#define LIBRARYTAB_H

#include <QWidget>
#include <QStackedWidget>

#include "Window.hpp"
#include "DataHandler.hpp"

class LibraryTab : public TabWidget
{
    Q_OBJECT;
public:
    LibraryTab(MainWidget *);

private:
    QListWidget *playlistView;
    DatabaseHandler *dataHandler;
    QStackedWidget *tableView;
    
    void init(MainWidget *);
    void layout();
};

class PlayListView : public QListWidget
{
    Q_OBJECT;
public:
    explicit PlayListView(DatabaseHandler*, QStackedWidget*);

private slots:
    void changePlaylist(int);
public slots:
    void extractFromDB();

private:
    DatabaseHandler *handler;
    QStackedWidget *stack;

};

class PlaylistAdder : public QWidget
{
    Q_OBJECT;

    public:
    explicit PlaylistAdder();

    private:
    QLineEdit *text;

    signals:
        void createPlaylist(QString);

    private slots:
        void btnPressed();
};

#endif
