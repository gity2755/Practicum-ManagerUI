#include "errorlog.h"

QVector<QPair<QString, QDateTime>> ErrorLog::errors;

void ErrorLog::addError(const QString &text, const QDateTime &dateTime)
{
    errors.append(qMakePair(text, dateTime));
}

const QVector<QPair<QString, QDateTime>>& ErrorLog::getErrors()
{
    return errors;
}
