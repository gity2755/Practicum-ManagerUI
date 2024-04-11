#include "camerasettingsdialog.h"

CameraSettingsDialog::CameraSettingsDialog(QWidget *parent)
    : QDialog(parent)
{
    // הגדרת האלמנטים בפורמט שורה-ערך
    ipLineEdit = new QLineEdit(this);
    qualityComboBox = new QComboBox(this);
    saveButton = new QPushButton("Save", this);
    cancelButton = new QPushButton("Cancel", this);

    // הגדרת אופציות האיכות ב- ComboBox
    qualityComboBox->addItem("Low");
    qualityComboBox->addItem("Medium");
    qualityComboBox->addItem("High");

    // הגדרת פורמט המידע
    QFormLayout *formLayout = new QFormLayout();
    formLayout->addRow("IP:", ipLineEdit);
    formLayout->addRow("Quality:", qualityComboBox);

    // הגדרת כפתורים
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(saveButton);
    buttonLayout->addWidget(cancelButton);

    // תצרת של המערך הכללי
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(formLayout);
    mainLayout->addLayout(buttonLayout);

    // קשר בין הכפתור לפונקציה המתאימה
    connect(saveButton, &QPushButton::clicked, this, &CameraSettingsDialog::onSaveButtonClicked);
    connect(cancelButton, &QPushButton::clicked, this, &CameraSettingsDialog::reject);
}

CameraSettingsDialog::~CameraSettingsDialog()
{
}

QStringList CameraSettingsDialog::getCameraSettings() const
{
    QStringList settings;
    settings << ipLineEdit->text() << qualityComboBox->currentText();
    return settings;
}

void CameraSettingsDialog::onSaveButtonClicked()
{
    accept(); // קריאה לפונקציה accept כדי לסגור את הדיאלוג ולהחזיר את הערכים
}
