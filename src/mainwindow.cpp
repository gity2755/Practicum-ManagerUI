#include "mainwindow.h"
#include "login.h"
#include "listToDo.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    stackedWidget = new QStackedWidget(this);
    setCentralWidget(stackedWidget);

    createNavbar();

    Login *loginPage = new Login(this);
    ListToDo *listToDoPage = new ListToDo(this);

    stackedWidget->addWidget(loginPage);
    stackedWidget->addWidget(listToDoPage);

    connect(loginButton, &QPushButton::clicked, this, &MainWindow::showLoginPage);
    connect(listToDoButton, &QPushButton::clicked, this, &MainWindow::showListToDoPage);
}

MainWindow::~MainWindow()
{
}

void MainWindow::createNavbar()
{
    QWidget *navbar = new QWidget(this);
    QHBoxLayout *layout = new QHBoxLayout(navbar);

    loginButton = new QPushButton("Login");
    listToDoButton = new QPushButton("List To Do");
    QPushButton *allCamerasButton = new QPushButton("All Cameras"); // יצירת הכפתור החדש

    layout->addWidget(loginButton);
    layout->addWidget(listToDoButton);
    layout->addWidget(allCamerasButton); // הוספת הכפתור החדש לתפריט

    navbar->setLayout(layout);
    setMenuWidget(navbar);

    // חיבור האירוע לפונקציה המתאימה
    connect(allCamerasButton, &QPushButton::clicked, this, &MainWindow::showAllCamerasPage);
}

void MainWindow::showLoginPage()
{
    stackedWidget->setCurrentIndex(0); // Index of the login page in the stacked widget
}

void MainWindow::showListToDoPage()
{
    stackedWidget->setCurrentIndex(1); // Index of the ListToDo page in the stacked widget
}
void MainWindow::showAllCamerasPage()
{
    // Create an instance of AllCamerasPage with a specific number of cameras
    int numCameras = 3; // Change this to the desired number of cameras
    AllCamerasPage *allCamerasPage = new AllCamerasPage(numCameras);

    // Add the AllCamerasPage to the stacked widget
    stackedWidget->addWidget(allCamerasPage);

    // Set the current page to the AllCamerasPage
    stackedWidget->setCurrentWidget(allCamerasPage);
}


