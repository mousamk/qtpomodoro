#include <QDebug>
#include <QMenu>
#include "myapplication.h"
#include "ui/mainwindow.h"


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
    showHideAction = menu->addAction("Show");
    connect(showHideAction, SIGNAL(triggered()), SLOT(showOrHideWindow()));
//    QAction* breakAction = menu->addAction("Break");
//    connect(breakAction, SIGNAL(triggered()), SLOT(doBreak()));
    QAction* exitAction = menu->addAction("Exit");
    connect(exitAction, SIGNAL(triggered()), SLOT(quit()));
    trayIcon = new QSystemTrayIcon(icon, this);
    trayIcon->setContextMenu(menu);
    trayIcon->setToolTip("Qt Pomodoro");
}

void MyApplication::showTrayIcon() {
    trayIcon->show();
}

void MyApplication::showOrHideWindow() {
    if (mainWindow != nullptr && mainWindow->isVisible()) {
        mainWindow->hide();
        showHideAction->setText("Show");
    } else {
        if (mainWindow == nullptr) {
            mainWindow = new MainWindow();
        }
        mainWindow->show();
        showHideAction->setText("Hide");
    }
}

void MyApplication::doBreak() {
    qDebug() << "Start break...";

    QPixmap pixmap(32, 32);
    pixmap.load("://images/tray_break.png");
    QIcon icon(pixmap);
    trayIcon->setIcon(icon);
}
