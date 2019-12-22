#ifndef STATEWAITINGTORUN_H
#define STATEWAITINGTORUN_H

#include "state.h"


class StateWaitingToRun : public State
{
public:
    StateWaitingToRun(Pomodoro* pomorodo);
    void goNextState() override;
    void handleMainAction() override;
    void skipToNext() override;
    QString getMainActionIcon() override;
    QString getBackgroundColor() override;
    QString getIconPath() override;
};

#endif // STATEWAITINGTORUN_H
