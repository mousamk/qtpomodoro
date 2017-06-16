#ifndef POMODORO_H
#define POMODORO_H

#include <QObject>
#include <QTimer>
#include "status.h"


class State;


class Pomodoro: public QObject
{
    Q_OBJECT


public:
    Pomodoro(QObject* parent = NULL);
    bool isRunning();
    PomodoroStatus getStatus();
    State* getState();


public slots:
    void goNextState();
    void update();
    void start();
    void stop();


private:
    void initTimer();
    void setupConnections();
    void changeStatus(PomodoroStatus);
    void startRun();
    void finishRun();
    void startBreak();
    void finishBreak();
    int nextBreakMinutes();


signals:
    void statusChanged(PomodoroStatus);
    void timeUpdated(int min, int sec);


private:
    PomodoroStatus status = WaitingToStart;
    int roundsDone = 0;
    QTimer* timer = NULL;
    qint64 startTime = 0;
    State* state = NULL;


    friend class State;
};


#endif // POMODORO_H
