#ifndef ALLCAMERASPAGE_H
#define ALLCAMERASPAGE_H

#include <QWidget>
#include <QGridLayout>

class AllCamerasPage : public QWidget
{
    Q_OBJECT

public:
    explicit AllCamerasPage(int numCameras, QWidget *parent = nullptr);
    void toggleCamera();
    void showCameraSettings();
    void showAlerts();

private:
    QGridLayout *layout;
    int numCameras; // משתנה חדש
};

#endif // ALLCAMERASPAGE_H
