#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pPlayWindow = new PlayWindow();
    pCreateWindow = new CreateWindow();

    //Ceci permet de contourner les problèmes de Path liée build.
    QDir relativePath = QDir::current();
    while(relativePath.absolutePath().contains("/build-MemoryCards"))
    {
        std::cout<<relativePath.absolutePath().toStdString()<<std::endl;
        relativePath.setCurrent("../");
        relativePath = QDir::current();
    }

    QObject::connect(ui->playButton, &QPushButton::clicked, this, &MainWindow::switchPlayWindow);
    QObject::connect(pPlayWindow, &PlayWindow::returnToMainWindow, this, &MainWindow::switchPlayWindow);

    QObject::connect(ui->createButton, &QPushButton::clicked, this, &MainWindow::switchCreateWindow);
    QObject::connect(pCreateWindow, &CreateWindow::returnToMainWindow, this, &MainWindow::switchCreateWindow);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::switchPlayWindow()
{
    if (this->isVisible())
    {
        this->hide();

        Card *cardList[3] = {nullptr, nullptr, nullptr};
        cardList[0] = new Card(1);
        cardList[1] = new Card(2);
        cardList[2] = new Card(3);

        Play *pPlay = new Play("testGame", cardList, 3, 0);
        pPlayWindow->setCurrentPlay(pPlay);

        pPlayWindow->show();

    }
    else {
        pPlayWindow->hide();
        this->show();
    }
}

void MainWindow::switchCreateWindow()
{
    if (this->isVisible())
    {
        this->hide();
        pCreateWindow->show();
    }
    else {
        pCreateWindow->hide();
        this->show();
    }
}