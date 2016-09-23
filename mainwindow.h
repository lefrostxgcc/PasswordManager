#ifndef PASSWORDMANAGER_MAINWINDOW_H
#define PASSWORDMANAGER_MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
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
    void copyPasswordToClipbord(int siteIndex);

private:
    void init();
    QLabel      *createLabelSite();
    QPushButton *createButtonLogin();
    QPushButton *createButtonPassword();

    Ui::MainWindow *ui;
    PasswordManager::Base passwordBase;
    QList<PasswordManager::Record> records;
};

#endif // PASSWORDMANAGER_MAINWINDOW_H
