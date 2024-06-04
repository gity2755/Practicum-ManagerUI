#ifndef ERRORLOG_H
#define ERRORLOG_H

#include <QVector>
#include <QPair>
#include <QDate>
#include <QString>

class ErrorLog
{
public:
    static void addError(const QString &text, const QDateTime &dateTime);
    static const QVector<QPair<QString, QDateTime>>& getErrors();

private:
    static QVector<QPair<QString, QDateTime>> errors;
};

#endif // ERRORLOG_H
