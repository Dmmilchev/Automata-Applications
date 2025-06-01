#pragma once

#include <iostream>
#include "macros.h"

class IDelta {
public:
    virtual void addTransition(State from, const Letter c, State to) = 0;
    virtual void removeTransition(State from, Letter c) = 0;
    virtual State next(State from, Letter c) = 0;
};