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

    // Create an instance of CameraSettingsDialog
    // CameraSettingsDialog cameraSettingsDialog;
    // cameraSettingsDialog.exec(); // תציג את חלון ההגדרות של המצלמה

    AllCamerasPage allcameraspage(3);
    allcameraspage.show();
    return a.exec();
}
