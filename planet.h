#ifndef PLANET_H
#define PLANET_H

#include <QWidget>
#include <QImage>
#include <QPaintEvent>

class Planet : public QWidget
{
    Q_OBJECT
public:
    explicit Planet(QWidget *parent = nullptr);
    int pos_x1,pos_y1,pos_x2,pos_y2;
    int pos_x3,pos_y3,pos_x4,pos_y4;
    QImage newImg;
    int r;
    Planet(Planet &p);
signals:

public slots:

private:
};

#endif // PLANET_H

