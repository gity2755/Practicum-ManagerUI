#include "login.h"

Login::Login(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("Login");

    // Username input
    QLabel *usernameLabel = new QLabel("Username:");
    usernameLineEdit = new QLineEdit();
    usernameLabel->setBuddy(usernameLineEdit);

    // Password input
    QLabel *passwordLabel = new QLabel("Password:");
    passwordLineEdit = new QLineEdit();
    passwordLineEdit->setEchoMode(QLineEdit::Password);
    passwordLabel->setBuddy(passwordLineEdit);

    // Login button
    loginButton = new QPushButton("Login");
    connect(loginButton, &QPushButton::clicked, this, &Login::attemptLogin);

    // Status label
    statusLabel = new QLabel();

    // Layout
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(usernameLabel);
    layout->addWidget(usernameLineEdit);
    layout->addWidget(passwordLabel);
    layout->addWidget(passwordLineEdit);
    layout->addWidget(loginButton);
    layout->addWidget(statusLabel);
    setLayout(layout);
}

void Login::attemptLogin()
{
    QString username = usernameLineEdit->text();
    QString password = passwordLineEdit->text();

    // כאן יש להוסיף לוגיקה לבדיקת ההתחברות
    // כרגע אני מקבל יוזר וסיסמה ומדפיס כי התחברתי
    // זה צריך להישנות להתאמה לדרישות הספציפיות של האפליקציה שלך
    if (username == "admin" && password == "password")
    {
        statusLabel->setText("Login successful!");
    }
    else
    {
        statusLabel->setText("Login failed. Please try again.");
    }
}
