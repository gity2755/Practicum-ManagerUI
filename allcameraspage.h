#ifndef ALLCAMERASPAGE_H
#define ALLCAMERASPAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>

class AllCamerasPage : public QWidget
{
    Q_OBJECT

public:
    explicit AllCamerasPage(int numCameras, QWidget *parent = nullptr);

private:
    QVBoxLayout *layout;
};

#endif // ALLCAMERASPAGE_H
