#ifndef POMODORO_H
#define POMODORO_H

#include <QObject>
#include <QTimer>
#include "status.h"


class Pomodoro: public QObject
{
    Q_OBJECT


public:
    Pomodoro(QObject* parent = NULL);
    bool isRunning();


public slots:
    void goNextState();
    void timerTimeout();


private:
    void initTimer();
    void setupConnections();
    void changeStatus(PomodoroStatus);
    void startRun();
    void finishRun();
    void startBreak();
    void finishBreak();


signals:
    void statusChanged(PomodoroStatus);
    void timeUpdated(int min, int sec);


private:
    PomodoroStatus status = WaitingToStart;
    int roundsDone = 0;
    QTimer* timer = NULL;
};


#endif // POMODORO_H
