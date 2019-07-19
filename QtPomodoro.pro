#-------------------------------------------------
#
# Project created by QtCreator 2017-06-16T01:08:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtPomodoro
TEMPLATE = app


SOURCES += main.cpp\
        app/myapplication.cpp \
        ui/settingsdialog.cpp \
        ui/mainwindow.cpp \
        data/settings.cpp \
        entity/pomodoro.cpp \
        entity/state.cpp \
        entity/statewaitingtostart.cpp \
        entity/staterunning.cpp \
        entity/statewaitingtobreak.cpp \
        entity/statebreakrunning.cpp \
        entity/statewaitingtorun.cpp

HEADERS  += ui/mainwindow.h \
        app/myapplication.h \
        data/settings.h \
        entity/pomodoro.h \
        entity/state.h \
        entity/statewaitingtostart.h \
        entity/staterunning.h \
        entity/statewaitingtobreak.h \
        entity/statebreakrunning.h \
        entity/statewaitingtorun.h \
        ui/settingsdialog.h

FORMS    += ui/mainwindow.ui \
        ui/settingsdialog.ui

RESOURCES += \
    res/resources.qrc

