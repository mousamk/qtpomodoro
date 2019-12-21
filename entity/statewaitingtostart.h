#ifndef STATEWAITINGTOSTART_H
#define STATEWAITINGTOSTART_H

#include "state.h"


class StateWaitingToStart : public State
{
public:
    StateWaitingToStart(Pomodoro* pomodoro);
    void goNextState() override;
    void handleMainAction() override;
    void skipToNext() override;
    QString getMainActionText() override;
    QString getMainActionIcon() override;
    QString getBackgroundColor() override;
    QString getIconPath() override;
};

#endif // STATEWAITINGTOSTART_H
