#include "base.h"

PasswordManager::Base::Base(const QString &passwordFilename)
    : filename(passwordFilename)
{
}

QList<PasswordManager::Record> PasswordManager::Base::load()
{
    return {};
}

void PasswordManager::Base::save(const QList<PasswordManager::Record> &records)
{

}
