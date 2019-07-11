#ifndef PLAYWIDGET_H
#define PLAYWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QDebug>
#include <QTimer>
#include <QTime>
#include <QMouseEvent>
#include "planet.h"
#include "mainwindow.h"
#include "mainwindow2.h"
#include "mainwindow3.h"
#include <QPropertyAnimation>
#include <QLabel>

namespace Ui {
class playWidget;
}

class playWidget : public QWidget
{
    Q_OBJECT

public:
        explicit playWidget(QWidget *parent = nullptr);
        ~playWidget();
protected:
        void paintEvent(QPaintEvent *);
        void mouseMoveEvent(QMouseEvent *);

private slots:
        void on_beginButton_clicked();
        void timeOut();

        void on_stop_clicked();

signals:
    void sendData(QString data);

private:
        Ui::playWidget *ui;
        MainWindow *m;
        MainWindow2 *n;
        MainWindow3 *l;
        int player_x,player_y,player_size;
        int score=0;
        QTimer *timer;
        int begin;
        void ifCollide(QLabel *l);
        int player_r=30;
        Planet plan_1, plan_2, plan_3, plan_4;
        QPropertyAnimation* movep11l;
        QPropertyAnimation* movep11r;
        QPropertyAnimation* movep21l;
        QPropertyAnimation* movep21r;
        QPropertyAnimation* movep31l;
        QPropertyAnimation* movep31r;
        QPropertyAnimation* movep41l;
        QPropertyAnimation* movep41r;
        QPropertyAnimation* movep12l;
        QPropertyAnimation* movep12r;
        QPropertyAnimation* movep22l;
        QPropertyAnimation* movep22r;
        QPropertyAnimation* movep32l;
        QPropertyAnimation* movep32r;
        QPropertyAnimation* movep42l;
        QPropertyAnimation* movep42r;
};

#endif // PLAYWIDGET_H
