#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionLogin_triggered()
{
    login log;
    ui->tabWidget->setTabEnabled(0, log.getCred());
    ui->tabWidget->setTabEnabled(1, !log.getCred());
    ui->tabWidget->setCurrentIndex(log.getCred());

    log.setModal(true);
    log.exec();
}

