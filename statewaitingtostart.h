#ifndef STATEWAITINGTOSTART_H
#define STATEWAITINGTOSTART_H

#include "state.h"


class StateWaitingToStart : public State
{
public:
    StateWaitingToStart(Pomodoro* pomodoro);
    void goNextState();
    void handleMainAction();
    QString getMainActionText();
    QString getBackgroundColor();
};

#endif // STATEWAITINGTOSTART_H
