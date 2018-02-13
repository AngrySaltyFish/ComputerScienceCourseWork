#include "DownloadTab.hpp"
#include "LibraryTab.hpp"

#include <iostream>

#include <QApplication>
#include <QMenuBar>
#include <QBoxLayout>

#include "Window.hpp"

MainWindow::MainWindow(QWidget &widget)
{
    setCentralWidget(&widget);
    show();
}

MainWidget::MainWidget()
{
}
void MainWidget::setFileManger(DatabaseHandler *fileHandler)
{
    handler = fileHandler;
}
DatabaseHandler& MainWidget::getFileManger()
{
    return *handler;
}

TabWidget::TabWidget(MainWidget &tabManger, const char *tabName)
{
    autoAdd(tabManger, tabName);

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
    LibraryTab libraryTab(&mainWidget);
    MainWindow window(mainWidget);

    return app.exec();
}
