#include "mymusic.h"
#include "ui_mymusic.h"
#include<QPainter>
#include<QMediaPlayer>
mymusic::mymusic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mymusic)
{
    ui->setupUi(this);
    ui->p1->setStyleSheet("QPushButton{"
                                  "border-image:url(:/new/prefix1/06.png)"
                                  "}"
                          "QPushButton:hover{"
                                  "border-image:url(:/new/prefix1/05.png) "
                                  "}"
                          );
    ui->p2->setStyleSheet("QPushButton{"
                                  "border-image:url(:/new/prefix1/06.png)"
                                  "}"
                          "QPushButton:hover{"
                                  "border-image:url(:/new/prefix1/05.png) "
                                  "}"
                          );
}
mymusic::~mymusic()
{
    delete ui;
}
void mymusic::paintEvent(QPaintEvent *)
{
  QPainter p(this);
  p.drawPixmap(rect(),QPixmap(":/new/prefix1/menu.jpg"));
}

void mymusic::on_p1_clicked()
{
    myPlayer->setMedia(QUrl::fromLocalFile("D:/qt/lldq3.2/lldq3/music/music.mp3"));
    myPlayer->setVolume(80);
    myPlayer->play();
}

void mymusic::on_p2_clicked()
{
   myPlayer->pause();
}
