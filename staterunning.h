#ifndef STATERUNNING_H
#define STATERUNNING_H

#include "state.h"


class StateRunning : public State
{
public:
    StateRunning(Pomodoro* pomodoro);
    void goNextState();
    void handleMainAction();
    QString getMainActionText();
    QString getBackgroundColor();
};

#endif // STATERUNNING_H
