#include "getusbdiskwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GetUsbDiskWidget w;
    w.show();

    return a.exec();
}
