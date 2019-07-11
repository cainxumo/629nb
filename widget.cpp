#include "widget.h"
#include "ui_widget.h"
#include<QPainter>
#include<QPropertyAnimation>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setStyleSheet("Qpushbutton{color:rgb(0,255,255);"
                             "background-color:green;"

                             "}");
    ui->P1->setStyleSheet("QPushButton{"
                                  "border-image:url(:/new/prefix1/title.png)"
                                  "}");

    connect(&subwidget,SIGNAL(mysigal()),this,SLOT(dealsub()));

    QPropertyAnimation *animation = new QPropertyAnimation(this,"windowOpacity");
    animation->setDuration(1000);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->start();


}

Widget::~Widget()
{
    delete ui;
}
void Widget::paintEvent(QPaintEvent *)
{
  QPainter p(this);
  p.drawPixmap(rect(),QPixmap(":/new/prefix1/earth.jpg"));
}

void Widget::on_P1_clicked()
{

    QPropertyAnimation *animation2 = new QPropertyAnimation(&subwidget,"windowOpacity");
    animation2->setDuration(1000);
    animation2->setStartValue(0);
    animation2->setEndValue(1);
    animation2->start();
    subwidget.show();
    hide();
}
void Widget::dealsub(){
    subwidget.hide();
    QPropertyAnimation *animation2 = new QPropertyAnimation(this,"windowOpacity");
    animation2->setDuration(1000);
    animation2->setStartValue(0);
    animation2->setEndValue(1);
    animation2->start();
    show();

}
