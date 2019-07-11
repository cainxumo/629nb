#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"subwidget.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    void paintEvent(QPaintEvent *);

private slots:
    void on_P1_clicked();
    void dealsub();

private:
    Ui::Widget *ui;
    subwidget subwidget;
};

#endif // WIDGET_H
