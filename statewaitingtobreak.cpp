#include "statewaitingtobreak.h"
#include "pomodoro.h"


StateWaitingToBreak::StateWaitingToBreak(Pomodoro* pomodoro) : State(pomodoro)
{
}

void StateWaitingToBreak::goNextState()
{
    pomodoro->startBreak();
}

void StateWaitingToBreak::handleMainAction()
{
    goNextState();
}

QString StateWaitingToBreak::getMainActionText()
{
    return "Break";
}

QString StateWaitingToBreak::getBackgroundColor()
{
    return "#00FF00";
}
