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
#include "camera.h"
class CameraSettingsDialog : public QDialog
{
    Q_OBJECT
public:
    explicit CameraSettingsDialog(Camera *camera,QWidget *parent = nullptr);
   // ~CameraSettingsDialog();

    // פונקציה לקבלת הנתונים שהוכנסו
    QStringList getCameraSettings() const;

private:
    QLineEdit *name;
    QComboBox *resolution;
    QPushButton *saveButton;
    QPushButton *cancelButton;

private slots:
    void onSaveButtonClicked(Camera* camera);
};

#endif // CAMERASETTINGSDIALOG_H
