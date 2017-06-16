#include "pomodoro.h"
#include "settings.h"


Pomodoro::Pomodoro(QObject* parent) : QObject(parent)
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
    connect(timer, SIGNAL(timeout()), this, SLOT(timerTimeout()));
}

void Pomodoro::changeStatus(PomodoroStatus newStatus)
{
    status = newStatus;
    emit statusChanged(newStatus);
}

void Pomodoro::start()
{
    timer->stop();
    roundsDone = 0;
    startRun();
}

void Pomodoro::stop()
{
    timer->stop();
    roundsDone = 0;
    emit timeUpdated(Settings::getInstance()->loadPomodoroRunMinutes(), 0);
    changeStatus(WaitingToRun);
}

bool Pomodoro::isRunning()
{
    return status != WaitingToStart;
}

PomodoroStatus Pomodoro::getStatus()
{
    return status;
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

int Pomodoro::nextBreakMinutes()
{
    Settings* settings = Settings::getInstance();
    bool isLong = roundsDone % settings->loadPomodoroRunCounts() == 0;
    return isLong ? settings->loadPomodoroLongBreakMinutes() : settings->loadPomodoroBreakMinutes();
}

void Pomodoro::finishBreak()
{
    //...
}

void Pomodoro::timerTimeout()
{
    //...
}
