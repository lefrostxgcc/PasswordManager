#ifndef PASSWORDMANAGER_RECORD_H
#define PASSWORDMANAGER_RECORD_H

#include <QString>

namespace PasswordManager
{
    struct Record
    {
        QString site;
        QString login;
        QString password;
    };
}

#endif // PASSWORDMANAGER_RECORD_H
