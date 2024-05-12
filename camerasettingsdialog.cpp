#include "camerasettingsdialog.h"
#include "camera.h"
CameraSettingsDialog::CameraSettingsDialog(Camera *camera,QWidget *parent)
    : QDialog(parent)
{
    // הגדרת האלמנטים בפורמט שורה-ערך
    name = new QLineEdit(this);
    resolution = new QComboBox(this);
    saveButton = new QPushButton("Save", this);
    cancelButton = new QPushButton("Cancel", this);

    // הגדרת אופציות האיכות ב- ComboBox
    resolution->addItem("Low");
    resolution->addItem("Medium");
    resolution->addItem("High");

    // הגדרת פורמט המידע
    QFormLayout *formLayout = new QFormLayout();
    formLayout->addRow("name:", name);
    formLayout->addRow("resolution:", resolution);

    // הגדרת כפתורים
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(saveButton);
    buttonLayout->addWidget(cancelButton);

    // תצרת של המערך הכללי
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(formLayout);
    mainLayout->addLayout(buttonLayout);

    // קשר בין הכפתור לפונקציה המתאימה
    connect(saveButton, &QPushButton::clicked, this,[=]() { onSaveButtonClicked(camera); });
    connect(cancelButton, &QPushButton::clicked, this, &CameraSettingsDialog::reject);
}

// CameraSettingsDialog::~CameraSettingsDialog()
// {

// }

QStringList CameraSettingsDialog::getCameraSettings() const
{
    QStringList settings;
    settings << name->text() << resolution->currentText();
    return settings;
}

void CameraSettingsDialog::onSaveButtonClicked(Camera* camera)
{
    camera->setName(name->text());
    camera->setResolution(3);
    QString s=camera->getName();
    qDebug() << "Camera Name: " << s;
    accept(); // קריאה לפונקציה accept כדי לסגור את הדיאלוג ולהחזיר את הערכים
}
