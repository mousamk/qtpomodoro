#ifndef POMODORO_H
#define POMODORO_H

#include <QObject>
#include "status.h"


class Pomodoro: QObject
{
    Q_OBJECT


public:
    Pomodoro(const QObject* parent = NULL);


public slots:
    void goNextState();


private:
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
};


#endif // POMODORO_H
