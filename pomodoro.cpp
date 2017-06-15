#include "pomodoro.h"


Pomodoro::Pomodoro(const QParent* parent) : QObject(parent)
{
    initTimer();
    setupConnections();
}

void Pomodoro::initTimer()
{
    timer = new QTimer(this);
}

void Pomodoro::setupConnections()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(timerTimeout());
}

void Pomodoro::changeStatus(PomodoroStatus newStatus)
{
    status = newStatus;
    emit statusChanged(newStatus);
}

void Pomodoro::goNextState()
{
    switch (status)
    {
    case WaitingToStart:
    case WaitingToRun:
        startRun();
        break;
    case Running:
        finishRun();
        break;
    case WaitingToBreak:
        startBreak();
        break;
    case BreakRunning:
        finishBreak();
        break;
    }
}

void Pomodoro::startRun()
{
    //...
}

void Pomodoro::finishRun()
{
    //...
}

void Pomodoro::startBreak()
{
    //...
}

void Pomodoro::finishRun()
{
    //...
}

void Pomodoro::timerTimeout()
{
    //...
}
