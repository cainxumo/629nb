#include "myhelp.h"
#include "ui_myhelp.h"
#include<QPainter>
#include<QPropertyAnimation>
myhelp::myhelp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myhelp)
{
 ui->setupUi(this);
 ui->pushButton->setStyleSheet("QPushButton{"
                               "border-image:url(:/new/prefix1/06.png)"
                               "}"
                               "QPushButton:hover{"
                                       "border-image:url(:/new/prefix1/05.png) "
                                       "}"
                               );
 ui->l1->setStyleSheet("QLabel{"
                            "background-color:rgba(255,255,255,50%)"
                       "}"
                       );
 ui->l2->setStyleSheet("QLabel{"
                            "background-color:rgba(255,255,255,50%)"
                       "}"
                       );
}
myhelp::~myhelp()
{
    delete ui;
}
void myhelp::paintEvent(QPaintEvent *)
{
  QPainter p(this);
  p.drawPixmap(rect(),QPixmap(":/new/prefix1/menu.jpg"));
}

void myhelp::on_pushButton_clicked()
{
    QPropertyAnimation *animation2 = new QPropertyAnimation(this,"windowOpacity");
    animation2->setDuration(1000);
    animation2->setStartValue(1);
    animation2->setEndValue(0);
    animation2->start();

}
