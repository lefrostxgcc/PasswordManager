#ifndef PASSWORDMANAGER_MAINWINDOW_H
#define PASSWORDMANAGER_MAINWINDOW_H

#include <QMainWindow>
#include "base.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void copyLoginToClipbord(int siteIndex);
    void copyPasswordToClipBord(int siteIndex);

private:
    void init();

    Ui::MainWindow *ui;
    PasswordManager::Base passwordBase;
};

#endif // PASSWORDMANAGER_MAINWINDOW_H
