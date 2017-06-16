#ifndef STATE_H
#define STATE_H


class Pomodoro;


class State : public QObject
{
    Q_OBJECT


public:
    explicit State(Pomodoro* pomodoro);
    void goNextState() = 0;


private:
    Pomodoro* pomodoro;
};

#endif // STATE_H
