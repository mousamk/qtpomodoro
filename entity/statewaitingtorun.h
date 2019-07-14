#ifndef STATEWAITINGTORUN_H
#define STATEWAITINGTORUN_H

#include "state.h"


class StateWaitingToRun : public State
{
public:
    StateWaitingToRun(Pomodoro* pomorodo);
    void goNextState();
    void handleMainAction();
    void skipToNext();
    QString getMainActionText();
    QString getBackgroundColor();
    QString getIconPath();
};

#endif // STATEWAITINGTORUN_H
