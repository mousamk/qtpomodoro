#ifndef STATEWAITINGTOBREAK_H
#define STATEWAITINGTOBREAK_H

#include "state.h"


class StateWaitingToBreak : public State
{
public:
    StateWaitingToBreak(Pomodoro* pomodoro);
    void goNextState();
    void handleMainAction();
    void skipToNext();
    QString getMainActionText();
    QString getBackgroundColor();
    QString getIconPath();
};

#endif // STATEWAITINGTOBREAK_H
