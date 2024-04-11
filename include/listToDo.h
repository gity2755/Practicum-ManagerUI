#ifndef LISTTODO_H
#define LISTTODO_H

#include <QMainWindow>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

class ListToDo : public QMainWindow
{
    Q_OBJECT

public:
    static bool firstItemChecked; // משתנה סטטי לבדיקת הבחירה

public:
    ListToDo(QWidget *parent = nullptr);
    ~ListToDo();

private slots:
    void onAddItem();
    void onItemChecked();
    void onDeleteItems();

private:
    QListWidget *listWidget;
    QLineEdit *textEdit;
    QPushButton *addItemButton;
    QVBoxLayout *verticalLayout;
};

#endif // LISTTODO_H
