#ifndef STATE_H
#define STATE_H

#include <QObject>


class Pomodoro;


class State : public QObject
{
    Q_OBJECT


public:
    explicit State(Pomodoro* pomodoro);
    virtual void goNextState() = 0;
    virtual void handleMainAction() = 0;
    virtual QString getMainActionText() = 0;
    virtual QString getBackgroundColor() = 0;



private:
    Pomodoro* pomodoro;
};

#endif // STATE_H
