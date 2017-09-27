#include "DownloadTab.hpp"

#include <iostream>

#include <QApplication>
#include <QMenuBar>
#include <QBoxLayout>



MainWindow::MainWindow(QWidget &widget)
{
    setCentralWidget(&widget);
    //createMenus();
    //addMenuBars();
    show();
}
void MainWindow::createMenus()
{
    //menuBars = {"file"};
    //menus["file"] = {std::make_pair("Exit", exitApp())};
}
void MainWindow::addMenuBars()
{
    QMenuBar *bar = menuBar();

    /*
    for (int i = 0; i < (sizeof(menuBars) / sizeof(menuBars[0])); i++)
    {
        QMenu currentBar = bar->addMenu(QString::fromStdString(menuBars[i]));

        for (int x = 0; x < (sizeof(menus[menuBars[i]]) / sizeof(menus[menuBars[i]][0]));e x++)
        {
            currentBar.addAction(menus[menuBars[i]][x].first());
        }
    }
    */
}
int MainWindow::exitApp()
{
    return 1;
}

MainWidget::MainWidget()
{
    //btns();
}

TabWidget::TabWidget(MainWidget &tabManger, const char *tabName)
{
    autoAdd(tabManger, tabName);
    //styling();
}
void TabWidget::autoAdd(MainWidget &tabManger, const char *tabName)
{
    tabManger.addTab(this, QString(tabName));
}


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWidget mainWidget;
    DownloadWidget downloadWidget(&mainWidget);
    MainWindow window(mainWidget);

    return app.exec();
}
