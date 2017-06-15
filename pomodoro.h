#ifndef POMODORO_H
#define POMODORO_H

#include <QObject>
#include "status.h"


class Pomodoro: QObject
{
    Q_OBJECT


public:
    Pomodoro(const QObject* parent = NULL);


private:
    void changeStatus(PomodoroStatus);


signals:
    void statusChanged(PomodoroStatus);


private:
    PomodoroStatus status = WaitingToStart;
    int roundsDone = 0;
};


#endif // POMODORO_H
