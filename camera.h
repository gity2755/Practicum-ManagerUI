#ifndef CAMERA_H
#define CAMERA_H

#include <QWidget>
#include <QPushButton>
#include <QDebug>
#include <QLabel>
#include <QString>
#include <QTimer>
#include "cameraalerts.h"

class Camera : public QWidget
{
    Q_OBJECT

public:
    enum Resolution { LOW, MEDIUM, HIGH };

    explicit Camera(QWidget *parent = nullptr);
    void setToggleOnButton(QPushButton *button);
    void setIsCameraOn(bool isCameraOn);
    void setName(QString name);
    void setResolution(int resolution);
    void setCpuUsage(int cpuUsage);
    void setMemoryUsage(int memoryUsage);
    void setMemory(int memory);
    QString getName();
    int getResolution();
    int getCpuUsage();
    int getMemoryUsage();
    int getMemory();
    void addError(const QString &text, const QDateTime &dateTime);
    void scheduleError(const QString &text, int seconds);

private:
    bool m_isCameraOn;
    Resolution m_resolution;
    QString m_name;
    int m_cpuUsage;
    int m_memoryUsage;
    int m_memory;
    QPushButton *m_toggleOnButton;
    QLabel *m_label;
    QLabel *m_detailsLabel;
    CameraAlerts *m_cameraAlerts;
    QTimer *m_errorTimer;

private slots:
    void handleToggleOnButtonClicked();
    void showCameraSettings();
    void showAlerts();
    void backToCameraView();
    //void handleScheduledError();
};

#endif // CAMERA_H
