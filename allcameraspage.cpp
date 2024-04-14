#include "allcameraspage.h"
#include <QPixmap>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include "camerasettingsdialog.h"

AllCamerasPage::AllCamerasPage(int numCameras, QWidget *parent)
    : QWidget(parent)
{
    QGridLayout* gridLayout = new QGridLayout(this);

    int numRows = (numCameras + 2) / 3; // חישוב מספר השורות הדרושות

    // Loop to create camera widgets
    for (int i = 0; i < numCameras; i++)
    {
        // Create camera widget
        QWidget *cameraWidget = new QWidget(this);
        QVBoxLayout *cameraLayout = new QVBoxLayout(cameraWidget);
        QString url = R"(D:\Gitty_learning\PRACTICOM\managerUI\img.png)";
        QPixmap img(url);
        QLabel *label = new QLabel(this);
        label->setPixmap(img);
        cameraLayout->addWidget(label);

        // Create buttons
        QPushButton *toggleButton = new QPushButton("Toggle Camera", this);
        QPushButton *settingsButton = new QPushButton("Camera Settings", this);
        QPushButton *alertButton = new QPushButton("Show Alerts", this);

        // Connect buttons to slots
        connect(toggleButton, &QPushButton::clicked, this, &AllCamerasPage::toggleCamera);
        connect(settingsButton, &QPushButton::clicked, this, &AllCamerasPage::showCameraSettings);
        connect(alertButton, &QPushButton::clicked, this, &AllCamerasPage::showAlerts);

        // Add buttons to camera layout
        cameraLayout->addWidget(toggleButton);
        cameraLayout->addWidget(settingsButton);
        cameraLayout->addWidget(alertButton);

        gridLayout->addWidget(cameraWidget, i / 3, i % 3); // הוספת הווידג'ט לגריד
    }

    // כלום לא צריך לשנות פה
    qDebug() << "after" << gridLayout;
}

void AllCamerasPage::toggleCamera()
{
    // קוד להדלקה/כיבוי מצלמה
}

void AllCamerasPage::showCameraSettings()
{
    CameraSettingsDialog dialog;
    dialog.exec();
}

void AllCamerasPage::showAlerts()
{
    // קוד להצגת אזהרות
}
