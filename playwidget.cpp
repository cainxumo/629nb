#include "playwidget.h"
#include "ui_playwidget.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow2.h"
#include "ui_mainwindow2.h"
#include "mainwindow3.h"
#include "ui_mainwindow3.h"
#include "planet.h"
#include "math.h"
#include <QPainter>
#include <QTimer>
#include <QTime>
#include <QMouseEvent>
#include <QPushButton>
#include <QImage>
#include <QLabel>
#include <QPixmap>
#include <QPropertyAnimation>

playWidget::playWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::playWidget)
{
    ui->setupUi(this);
    resize(1200,720);
    setMouseTracking(true);
    ui->beginButton->setStyleSheet("background:white;color:black;");//改
    begin=0;

    timer = new QTimer;
    timer->setInterval(500);
    connect(timer,SIGNAL(timeout()),this,SLOT(timeOut()));
    timer->start();

    QPixmap pix1, pix2, pix3, pix4;
    pix1.load(":/images/planet2.png"); pix1=pix1.scaled(40,40);
    pix2.load(":/images/planet3.png"); pix2=pix2.scaled(80,80);
    pix3.load(":/images/planet4.png"); pix3=pix3.scaled(120,120);
    pix4.load(":/images/planet5.png"); pix4=pix4.scaled(160,160);

    ui->plan_11->setPixmap(pix1); ui->plan_12->setPixmap(pix1);
    ui->plan_13->setPixmap(pix1); ui->plan_14->setPixmap(pix1);
    ui->plan_21->setPixmap(pix2); ui->plan_22->setPixmap(pix2);
    ui->plan_23->setPixmap(pix2); ui->plan_24->setPixmap(pix2);
    ui->plan_31->setPixmap(pix3); ui->plan_32->setPixmap(pix3);
    ui->plan_33->setPixmap(pix3); ui->plan_34->setPixmap(pix3);
    ui->plan_41->setPixmap(pix4); ui->plan_42->setPixmap(pix4);
    ui->plan_43->setPixmap(pix4); ui->plan_44->setPixmap(pix4);

    plan_1.pos_x1 = -200; plan_1.pos_x2 = -400; plan_1.pos_x3 = 1380;plan_1.pos_x4 = 1580;
    plan_1.pos_y1 = rand()%550; plan_1.pos_y2 = rand()%550; plan_1.r = 20;
    plan_1.pos_y3 = rand()%550; plan_1.pos_y4 = rand()%550;
    plan_2.pos_x1 = -100; plan_2.pos_x2 = -300; plan_2.pos_x3 = 1580; plan_2.pos_x4 = 1680;
    plan_2.pos_y1 = rand()%550; plan_2.pos_y2 = rand()%550; plan_2.r = 40;
    plan_2.pos_y3 = rand()%550; plan_2.pos_y4 = rand()%550;
    plan_3.pos_x1 = -300; plan_3.pos_x2 = -200; plan_3.pos_x3 = 1480; plan_3.pos_x4 = 1580;
    plan_3.pos_y1 = rand()%550; plan_3.pos_y2 = rand()%550; plan_3.r = 60;
    plan_3.pos_y3 = rand()%550; plan_3.pos_y4 = rand()%550;
    plan_4.pos_x1 = -400; plan_4.pos_x2 = -300; plan_4.pos_x3 = 1680; plan_4.pos_x4 = 1480;
    plan_4.pos_y1 = rand()%550; plan_4.pos_y2 = rand()%550; plan_4.r = 80;
    plan_4.pos_y3 = rand()%550; plan_4.pos_y4 = rand()%550;

    movep11l = new QPropertyAnimation(ui->plan_11, "geometry");
    movep12r = new QPropertyAnimation(ui->plan_14, "geometry");
    movep21l = new QPropertyAnimation(ui->plan_21, "geometry");
    movep22r = new QPropertyAnimation(ui->plan_24, "geometry");
    movep31l = new QPropertyAnimation(ui->plan_31, "geometry");
    movep32r = new QPropertyAnimation(ui->plan_34, "geometry");
    movep41l = new QPropertyAnimation(ui->plan_41, "geometry");
    movep42r = new QPropertyAnimation(ui->plan_44, "geometry");
    movep12l = new QPropertyAnimation(ui->plan_12, "geometry");
    movep11r = new QPropertyAnimation(ui->plan_13, "geometry");
    movep22l = new QPropertyAnimation(ui->plan_22, "geometry");
    movep21r = new QPropertyAnimation(ui->plan_23, "geometry");
    movep32l = new QPropertyAnimation(ui->plan_32, "geometry");
    movep31r = new QPropertyAnimation(ui->plan_33, "geometry");
    movep42l = new QPropertyAnimation(ui->plan_42, "geometry");
    movep41r = new QPropertyAnimation(ui->plan_43, "geometry");
}

