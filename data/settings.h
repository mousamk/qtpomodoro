#ifndef SETTINGS_H
#define SETTINGS_H

#include <QSettings>
#include <QByteArray>


class Settings
{
public:
    static Settings* getInstance();
    void saveMainWindowGeometry(QByteArray);
    void saveMainWindowState(QByteArray);
    QByteArray loadMainWindowGeometry();
    QByteArray loadMainWindowState();
    int loadPomodoroRunMinutes();
    int loadPomodoroRunCounts();
    int loadPomodoroBreakMinutes();
    int loadPomodoroLongBreakMinutes();
    void savePomodoroRunMinutes(int);
    void savePomodoroRunCounts(int);
    void savePomodoroBreakMinutes(int);
    void savePomodoroLongBreakMinutes(int);


private:
    Settings();


private:
    static Settings* instance;
    QSettings* settings;
};

#endif // SETTINGS_H
