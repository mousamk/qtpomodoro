#ifndef BREAKRUNNING_H
#define BREAKRUNNING_H

#include "state.h"


class StateBreakRunning : public State
{
public:
    StateBreakRunning(Pomorodo* pomodoro);
    void goNextState();
    void handleMainAction();
    QString getMainActionText();
    QString getBackgroundColor();
};

#endif // BREAKRUNNING_H
