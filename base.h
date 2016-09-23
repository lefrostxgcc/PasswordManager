#ifndef PASSWORDMANAGER_BASE_H
#define PASSWORDMANAGER_BASE_H

#include <QString>
#include <QList>
#include "record.h"

namespace PasswordManager
{
    class Base
    {
    public:
        explicit Base(const QString &passwordFilename);
        QList<Record> load();
        void save(const QList<Record> &records);

    private:
        QString filename;
    };

}

#endif // PASSWORDMANAGER_BASE_H
