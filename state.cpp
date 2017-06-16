#include "state.h"
#include "pomodoro.h"


State::State(Pomodoro* pomodoro) : QObject(pomodoro)
{
    this->pomodoro = pomodoro;
}

