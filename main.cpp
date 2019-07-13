#include "app/myapplication.h"
#include <QtWidgets/QSystemTrayIcon>
#include <QtWidgets/QMenu>
#include <QDebug>

int main(int argc, char *argv[])
{
    MyApplication a(argc, argv);
    a.showTrayIcon();
    return a.exec();
}
