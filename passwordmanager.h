#ifndef PASSWORDMANAGER_H
#define PASSWORDMANAGER_H

#include <QMainWindow>

namespace Ui {
class PasswordManager;
}

class PasswordManager : public QMainWindow
{
    Q_OBJECT

public:
    explicit PasswordManager(QWidget *parent = 0);
    ~PasswordManager();

private:
    Ui::PasswordManager *ui;
};

#endif // PASSWORDMANAGER_H
