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
    
    void init();
    void layout();
};

class PlayListView : public QListWidget
{
    Q_OBJECT;
public:
    explicit PlayListView(DatabaseHandler*, QStackedWidget*);

private slots:
    void changePlaylist(int);

private:
    DatabaseHandler *handler;
    QStackedWidget *stack;

    void extractFromDB(QStackedWidget*);
};

#endif
