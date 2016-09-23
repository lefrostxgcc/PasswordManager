#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSignalMapper>
#include <QClipboard>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    passwordBase{"records.txt"}
{
    ui->setupUi(this);

    ui->labelSiteTemplate           ->setVisible(false);
    ui->pushButtonLoginTemplate     ->setVisible(false);
    ui->pushButtonPasswordTemplate  ->setVisible(false);

    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::copyLoginToClipbord(int siteIndex)
{
    QApplication::clipboard()->setText(records[siteIndex].login);
}

void MainWindow::copyPasswordToClipbord(int siteIndex)
{
    QApplication::clipboard()->setText(records[siteIndex].password);
    close();
}

void MainWindow::init()
{
    records = passwordBase.load();

    QSignalMapper *loginMapper    = new QSignalMapper(this);
    QSignalMapper *passMapper     = new QSignalMapper(this);

    connect(loginMapper,    SIGNAL(mapped(int)), this, SLOT(copyLoginToClipbord(int))   );
    connect(passMapper,     SIGNAL(mapped(int)), this, SLOT(copyPasswordToClipBord(int)));

    for (int curRecord{}; curRecord < records.size(); ++curRecord)
    {
        QLabel      *site       = createLabelSite();
        QPushButton *login      = createButtonLogin();
        QPushButton *password   = createButtonPassword();

        site->setText("<a href=\""+ records[curRecord].siteAddress + "\">" + records[curRecord].siteName + "</a>");
        connect(login,      SIGNAL(clicked()), loginMapper, SLOT(map()));
        connect(password,   SIGNAL(clicked()), passMapper,  SLOT(map()));

        loginMapper->setMapping(login,    curRecord);
        passMapper ->setMapping(password, curRecord);

        ui->gridLayout->addWidget(site,     curRecord + 1, 0);
        ui->gridLayout->addWidget(login,    curRecord + 1, 1);
        ui->gridLayout->addWidget(password, curRecord + 1, 2);
    }
}

QLabel *MainWindow::createLabelSite()
{
    QLabel *label = new QLabel;
    label->setOpenExternalLinks(true);
    label->setFont(ui->labelSiteTemplate->font());

    return label;
}

QPushButton *MainWindow::createButtonLogin()
{
    QPushButton *button = new QPushButton;
    button->setText(ui->pushButtonLoginTemplate->text());
    button->setMinimumSize(ui->pushButtonLoginTemplate->minimumSize());
    button->setMaximumSize(ui->pushButtonLoginTemplate->maximumSize());
    button->setFont(ui->pushButtonLoginTemplate->font());

    return button;
}

QPushButton *MainWindow::createButtonPassword()
{
    QPushButton *button = new QPushButton;
    button->setText(ui->pushButtonPasswordTemplate->text());
    button->setMinimumSize(ui->pushButtonPasswordTemplate->minimumSize());
    button->setMaximumSize(ui->pushButtonPasswordTemplate->maximumSize());
    button->setFont(ui->pushButtonPasswordTemplate->font());

    return button;
}
