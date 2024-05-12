#ifndef ALLCAMERASPAGE_H
#define ALLCAMERASPAGE_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include "camera.h"

class AllCamerasPage : public QWidget
{
    Q_OBJECT

public:
    explicit AllCamerasPage(int numCameras, QWidget *parent = nullptr);
private:
    QGridLayout *layout;

};

#endif // ALLCAMERASPAGE_H
