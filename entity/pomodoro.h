#ifndef POMODORO_H
#define POMODORO_H

#include <QObject>
#include <QTimer>

class State;
class StateWaitingToRun;
class StateWaitingToBreak;
class StateRunning;
class StateBreakRunning;

class Pomodoro: public QObject
{
    Q_OBJECT

public:
    Pomodoro(QObject* parent = nullptr);

public slots:
    void goNextState();
    void update();
    void start();
    void stop();
    void handleMainAction();
    void skipToNext();

public:
    QString getMainActionIcon();
    QString getBackgroundColor();
    State* getState();

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
    QTimer* timer = nullptr;
    qint64 timeToFinish = 0;
    State* state = nullptr;


    friend class StateWaitingToRun;
    friend class StateWaitingToBreak;
    friend class StateRunning;
    friend class StateBreakRunning;
};


#endif // POMODORO_H
