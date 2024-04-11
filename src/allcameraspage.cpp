#include "allcameraspage.h"
#include <QPixmap>
#include <QLabel>
#include <QVBoxLayout>

AllCamerasPage::AllCamerasPage(int numCameras, QWidget *parent)
    : QWidget(parent)
{
    layout = new QVBoxLayout(this);

    // Loop to create camera widgets
    for (int i = 0; i <3; i++)
    {
        // Create camera widget
        QWidget *cameraWidget = new QWidget();
        qDebug()<<"cameraWidget"<<cameraWidget;
        QVBoxLayout *cameraLayout = new QVBoxLayout(cameraWidget);
        qDebug()<<"cameraLayout"<<cameraLayout;
        // Create QLabel for the camera image
        QLabel *cameraImageLabel = new QLabel();
        qDebug()<<"cameraImageLabel"<<cameraImageLabel;
        // Load the image from a file in the project directory
        QPixmap pixmap(":/camgif.gif");
        cameraImageLabel->setPixmap(pixmap);
        // Add QLabel to camera layout
        cameraLayout->addWidget(cameraImageLabel);
        qDebug()<<"after"<<pixmap;

        // Add camera widget to the AllCamerasPage layout
        layout->addWidget(cameraWidget);
    }
}


