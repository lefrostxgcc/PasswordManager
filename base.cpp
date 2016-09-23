#include "base.h"
#include <QFile>
#include <QTextStream>

PasswordManager::Base::Base(const QString &passwordFilename)
    : filename(passwordFilename)
{
}

QList<PasswordManager::Record> PasswordManager::Base::load()
{
    QFile file{filename};
    file.open(QIODevice::ReadOnly);

    if (!file.isOpen())
        throw std::runtime_error{"Cannot open to load password base file"};

    QTextStream stream(&file);

    QList<Record> records;

    while (!stream.atEnd())
    {
        Record temp;
        QStringList lineList = stream.readLine().split('\t');
        temp.site = lineList[0];
        temp.login = lineList[1];
        temp.password = lineList[2];
        records.push_back(temp);
    }

    return records;
}

void PasswordManager::Base::save(const QList<PasswordManager::Record> &records)
{
    QFile file{filename};
    file.open(QIODevice::WriteOnly);

    if (!file.isOpen())
        throw std::runtime_error{"Cannot open to save password base file"};

    QTextStream stream(&file);

    for (const auto &x : records)
        stream << x.site << '\t' << x.login << '\t' << x.password << '\n';
}
