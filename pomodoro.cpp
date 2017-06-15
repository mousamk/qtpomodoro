#include "pomodoro.h"


Pomodoro::Pomodoro(const QParent* parent) : QObject(parent)
{
}

void Pomodoro::changeStatus(PomodoroStatus newStatus)
{
    status = newStatus;
    emit statusChanged(newStatus);
}

void Pomodoro::nextStatus()
{
    //Go to the next state.
}
