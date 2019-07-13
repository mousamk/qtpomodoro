#ifndef MYAPPLICATION_H
#define MYAPPLICATION_H

#include <QApplication>
#include <QtWidgets/QSystemTrayIcon>
#include <QtWidgets/QSystemTrayIcon>


class MyApplication : public QApplication
{
    Q_OBJECT

private:
    QSystemTrayIcon* trayIcon;

public:
    MyApplication(int &argc, char** argv);
    void showTrayIcon();

public Q_SLOTS:
    void doBreak();
};

#endif // MYAPPLICATION_H
