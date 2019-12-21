#ifndef BREAKRUNNING_H
#define BREAKRUNNING_H

#include "state.h"


class StateBreakRunning : public State
{
public:
    StateBreakRunning(Pomodoro* pomodoro);
    void goNextState() override;
    void handleMainAction() override;
    void skipToNext() override;
    QString getMainActionText() override;
    QString getMainActionIcon() override;
    QString getBackgroundColor() override;
    QString getIconPath() override;
};

#endif // BREAKRUNNING_H
