#ifndef MYAPPLICATION_H
#define MYAPPLICATION_H

#include <QApplication>
#include <QtWidgets/QSystemTrayIcon>
#include <QtWidgets/QSystemTrayIcon>
#include <QtWidgets/QAction>
#include <QMenu>

class MainWindow;
class SettingsDialog;


class MyApplication : public QApplication
{
    Q_OBJECT

private:
    QSystemTrayIcon* trayIcon;
    MainWindow* mainWindow = nullptr;
    SettingsDialog* settingsDialog = nullptr;
    QAction* showHideAction = nullptr;
    QMenu* trayMenu = new QMenu();

public:
    static MyApplication* getInstance();
    MyApplication(int &argc, char** argv);
    void showTrayIcon();

private:
    void setupSystemTray();
    void setupMenuActions();
    void setupShowHideAction();
    void setupExitAction();
    void setupSettingsAction();
    QIcon getIconForTray(QString);
    void buildSystemTrayIcon();
    void initMainWindow();

public Q_SLOTS:
    void doBreak();
    void showOrHideWindow();

private:
    static MyApplication* instance;
};

#endif // MYAPPLICATION_H
