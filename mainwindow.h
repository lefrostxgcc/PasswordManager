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

private:
    Ui::MainWindow *ui;
    PasswordManager::Base passwordBase;
};

#endif // PASSWORDMANAGER_MAINWINDOW_H
