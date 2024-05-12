// camera.cpp
#include "camerasettingsdialog.h"
#include "camera.h"
#include <QVBoxLayout>
#include <QString>

Camera::Camera( QWidget *parent)
    : QWidget(parent)
{
    Resolution r=LOW;
    this->m_name="***";
    this->m_resolution=r;
    QVBoxLayout *cameraLayout = new QVBoxLayout(this);
    // Create and configure label for the image
    m_label = new QLabel(this);
    QString url = R"(D:\Gitty_learning\PRACTICOM\managerUI\img.png)";
    QPixmap img(url);
    m_label->setPixmap(img);
    cameraLayout->addWidget(m_label);

    // Create and configure label for camera details
    m_detailsLabel = new QLabel(this);
    m_detailsLabel->setText(QString("Name: %1\nResolution: %2").arg(m_name).arg(m_resolution));
    cameraLayout->addWidget(m_detailsLabel);

    // Create buttons
    m_toggleOnButton = new QPushButton("Turn on Camera", this);
    QPushButton *settingsButton = new QPushButton("Camera Settings", this);
    QPushButton *alertButton = new QPushButton("Show Alerts", this);

    // Connect buttons to slots
    connect(m_toggleOnButton, &QPushButton::clicked, this, &Camera::handleToggleOnButtonClicked);
    connect(settingsButton, &QPushButton::clicked, this, &Camera::showCameraSettings);

    // Add buttons to camera layout
    cameraLayout->addWidget(m_toggleOnButton);
    cameraLayout->addWidget(settingsButton);
    cameraLayout->addWidget(alertButton);
}

void Camera::setToggleOnButton(QPushButton *button)
{
    m_toggleOnButton = button;
}

void Camera::setIsCameraOn(bool isCameraOn)
{
    m_isCameraOn = isCameraOn;
}

void Camera::setCpuUsage(int cpuUsage)
{
    m_cpuUsage = cpuUsage;
}


void Camera::setName(QString name)
{
    m_name = name;
}

void Camera::setMemoryUsage(int resolution)
{
}
void Camera::setResolution(int resolution)
{
}

void Camera::setMemory(int memory)
{
    m_memory = memory;
}
int Camera::getCpuUsage()
{
    return m_cpuUsage;
}


QString Camera::getName()
{
return m_name;}

int Camera::getMemoryUsage()
{
    return 0;
}
int Camera::getResolution()
{
    return 3;
}

int Camera::getMemory()
{
return m_memory;}

void Camera::handleToggleOnButtonClicked()
{
    if (m_isCameraOn) {
        m_toggleOnButton->setText("Turn on Camera");
        setIsCameraOn(false);
        qDebug() << "Camera turned off";
    } else {
        m_toggleOnButton->setText(QStringLiteral("Turn Off Camera"));
        setIsCameraOn(true);
        qDebug() << "Camera turned on";
    }
}

void Camera::showCameraSettings()
{
    CameraSettingsDialog dialog(this);
    dialog.exec();
}
