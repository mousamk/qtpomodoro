#ifndef STATEWAITINGTOBREAK_H
#define STATEWAITINGTOBREAK_H

#include "state.h"


class StateWaitingToBreak : public State
{
public:
    StateWaitingToBreak(Pomodoro* pomodoro);
    void goNextState() override;
    void handleMainAction() override;
    void skipToNext() override;
    QString getMainActionIcon() override;
    QString getBackgroundColor() override;
    QString getIconPath() override;
};

#endif // STATEWAITINGTOBREAK_H
