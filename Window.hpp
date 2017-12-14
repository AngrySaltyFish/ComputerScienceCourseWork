#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QMainWindow>
#include <QMenu>

#include <map>
#include "DataHandler.hpp"


class MainWindow : public QMainWindow
{
    Q_OBJECT;

public:
    MainWindow(QWidget &centralWidget);

private:
    std::string menuBars;
    //std::map<const std::string, std::pair<std::string, int>[]> menus;

    void addMenuBars();
    void createMenus();
    int exitApp();
};

class MainWidget : public QTabWidget
{
    Q_OBJECT;

public:
    MainWidget();

    void setFileManger(DatabaseHandler *);
    DatabaseHandler& getFileManger();

private:
    void addTabs();
    void btns();

    DatabaseHandler *handler;
};

class TabWidget : public QWidget
{
    Q_OBJECT;

public:
    TabWidget(MainWidget &tabManger, const char *tabName);

private:
    void autoAdd(MainWidget &tabManger, const char *tabName);
};

#endif
