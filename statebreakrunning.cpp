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

QString StateBreakRunning::getMainActionText()
{
    return "Stop";
}

QString StateBreakRunning::getBackgroundColor()
{
    return "#00FF00";
}
