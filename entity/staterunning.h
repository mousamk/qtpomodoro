#ifndef STATERUNNING_H
#define STATERUNNING_H

#include "state.h"


class StateRunning : public State
{
public:
    StateRunning(Pomodoro* pomodoro);
    void goNextState();
    void handleMainAction();
    void skipToNext();
    QString getMainActionText();
    QString getBackgroundColor();
    QString getIconPath();
};

#endif // STATERUNNING_H
