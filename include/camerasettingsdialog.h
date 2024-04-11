#ifndef CAMERASETTINGSDIALOG_H
#define CAMERASETTINGSDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QCheckBox>
#include <QComboBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>

class CameraSettingsDialog : public QDialog
{
    Q_OBJECT
public:
    explicit CameraSettingsDialog(QWidget *parent = nullptr);
    ~CameraSettingsDialog();

    // פונקציה לקבלת הנתונים שהוכנסו
    QStringList getCameraSettings() const;

private:
    QLineEdit *ipLineEdit;
    QComboBox *qualityComboBox;
    QPushButton *saveButton;
    QPushButton *cancelButton;

private slots:
    void onSaveButtonClicked();
};

#endif // CAMERASETTINGSDIALOG_H
