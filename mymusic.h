#ifndef MUSIC_H
#define MUSIC_H

#include <QWidget>
#include<QPushButton>
#include<QMediaPlayer>

namespace Ui {
class mymusic;
}
class mymusic : public QWidget
{
    Q_OBJECT
public:
    explicit mymusic(QWidget *parent = nullptr);
~mymusic();
    QMediaPlayer *myPlayer= new QMediaPlayer;
signals:

public slots:
protected:
    void paintEvent(QPaintEvent *);
private slots:
    void on_p1_clicked();

    void on_p2_clicked();

private:
    Ui::mymusic *ui;
};

#endif // MUSIC_H
