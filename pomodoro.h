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
    PomodoroStatus getStatus();


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
    qint64 startTime = 0;
};


#endif // POMODORO_H
