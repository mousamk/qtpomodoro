#include "pomodoro.h"
#include "settings.h"
#include <QDebug>
#include <QDateTime>
#include "statewaitingtostart.h"


Pomodoro::Pomodoro(QObject* parent) : QObject(parent)
{
    initTimer();
    initState();
    setupConnections();
}

void Pomodoro::initTimer()
{
    timer = new QTimer(this);
}

void Pomodoro::initState()
{
    state = new StateWaitingToStart(this);
}

void Pomodoro::setupConnections()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
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

void Pomodoro::handleMainAction()
{
    state->handleMainAction();
}

QString Pomodoro::getMainActionText()
{
    return state->getMainActionText();
}

QString Pomodoro::getBackgroundColor()
{
    return state->getBackgroundColor();
}

void Pomodoro::goNextState()
{
    state->goNextState();
}

void Pomodoro::startRun()
{
    timer->start(1000);
    changeStatus(Running);
    finishTime = QDateTime::currentMSecsSinceEpoch()/1000 + Settings::getInstance()->loadPomodoroRunMinutes()*60;
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
    changeStatus(BreakRunning);
    finishTime = QDateTime::currentMSecsSinceEpoch()/1000 + nextBreakMinutes()*60;
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
    qint64 now = QDateTime::currentMSecsSinceEpoch() / 1000;
    qint64 rem = finishTime - now;
    if (rem <= 0)
        goNextState();
    else {
        int min = rem / 60;
        int sec = rem % 60;
        emit timeUpdated(min, sec);
    }
}
