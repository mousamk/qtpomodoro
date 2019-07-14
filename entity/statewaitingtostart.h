#ifndef STATEWAITINGTOSTART_H
#define STATEWAITINGTOSTART_H

#include "state.h"


class StateWaitingToStart : public State
{
public:
    StateWaitingToStart(Pomodoro* pomodoro);
    void goNextState();
    void handleMainAction();
    void skipToNext();
    QString getMainActionText();
    QString getBackgroundColor();
    QString getIconPath();
};

#endif // STATEWAITINGTOSTART_H
