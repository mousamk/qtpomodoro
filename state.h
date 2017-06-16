#ifndef STATE_H
#define STATE_H

#include <QObject>


class Pomodoro;


class State : public QObject
{
    Q_OBJECT


public:
    explicit State(Pomodoro* pomodoro);
    void goNextState() = 0;
    void handleMainAction() = 0;
    QString getMainActionText() = 0;
    QString getBackgroundColor() = 0;



private:
    Pomodoro* pomodoro;
};

#endif // STATE_H
