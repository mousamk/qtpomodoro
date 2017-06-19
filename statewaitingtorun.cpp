#include "statewaitingtorun.h"
#include "pomodoro.h"


StateWaitingToRun::StateWaitingToRun(Pomodoro* pomodoro) : State(pomodoro)
{
}

void StateWaitingToRun::goNextState()
{
    pomodoro->startRun();
}

void StateWaitingToRun::handleMainAction()
{
    goNextState();
}

void StateWaitingToRun::skipToNext()
{
    pomodoro->finishRun();
}

QString StateWaitingToRun::getMainActionText()
{
    return "Start";
}

QString StateWaitingToRun::getBackgroundColor()
{
    return "#FF0000";
}
