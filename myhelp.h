#ifndef HELP_H
#define HELP_H

#include <QWidget>
#include<QPushButton>
namespace Ui {
class myhelp;
}
class myhelp : public QWidget
{
    Q_OBJECT
public:
    explicit myhelp(QWidget *parent = nullptr);
~myhelp();
signals:

public slots:
protected:
    void paintEvent(QPaintEvent *);
private slots:
    void on_pushButton_clicked();

private:
    Ui::myhelp *ui;
};

#endif // HELP_H
