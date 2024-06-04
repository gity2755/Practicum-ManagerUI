#include "camera.h"
#include "camerasettingsdialog.h"
#include <QVBoxLayout>
#include <QString>

Camera::Camera(QWidget *parent)
    : QWidget(parent), m_isCameraOn(false), m_resolution(LOW), m_name("***"), m_cpuUsage(0), m_memoryUsage(0), m_memory(0)
{
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
    connect(alertButton, &QPushButton::clicked, this, &Camera::showAlerts);

    // Add buttons to camera layout
    cameraLayout->addWidget(m_toggleOnButton);
    cameraLayout->addWidget(settingsButton);
    cameraLayout->addWidget(alertButton);

    // Initialize CameraAlerts
    m_cameraAlerts = new CameraAlerts(this);
    m_cameraAlerts->setVisible(false);
    connect(m_cameraAlerts, &CameraAlerts::backRequested, this, &Camera::backToCameraView);

    cameraLayout->addWidget(m_cameraAlerts);
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
    m_resolution = static_cast<Resolution>(resolution);
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
    return m_name;
}

int Camera::getMemoryUsage()
{
    return m_memoryUsage;
}

int Camera::getResolution()
{
    return m_resolution;
}

int Camera::getMemory()
{
    return m_memory;
}

void Camera::handleToggleOnButtonClicked()
{
    if (m_isCameraOn) {
        m_toggleOnButton->setText("Turn on Camera");
        setIsCameraOn(false);
        qDebug() << "Camera turned off";
    } else {
        m_toggleOnButton->setText("Turn Off Camera");
        setIsCameraOn(true);
        qDebug() << "Camera turned on";
    }
}

void Camera::showCameraSettings()
{
    CameraSettingsDialog dialog(this);
    dialog.exec();
}

void Camera::showAlerts()
{
    m_cameraAlerts->setVisible(true);
    m_label->setVisible(false);
    m_detailsLabel->setVisible(false);
    m_toggleOnButton->setVisible(false);
}

void Camera::backToCameraView()
{
    m_cameraAlerts->setVisible(false);
    m_label->setVisible(true);
    m_detailsLabel->setVisible(true);
    m_toggleOnButton->setVisible(true);
}

void Camera::addError(const QString &text, const QDateTime &dateTime)
{
    m_cameraAlerts->addError(text, dateTime);
}

void Camera::scheduleError(const QString &text, int seconds)
{
    m_errorTimer = new QTimer(this);
    connect(m_errorTimer, &QTimer::timeout, [this, text]() {
        this->addError(text, QDateTime::currentDateTime());
        m_errorTimer->stop();
        m_errorTimer->deleteLater();
    });
    m_errorTimer->start(seconds * 1000);
}
