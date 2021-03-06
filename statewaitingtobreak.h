#ifndef STATEWAITINGTOBREAK_H
#define STATEWAITINGTOBREAK_H

#include "state.h"


class StateWaitingToBreak : public State
{
public:
    StateWaitingToBreak(Pomodoro* pomodoro);
    void goNextState();
    void handleMainAction();
    QString getMainActionText();
    QString getBackgroundColor();
};

#endif // STATEWAITINGTOBREAK_H
