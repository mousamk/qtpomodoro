#include <QDebug>
#include "myapplication.h"
#include "ui/mainwindow.h"
#include "entity/state.h"


MyApplication* MyApplication::instance = nullptr;


MyApplication* MyApplication::getInstance()
{
    return instance;
}

MyApplication::MyApplication(int &argc, char** argv)
    : QApplication (argc, argv)
{
    instance = this;
    setupSystemTray();
}

void MyApplication::setupSystemTray()
{
    setupMenuActions();
    buildSystemTrayIcon();
}

QIcon MyApplication::getIconForTray(QString path)
{
    QPixmap pixmap(32, 32);
    pixmap.load(path);
    return QIcon(pixmap);
}

void MyApplication::buildSystemTrayIcon()
{
    QIcon icon = getIconForTray("://images/tray.png");
    trayIcon = new QSystemTrayIcon(icon, this);
    trayIcon->setContextMenu(trayMenu);
    trayIcon->setToolTip("Qt Pomodoro");
}

void MyApplication::setupMenuActions()
{
    showHideAction = trayMenu->addAction("Show");
    connect(showHideAction, SIGNAL(triggered()), SLOT(showOrHideWindow()));

    QAction* exitAction = trayMenu->addAction("Exit");
    connect(exitAction, SIGNAL(triggered()), SLOT(quit()));
}

void MyApplication::showTrayIcon()
{
    trayIcon->show();
}

void MyApplication::showOrHideWindow()
{
    if (mainWindow && mainWindow->isVisible()) {
        mainWindow->hide();
        showHideAction->setText("Show");
    } else {
        if (!mainWindow) {
            initMainWindow();
        }
        mainWindow->show();
        showHideAction->setText("Hide");
    }
}

void MyApplication::initMainWindow()
{
    mainWindow = new MainWindow();
    connect(mainWindow, &MainWindow::statusChanged, this, [this](State* state){
        QIcon icon = getIconForTray(state->getIconPath());
        trayIcon->setIcon(icon);
    });
}

void MyApplication::doBreak()
{
    qDebug() << "Start break...";

    QPixmap pixmap(32, 32);
    pixmap.load("://images/tray_break.png");
    QIcon icon(pixmap);
    trayIcon->setIcon(icon);
}
