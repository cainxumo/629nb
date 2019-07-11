#include "QWidget"
#include "planet.h"
#include "playwidget.h"
#include <QImage>
#include <QPainter>
#include <QPoint>

Planet::Planet(QWidget *parent) : QWidget(parent)
{

}

Planet::Planet(Planet &p):QWidget(this)
{
    pos_x1 = p.pos_x1; pos_y1 = p.pos_y1;
    pos_x2 = p.pos_x2; pos_y2 = p.pos_y2;
    pos_x3 = p.pos_x3; pos_y3 = p.pos_y3;
    pos_x4 = p.pos_x4; pos_y4 = p.pos_y4;
    r = p.r;
    newImg = p.newImg;
}
