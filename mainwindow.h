#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QPushButton>
#include "allcameraspage.h" // Include the header file for AllCamerasPage

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showLoginPage();
    void showAllCamerasPage();

private:
    void createNavbar();

    QStackedWidget *stackedWidget;
    QPushButton *loginButton;
    QPushButton *allCamerasButton;

};

#endif // MAINWINDOW_H
