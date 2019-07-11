#include "subwidget.h"
#include "ui_subwidget.h"
#include"mymusic.h"
#include "playwidget.h"
#include<QPainter>
#include<QLabel>
#include<QPropertyAnimation>
#include<QMediaPlayer>
#include<QPixmapCache>
#include<QPixmap>

subwidget::subwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::subwidget)
{
    this->resize(1000,500);
    ui->setupUi(this);
    ui->p1->setStyleSheet("QPushButton{"
                                  "border-image:url(:/new/prefix1/01.png)"
                                  "}"
                          "QPushButton:hover{"
                                  "border-image:url(:/new/prefix1/05.png)"
                                  "}"
                          );
    ui->p2->setStyleSheet("QPushButton{"
                                  "border-image:url(:/new/prefix1/02.png)"
                                  "}"
                          "QPushButton:hover{"
                                  "border-image:url(:/new/prefix1/05.png)"
                                  "}"
                          );
    ui->p3->setStyleSheet("QPushButton{"
                                  "border-image:url(:/new/prefix1/03.png)"
                                  "}"
                          "QPushButton:hover{"
                                  "border-image:url(:/new/prefix1/05.png)"
                                  "}"
                          );
    ui->p4->setStyleSheet("QPushButton{"
                                  "border-image:url(:/new/prefix1/04.png)"
                                  "}"
                          "QPushButton:hover{"
                                  "border-image:url(:/new/prefix1/05.png)"
                                  "}"
                          );



}
subwidget::~subwidget()
{
    delete ui;
}
void subwidget::paintEvent(QPaintEvent *)
{
  QPainter p(this);
  p.drawPixmap(rect(),QPixmap(":/new/prefix1/earth.jpg"));
}


void subwidget::on_p4_clicked()
{
    emit mysigal();
}


void subwidget::on_p3_clicked()
{
    QPixmap p;
    p.load(":/new/prefix1/musical.jpg");
    p=p.scaled(1000,500);
    QLabel *label = new QLabel(&mymusic);
    label->resize(frameGeometry().width(),frameGeometry().height());
    label->setPixmap(p);
    label->show();
    QPropertyAnimation *animation= new QPropertyAnimation(label,"geometry");
    animation->setDuration(4000);
    animation->setStartValue(mymusic.geometry());
    animation->setEndValue(QRect(-mymusic.width(), 0, mymusic.width(), mymusic.height()));
    animation->start();
    mymusic.show();

}

void subwidget::on_p2_clicked()
{
    QPixmap p;
    p.load(":/new/prefix1/musical.jpg");
    p=p.scaled(1000,500);
    QLabel *label = new QLabel(&myhelp);
    label->resize(frameGeometry().width(),frameGeometry().height());
    label->setPixmap(p);
    label->show();
    QPropertyAnimation *animation= new QPropertyAnimation(label,"geometry");
    animation->setDuration(4000);
    animation->setStartValue(myhelp.geometry());
    animation->setEndValue(QRect(-myhelp.width(), 0, myhelp.width(), myhelp.height()));
    animation->start();
    myhelp.show();
}

void subwidget::on_p1_clicked()
{
    t=new playWidget;
    connect(t,SIGNAL(sendData(QString)),this,SLOT(receivData(QString)));
    t->show();
}

