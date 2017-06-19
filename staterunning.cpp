#include "staterunning.h"
#include "pomodoro.h"


StateRunning::StateRunning(Pomodoro* pomodoro) : State(pomodoro)
{
}

void StateRunning::goNextState()
{
    pomodoro->finishRun();
}

void StateRunning::handleMainAction()
{
    pomodoro->stop();
}

void StateRunning::skipToNext()
{
    goNextState();
}

QString StateRunning::getMainActionText()
{
    return "Stop";
}

QString StateRunning::getBackgroundColor()
{
    return "#FF0000";
}