playWidget::~playWidget()
{
    delete ui;
}

//鼠标事件
void playWidget::mouseMoveEvent(QMouseEvent * event)
{
    if(begin==1)
    {
        player_x = event->pos().x();
        player_y = event->pos().y();
        update();
    }/*
    else if(begin==2){
        n=new MainWindow2();
        connect(n,SIGNAL(sendData(QString)),this,SLOT(receivData(QString)));
        n->show();
    }*/
}

//计时
void playWidget::timeOut()
{
    int i=rand()%15;
    if(begin==1){
        switch(i){
        case 0:
            movep11l->setDuration(5000);
            movep11l->setStartValue(QRect(plan_1.pos_x1, plan_1.pos_y1, 40, 40));
            movep11l->setEndValue(QRect(1380, plan_1.pos_y1, 40, 40));
            movep11l->start();break;
        case 1:
            movep11r->setDuration(5000);
            movep11r->setStartValue(QRect(plan_1.pos_x3, plan_1.pos_y3, 40, 40));
            movep11r->setEndValue(QRect(-380, plan_1.pos_y3, 40, 40));
            movep11r->start();break;
        case 2:
            movep12l->setDuration(5000);
            movep12l->setStartValue(QRect(plan_1.pos_x2, plan_1.pos_y2, 40, 40));
            movep12l->setEndValue(QRect(1380, plan_1.pos_y2, 40, 40));
            movep12l->start();break;
        case 3:
            movep12r->setDuration(5000);
            movep12r->setStartValue(QRect(plan_1.pos_x4, plan_1.pos_y4, 40, 40));
            movep12r->setEndValue(QRect(-380, plan_1.pos_y4, 40, 40));
            movep12r->start();break;
        case 4:
            movep21l->setDuration(5000);
            movep21l->setStartValue(QRect(plan_2.pos_x1, plan_2.pos_y1, 80, 80));
            movep21l->setEndValue(QRect(1380, plan_2.pos_y1, 80, 80));
            movep21l->start();break;
        case 5:
            movep21r->setDuration(5000);
            movep21r->setStartValue(QRect(plan_2.pos_x3, plan_2.pos_y3, 80, 80));
            movep21r->setEndValue(QRect(-380, plan_2.pos_y3, 80, 80));
            movep21r->start();break;
        case 6:
            movep22l->setDuration(5000);
            movep22l->setStartValue(QRect(plan_2.pos_x2, plan_2.pos_y2, 80, 80));
            movep22l->setEndValue(QRect(1380, plan_2.pos_y2, 80, 80));
            movep22l->start();break;
        case 7:
            movep22r->setDuration(5000);
            movep22r->setStartValue(QRect(plan_2.pos_x4, plan_2.pos_y4, 80, 80));
            movep22r->setEndValue(QRect(-380, plan_2.pos_y4, 80, 80));
            movep22r->start();break;
        case 8:
            movep31l->setDuration(5000);
            movep31l->setStartValue(QRect(plan_3.pos_x1, plan_3.pos_y1, 120, 120));
            movep31l->setEndValue(QRect(1380, plan_3.pos_y1, 120, 120));
            movep31l->start();break;
        case 9:
            movep31r->setDuration(5000);
            movep31r->setStartValue(QRect(plan_3.pos_x3, plan_3.pos_y3, 120, 120));
            movep31r->setEndValue(QRect(-380, plan_3.pos_y3, 120, 120));
            movep31r->start();break;
        case 10:
            movep32l->setDuration(5000);
            movep32l->setStartValue(QRect(plan_3.pos_x2, plan_3.pos_y2, 120, 120));
            movep32l->setEndValue(QRect(1380, plan_3.pos_y2, 120, 120));
            movep32l->start();break;
        case 11:
            movep32r->setDuration(5000);
            movep32r->setStartValue(QRect(plan_3.pos_x4, plan_3.pos_y4, 120, 120));
            movep32r->setEndValue(QRect(-380, plan_3.pos_y4, 120, 120));
            movep32r->start();break;
        case 12:
            movep41l->setDuration(5000);
            movep41l->setStartValue(QRect(plan_4.pos_x1, plan_4.pos_y1, 160, 160));
            movep41l->setEndValue(QRect(1380, plan_4.pos_y1, 160, 160));
            movep41l->start();break;
        case 13:
            movep41r->setDuration(5000);
            movep41r->setStartValue(QRect(plan_4.pos_x3, plan_4.pos_y3, 160, 160));
            movep41r->setEndValue(QRect(-380, plan_4.pos_y3, 160, 160));
            movep41r->start();break;
        case 14:
            movep42l->setDuration(5000);
            movep42l->setStartValue(QRect(plan_4.pos_x2, plan_4.pos_y2, 160, 160));
            movep42l->setEndValue(QRect(1380, plan_4.pos_y2, 160, 160));
            movep42l->start();break;
        case 15:
            movep42r->setDuration(5000);
            movep42r->setStartValue(QRect(plan_4.pos_x4, plan_4.pos_y4, 160, 160));
            movep42r->setEndValue(QRect(-380, plan_4.pos_y4, 160, 160));
            movep42r->start();break;
        default:break;
        }
    }
    update();
}

