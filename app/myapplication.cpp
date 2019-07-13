#include <QDebug>
#include <QMenu>
#include "myapplication.h"


MyApplication* MyApplication::instance = nullptr;


MyApplication* MyApplication::getInstance() {
    return instance;
}

MyApplication::MyApplication(int &argc, char** argv)
    : QApplication (argc, argv)
{
    instance = this;

    QPixmap pixmap(32, 32);
    pixmap.load("://images/tray.png");
    QIcon icon(pixmap);
    QMenu* menu = new QMenu();
    QAction* breakAction = menu->addAction("Break");
    QObject::connect(breakAction, SIGNAL(triggered()), this, SLOT(doBreak()));
    QAction* exitAction = menu->addAction("Exit");
    QObject::connect(exitAction, SIGNAL(triggered()), this, SLOT(quit()));
    trayIcon = new QSystemTrayIcon(icon, this);
    trayIcon->setContextMenu(menu);
    trayIcon->setToolTip("Qt Pomodoro");
}

void MyApplication::showTrayIcon() {
    trayIcon->show();
}

void MyApplication::doBreak() {
    qDebug() << "Start break...";

    QPixmap pixmap(32, 32);
    pixmap.load("://images/tray_break.png");
    QIcon icon(pixmap);
    trayIcon->setIcon(icon);
}
