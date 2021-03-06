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
        mainwindow.cpp \
    settings.cpp \
    pomodoro.cpp \
    state.cpp \
    statewaitingtostart.cpp \
    staterunning.cpp \
    statewaitingtobreak.cpp \
    statebreakrunning.cpp \
    statewaitingtorun.cpp

HEADERS  += mainwindow.h \
    settings.h \
    pomodoro.h \
    state.h \
    statewaitingtostart.h \
    staterunning.h \
    statewaitingtobreak.h \
    statebreakrunning.h \
    statewaitingtorun.h

FORMS    += mainwindow.ui
