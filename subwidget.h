#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include<QPushButton>
#include"mymusic.h"
#include"myhelp.h"
#include"playwidget.h"
namespace Ui {
class subwidget;
}
class subwidget : public QWidget
{
    Q_OBJECT
public:
    explicit subwidget(QWidget *parent = nullptr);
     ~subwidget();
    void sendslot();

signals:
    void mysigal();

public slots:
protected:
    void paintEvent(QPaintEvent *);
private slots:
    void on_p4_clicked();

    void on_p3_clicked();

    void on_p2_clicked();

    void on_p1_clicked();

    void receivData(QString data);

private:
    Ui::subwidget *ui;
    playWidget *t;
    mymusic mymusic;
    myhelp myhelp;
};

#endif // SUBWIDGET_H
