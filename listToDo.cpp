#include "listToDo.h"
#include <QListWidgetItem>
#include <QCheckBox>
#include <QDebug>

bool ListToDo::firstItemChecked = false;

ListToDo::ListToDo(QWidget *parent)
    : QMainWindow(parent),
    listWidget(new QListWidget),
    textEdit(new QLineEdit),
    addItemButton(new QPushButton("Add Item")),
    verticalLayout(new QVBoxLayout)
{
    setWindowTitle("List To Do");

    // Add Widgets to layout
    verticalLayout->addWidget(textEdit);
    verticalLayout->addWidget(addItemButton);
    verticalLayout->addWidget(listWidget);

    // Set central widget
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(verticalLayout);
    setCentralWidget(centralWidget);

    connect(addItemButton, &QPushButton::clicked, this, &ListToDo::onAddItem);
}

void ListToDo::onAddItem()
{
    qDebug() << "Adding item...";
    QListWidgetItem *item = new QListWidgetItem();
    listWidget->addItem(item);

    QCheckBox *checkBox = new QCheckBox(textEdit->text());
    listWidget->setItemWidget(item, checkBox);

    connect(checkBox, &QCheckBox::clicked, this, &ListToDo::onItemChecked);

    qDebug() << "Item added.";
}

void ListToDo::onItemChecked()
{
    qDebug() << "Item checked.";
    if (!firstItemChecked)
    {
        qDebug() << "First item checked.";
        firstItemChecked = true;
        QPushButton *deleteButton = new QPushButton("To delete checked items");
        connect(deleteButton, &QPushButton::clicked, this, &ListToDo::onDeleteItems);
        verticalLayout->addWidget(deleteButton);
    }
}

void ListToDo::onDeleteItems()
{
    qDebug() << "Deleting checked items...";
    for (int i = listWidget->count() - 1; i >= 0; i--)
    {
        QListWidgetItem *item = listWidget->item(i);
        QWidget *widget = listWidget->itemWidget(item);
        if (widget)
        {
            QCheckBox *checkBox = qobject_cast<QCheckBox*>(widget);
            if (checkBox && checkBox->isChecked())
            {
                qDebug() << "Item" << i << "is checked.";
                listWidget->takeItem(i);
                delete item;
            }
        }
    }
    qDebug() << "Checked items deleted.";
}

ListToDo::~ListToDo()
{
    delete listWidget;
    delete textEdit;
    delete addItemButton;
    delete verticalLayout;
}
