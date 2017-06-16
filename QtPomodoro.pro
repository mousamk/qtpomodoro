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
    state.cpp

HEADERS  += mainwindow.h \
    settings.h \
    status.h \
    pomodoro.h \
    state.h

FORMS    += mainwindow.ui
