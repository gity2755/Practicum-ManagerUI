#ifndef CAMERAALERTS_H
#define CAMERAALERTS_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QDate>
#include "errorlog.h"

class CameraAlerts : public QWidget
{
    Q_OBJECT

public:
    explicit CameraAlerts(QWidget *parent = nullptr);
    void addError(const QString &text, const QDateTime &dateTime);
    void loadErrors();

private slots:
    void backToCameraView();

signals:
    void backRequested();

private:
    QTextEdit *m_errorText;
    QPushButton *m_backButton;
};

#endif // CAMERAALERTS_H
