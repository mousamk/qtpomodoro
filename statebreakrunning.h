#ifndef BREAKRUNNING_H
#define BREAKRUNNING_H

#include "state.h"


class StateBreakRunning : public State
{
public:
    StateBreakRunning(Pomodoro* pomodoro);
    void goNextState();
    void handleMainAction();
    void skipToNext();
    QString getMainActionText();
    QString getBackgroundColor();
};

#endif // BREAKRUNNING_H
