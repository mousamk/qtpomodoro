#ifndef STATERUNNING_H
#define STATERUNNING_H

#include "state.h"


class StateRunning : public State
{
public:
    StateRunning(Pomodoro* pomodoro);
    void goNextState() override;
    void handleMainAction() override;
    void skipToNext() override;
    QString getMainActionText() override;
    QString getMainActionIcon() override;
    QString getBackgroundColor() override;
    QString getIconPath() override;
};

#endif // STATERUNNING_H
