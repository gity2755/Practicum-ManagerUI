#include "mainwindow.h"
#include "login.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    stackedWidget = new QStackedWidget(this);
    setCentralWidget(stackedWidget);

    createNavbar();

    Login *loginPage = new Login(this);
    AllCamerasPage *allCamerasPage=new AllCamerasPage(3);

    stackedWidget->addWidget(loginPage);
    stackedWidget->addWidget(allCamerasPage);

    connect(loginButton, &QPushButton::clicked, this, &MainWindow::showLoginPage);
    connect(allCamerasButton, &QPushButton::clicked, this, &MainWindow::showAllCamerasPage);

}

MainWindow::~MainWindow()
{
}

// בקובץ הכותרת MainWindow.cpp

void MainWindow::createNavbar()
{
    QWidget *navbar = new QWidget(this);
    QHBoxLayout *layout = new QHBoxLayout(navbar);

    loginButton = new QPushButton("Login");
    allCamerasButton = new QPushButton("All Cameras"); // יצירת הכפתור החדש

    layout->addWidget(loginButton);
    layout->addWidget(allCamerasButton); // הוספת הכפתור החדש לתפריט

    navbar->setLayout(layout);
    setMenuWidget(navbar);

    // חיבור האירוע לפונקציה המתאימה
    connect(loginButton, &QPushButton::clicked, this, &MainWindow::showLoginPage);
    connect(allCamerasButton, &QPushButton::clicked, this, &MainWindow::showAllCamerasPage);
}

void MainWindow::showLoginPage()
{
    stackedWidget->setCurrentIndex(0); // Index of the login page in the stacked widget
}


void MainWindow::showAllCamerasPage()
{
    stackedWidget->setCurrentIndex(1); // Index of the cameras page page in the stacked widget

}


