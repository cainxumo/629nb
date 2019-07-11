#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "playwidget.h"
#include "ui_playwidget.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1200,720);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushBtn3_clicked()//退出
{
    close();
}

void MainWindow::on_pushBtn1_clicked()//继续游戏(先不搞)
{
    close();
}

void MainWindow::on_pushBtn2_clicked()//再来一局
{
    close();
}
