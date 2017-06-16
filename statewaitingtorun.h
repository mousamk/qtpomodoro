#ifndef STATEWAITINGTORUN_H
#define STATEWAITINGTORUN_H

#include "state.h"


class StateWaitingToRun : public State
{
public:
    StateWaitingToRun(Pomodoro* pomorodo);
    void goNextState();
    void handleMainAction();
    QString getMainActionText();
    QString getBackgroundColor();
};

#endif // STATEWAITINGTORUN_H
