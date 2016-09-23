#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    passwordBase{"records.txt"}
{
    ui->setupUi(this);
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::copyLoginToClipbord(int siteIndex)
{

}

void MainWindow::copyPasswordToClipBord(int siteIndex)
{

}

void MainWindow::init()
{

}
