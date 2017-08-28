#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QMainWindow>
#include <QMenu>

#include <map>

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

private:
    void addTabs();
    void btns();
};

class TabWidget : public QWidget
{
    Q_OBJECT;

public:
    TabWidget(MainWidget &tabManger, const char *tabName);
private:
    void autoAdd(MainWidget &tabManger, const char *tabName);
    //void styling();
};

#endif
