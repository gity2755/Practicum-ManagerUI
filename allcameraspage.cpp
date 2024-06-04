#include "allcameraspage.h"
#include <QPixmap>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include "camerasettingsdialog.h"
#include "camera.h"

AllCamerasPage::AllCamerasPage(int numCameras, QWidget *parent)
    : QWidget(parent)
{
    layout = new QGridLayout(this);

    // Create an array to hold the cameras
    Camera **cameras = new Camera*[numCameras];

    int numRows = (numCameras + 2) / 3; // חישוב מספר השורות הדרושות

    // Loop to create camera widgets
    for (int i = 0; i < numCameras; ++i) {
        // Create a new Camera instance
        Camera *camera = new Camera(this);
        cameras[i] = camera;
        // Set up the camera's properties (e.g., resolution, name, etc.)
        camera->setResolution(1);
        camera->setIsCameraOn(false);
        camera->setName("Camera " + QString::number(i + 1));
        camera->setCpuUsage(0);
        camera->setMemoryUsage(0);
        camera->setMemory(0);
        camera->scheduleError("hi",5);
        // Add the camera widget to the layout
        layout->addWidget(camera, i / 3, i % 3);
    }

    qDebug() << "after loop" << layout;

    // Don't forget to delete the array of cameras when you're done with it
    delete[] cameras;

}
