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

QString StateWaitingToStart::getMainActionText()
{
    return "Start";
}

QString StateWaitingToStart::getBackgroundColor()
{
    return "#FFFFFF";
}
