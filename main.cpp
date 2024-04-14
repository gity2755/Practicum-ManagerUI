#include "mainwindow.h"
#include "camerasettingsdialog.h"
#include <QApplication>
#include "allcameraspage.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create an instance of MainWindow
    MainWindow mainWindow;
    mainWindow.show();


    return a.exec();
}
