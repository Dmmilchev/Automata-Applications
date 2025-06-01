#pragma once
#include <iostream>
#include "macros.h"

class ILambda {
public:
    virtual  void addOutput(State from, Letter c, Nat n) = 0;
    virtual void removeOutput(State from, Letter c) = 0;
    virtual Nat output(State from, Letter c) = 0;
};