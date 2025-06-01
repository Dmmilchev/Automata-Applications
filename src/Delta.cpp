#include <iostream>
#include "Delta.h"

void Delta::addTransition(State from, const Letter c, State to)  {
    transitions[from][c] = to;
}

void Delta::removeTransition(State from, Letter c)  {
    transitions[from].erase(c);
    if (transitions[from].empty())
        transitions.erase(from);
}

State Delta::next(State from, Letter c) {
    if (transitions.count(from) == 0 || transitions[from].count(c) == 0)
        return NotState;
    else 
        return transitions[from][c];
}