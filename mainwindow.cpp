#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSignalMapper>

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
    records = passwordBase.load();

    QSignalMapper *loginMapper    = new QSignalMapper(this);
    QSignalMapper *passMapper     = new QSignalMapper(this);

    connect(loginMapper,    SIGNAL(mapped(int)), this, SLOT(copyLoginToClipbord(int))   );
    connect(passMapper,     SIGNAL(mapped(int)), this, SLOT(copyPasswordToClipBord(int)));

    for (int recordIndex{}; recordIndex < records.size(); ++recordIndex)
    {
        QLabel      *site = createLabelSite();
        QPushButton *login = createButtonLogin();
        QPushButton *password = createButtonPassword();

        site->setText(records[recordIndex].site);
        connect(login,      SIGNAL(clicked()), loginMapper, SLOT(map()));
        connect(password,   SIGNAL(clicked()), passMapper,  SLOT(map()));

        loginMapper->setMapping(login,    recordIndex);
        passMapper ->setMapping(password, recordIndex);

        ui->gridLayout->addWidget(site,     recordIndex + 1, 0);
        ui->gridLayout->addWidget(login,    recordIndex + 1, 1);
        ui->gridLayout->addWidget(password, recordIndex + 1, 2);
    }
}

QLabel *MainWindow::createLabelSite()
{
    return {};
}

QPushButton *MainWindow::createButtonLogin()
{
    return {};
}

QPushButton *MainWindow::createButtonPassword()
{
    return {};
}
