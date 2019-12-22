#include "statebreakrunning.h"
#include "pomodoro.h"


StateBreakRunning::StateBreakRunning(Pomodoro* pomodoro) : State(pomodoro)
{
}

void StateBreakRunning::goNextState()
{
    pomodoro->finishBreak();
}

void StateBreakRunning::handleMainAction()
{
    pomodoro->stop();
}

void StateBreakRunning::skipToNext()
{
    goNextState();
}

QString StateBreakRunning::getMainActionIcon()
{
    return "://images/pause.png";
}

QString StateBreakRunning::getBackgroundColor()
{
    return "#55FF55";
}

QString StateBreakRunning::getIconPath()
{
    return "://images/tray_break.png";
}