//绘图
void playWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(rect(),QPixmap(":/images/background.jpg"));

    QFont font;
    font.setPixelSize(30);
    font.setBold(true);
    painter.setFont(font);
    painter.drawText(QPoint(500,40),QString("当前得分： ")+QString("%1").arg(score));

    if(score<=50)
        player_r=30;
    else if(score<=200)
        player_r=50;
    else if(score<=300)
        player_r=70;
    else
    {//改.......................................................................
        this->hide();
        l=new MainWindow3();
        connect(l,SIGNAL(sendData(QString)),this,SLOT(receivData(QString)));
        l->show();
    }

    QImage player_1;
    player_1.load(":/images/planet1.png");
    QImage newPlayer = player_1.scaled(2*player_r,2*player_r);
    painter.drawImage(QPoint(player_x-player_r, player_y-player_r), newPlayer);

    ifCollide(ui->plan_11); ifCollide(ui->plan_12);
    ifCollide(ui->plan_13); ifCollide(ui->plan_14);
    ifCollide(ui->plan_21); ifCollide(ui->plan_22);
    ifCollide(ui->plan_23); ifCollide(ui->plan_24);
    ifCollide(ui->plan_31); ifCollide(ui->plan_32);
    ifCollide(ui->plan_33); ifCollide(ui->plan_34);
    ifCollide(ui->plan_41); ifCollide(ui->plan_42);
    ifCollide(ui->plan_43); ifCollide(ui->plan_44);

}

void playWidget::ifCollide(QLabel *l)
{
    int p1_x = l->x()+l->height()/2;
    int p1_y = l->y()+l->width()/2;
    int p2_x = player_x+player_r;
    int p2_y = player_y+player_r;
    if(sqrt(pow(p1_x-p2_x,2)+pow(p1_y-p2_y,2))<=(player_r+l->height()/2)){
        if(l->height()/2>player_r)
        {begin=2;
            this->hide();
        n=new MainWindow2();
        connect(n,SIGNAL(sendData(QString)),this,SLOT(receivData(QString)));
        n->show();}
        else {
            switch(l->height()){
            case 40:
                score+=10; break;
            case 80:
                score+=15; break;
            case 120:
                score+=20; break;
            }
            if(l==ui->plan_11) movep11l->setEndValue(QPoint(1380,l->y()));
            if(l==ui->plan_12) movep12l->setEndValue(QPoint(1380,l->y()));
            if(l==ui->plan_13) movep11r->setEndValue(QPoint(-380,l->y()));
            if(l==ui->plan_14) movep12r->setEndValue(QPoint(-380,l->y()));
            if(l==ui->plan_21) movep21l->setEndValue(QPoint(1380,l->y()));
            if(l==ui->plan_22) movep22l->setEndValue(QPoint(1380,l->y()));
            if(l==ui->plan_23) movep21r->setEndValue(QPoint(-380,l->y()));
            if(l==ui->plan_24) movep22r->setEndValue(QPoint(-380,l->y()));
            if(l==ui->plan_31) movep31l->setEndValue(QPoint(1380,l->y()));
            if(l==ui->plan_32) movep32l->setEndValue(QPoint(1380,l->y()));
            if(l==ui->plan_33) movep31r->setEndValue(QPoint(-380,l->y()));
            if(l==ui->plan_34) movep32r->setEndValue(QPoint(-380,l->y()));
            if(l==ui->plan_41) movep41l->setEndValue(QPoint(1380,l->y()));
            if(l==ui->plan_42) movep42l->setEndValue(QPoint(1380,l->y()));
            if(l==ui->plan_43) movep41r->setEndValue(QPoint(-380,l->y()));
            if(l==ui->plan_44) movep42r->setEndValue(QPoint(-380,l->y()));
        }
    }
}

void playWidget::on_beginButton_clicked()
{
    ui->beginButton->hide();
    begin = 1;
}

void playWidget::on_stop_clicked()
{
    m=new MainWindow();
    connect(m,SIGNAL(sendData(QString)),this,SLOT(receivData(QString)));
    m->show();
    this->hide();
}
