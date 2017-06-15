#include "pomodoro.h"


Pomodoro::Pomodoro(const QParent* parent) : QObject(parent)
{
}

void Pomodoro::changeStatus(PomodoroStatus newStatus)
{
    status = newStatus;
    emit statusChanged(newStatus);
}
