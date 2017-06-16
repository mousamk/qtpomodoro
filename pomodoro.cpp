#include "pomodoro.h"
#include "settings.h"
#include <QDebug>
#include <QDateTime>


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
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
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

State* Pomodoro::getState()
{
    return state;
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
    timer->start(1000);
    startTime = QDateTime::currentMSecsSinceEpoch();
    changeStatus(Running);
}

void Pomodoro::finishRun()
{
    timer->stop();
    emit timeUpdated(nextBreakMinutes(), 0);
    changeStatus(WaitingToBreak);
}

void Pomodoro::startBreak()
{
    timer->start();
    startTime = QDateTime::currentMSecsSinceEpoch();
    changeStatus(BreakRunning);
}

int Pomodoro::nextBreakMinutes()
{
    Settings* settings = Settings::getInstance();
    bool isLong = roundsDone % settings->loadPomodoroRunCounts() == 0;
    return isLong ? settings->loadPomodoroLongBreakMinutes() : settings->loadPomodoroBreakMinutes();
}

void Pomodoro::finishBreak()
{
    timer->stop();
    emit timeUpdated(Settings::getInstance()->loadPomodoroRunMinutes(), 0);
    changeStatus(WaitingToRun);
}

void Pomodoro::update()
{
    qint64 now = QDateTime::currentMSecsSinceEpoch();
    qint64 elapsed = (now - startTime) / 1000;
    qint64 whole = Settings::getInstance()->loadPomodoroRunMinutes()*60;
    qint64 rem = whole - elapsed;
    if (rem <= 0)
        goNextState();
    else {
        int min = rem / 60;
        int sec = rem % 60;
        emit timeUpdated(min, sec);
    }
}
