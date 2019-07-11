#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushBtn3_clicked();

    void on_pushBtn1_clicked();

    void on_pushBtn2_clicked();


signals:
    void sendData(QString data);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
