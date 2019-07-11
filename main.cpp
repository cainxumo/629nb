#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setWindowTitle(QObject::tr("流浪地球"));
    w.show();
    return a.exec();
}
