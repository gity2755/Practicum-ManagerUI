#include "cameraalerts.h"

CameraAlerts::CameraAlerts(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    m_errorText = new QTextEdit(this);
    m_errorText->setReadOnly(true);
    layout->addWidget(m_errorText);

    m_backButton = new QPushButton("Back to Camera View", this);
    connect(m_backButton, &QPushButton::clicked, this, &CameraAlerts::backToCameraView);
    layout->addWidget(m_backButton);

    loadErrors();
    // const QDateTime datetime = QDateTime::currentDateTime();
    // addError("fff", datetime);

}

void CameraAlerts::addError(const QString &text, const QDateTime &dateTime)
{
    ErrorLog::addError(text, dateTime);
    m_errorText->append(QString("[%1] %2").arg(dateTime.toString(), text));
}

void CameraAlerts::loadErrors()
{
    const auto &errors = ErrorLog::getErrors();
    for (const auto &error : errors)
    {
        m_errorText->append(QString("[%1] %2").arg(error.second.toString(), error.first));
    }
}

void CameraAlerts::backToCameraView()
{
    emit backRequested();
}
