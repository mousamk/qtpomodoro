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

QString StateWaitingToStart::getBackgroundColor()
{
    return "#FFFFFF";
}
