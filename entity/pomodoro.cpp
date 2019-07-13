#include "pomodoro.h"
#include "settings.h"
#include <QDebug>
#include <QDateTime>
#include "statewaitingtostart.h"
#include "staterunning.h"
#include "statebreakrunning.h"
#include "statewaitingtobreak.h"
#include "statewaitingtorun.h"


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
    emit statusChanged();
}

void Pomodoro::handleMainAction()
{
    state->handleMainAction();
}

void Pomodoro::skipToNext()
{
    state->skipToNext();
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
    finishTime = QDateTime::currentMSecsSinceEpoch()/1000 + Settings::getInstance()->loadPomodoroRunMinutes()*60;
    state = new StateRunning(this);
    emit statusChanged();
}

void Pomodoro::finishRun()
{
    timer->stop();
    state = new StateWaitingToBreak(this);
    roundsDone += 1;
    emit timeUpdated(nextBreakMinutes(), 0);
    emit statusChanged();
}

void Pomodoro::startBreak()
{
    timer->start();
    finishTime = QDateTime::currentMSecsSinceEpoch()/1000 + nextBreakMinutes()*60;
    state = new StateBreakRunning(this);
    emit statusChanged();
}

void Pomodoro::finishBreak()
{
    timer->stop();
    state = new StateWaitingToRun(this);
    emit timeUpdated(Settings::getInstance()->loadPomodoroRunMinutes(), 0);
    emit statusChanged();
}

int Pomodoro::nextBreakMinutes()
{
    Settings* settings = Settings::getInstance();
    bool isLong = roundsDone % settings->loadPomodoroRunCounts() == 0;
    return isLong ? settings->loadPomodoroLongBreakMinutes() : settings->loadPomodoroBreakMinutes();
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
