#include "statewaitingtostart.h"
#include "pomodoro.h"


StateWaitingToStart::StateWaitingToStart(Pomodoro* pomodoro) : State(pomodoro)
{
}

void StateWaitingToStart::goNextState()
{
    pomodoro->startRun();
}

void StateWaitingToStart::handleMainAction()
{
    goNextState();
}

void StateWaitingToStart::skipToNext()
{
    pomodoro->finishRun();
}

QString StateWaitingToStart::getMainActionText()
{
    return "Start";
}

QString StateWaitingToStart::getMainActionIcon()
{
    return "://images/play.png";
}

QString StateWaitingToStart::getBackgroundColor()
{
    return "#FF0000";
}

QString StateWaitingToStart::getIconPath()
{
    return "://images/tray.png";
}
