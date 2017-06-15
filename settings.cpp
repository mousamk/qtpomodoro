#include "settings.h"


Settings* Settings::instance = NULL;


Settings::Settings()
{
    settings = new QSettings("MousaTools", "QtPomodoro");
}

Settings* Settings::getInstance()
{
    if (NULL == instance)
        instance = new Settings();
    return instance;
}

void Settings::saveMainWindowGeometry(QByteArray data)
{
    settings->setValue("mainwindow_geometry", data);
}

void Settings::saveMainWindowState(QByteArray data)
{
    settings->setValue("mainwindow_state", data);
}

QByteArray Settings::loadMainWindowGeometry()
{
    return settings->value("mainwindow_geometry").toByteArray();
}

QByteArray Settings::loadMainWindowState()
{
    return settings->value("mainwindow_state").toByteArray();
}
