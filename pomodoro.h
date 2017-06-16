#ifndef POMODORO_H
#define POMODORO_H

#include <QObject>
#include <QTimer>


class State;
class StateWaitingToStart;
class StateWaitingToRun;
class StateWaitingToBreak;
class StateRunning;
class StateBreakRunning;


class Pomodoro: public QObject
{
    Q_OBJECT


public:
    Pomodoro(QObject* parent = NULL);


public slots:
    void goNextState();
    void update();
    void start();
    void stop();
    void handleMainAction();
    QString getMainActionText();
    QString getBackgroundColor();


private:
    void initTimer();
    void initState();
    void setupConnections();
    void startRun();
    void finishRun();
    void startBreak();
    void finishBreak();
    int nextBreakMinutes();


signals:
    void statusChanged();
    void timeUpdated(int min, int sec);


private:
    int roundsDone = 0;
    QTimer* timer = NULL;
    qint64 finishTime = 0;
    State* state = NULL;


    friend class StateWaitingToStart;
    friend class StateWaitingToRun;
    friend class StateWaitingToBreak;
    friend class StateRunning;
    friend class StateBreakRunning;
};


#endif // POMODORO_H
