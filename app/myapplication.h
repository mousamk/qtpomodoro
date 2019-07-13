#ifndef MYAPPLICATION_H
#define MYAPPLICATION_H

#include <QApplication>
#include <QtWidgets/QSystemTrayIcon>
#include <QtWidgets/QSystemTrayIcon>
#include <QtWidgets/QAction>

class MainWindow;


class MyApplication : public QApplication
{
    Q_OBJECT

private:
    QSystemTrayIcon* trayIcon;
    MainWindow* mainWindow = nullptr;
    QAction* showHideAction = nullptr;

public:
    static MyApplication* getInstance();
    MyApplication(int &argc, char** argv);
    void showTrayIcon();

public Q_SLOTS:
    void doBreak();
    void showOrHideWindow();

private:
    static MyApplication* instance;
};

#endif // MYAPPLICATION_H
