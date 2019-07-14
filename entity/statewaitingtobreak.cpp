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

void StateWaitingToBreak::skipToNext()
{
    pomodoro->finishBreak();
}

QString StateWaitingToBreak::getMainActionText()
{
    return "Break";
}

QString StateWaitingToBreak::getBackgroundColor()
{
    return "#55FF55";
}

QString StateWaitingToBreak::getIconPath()
{
    return "://images/tray_break.png";
}
