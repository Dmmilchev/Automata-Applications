#include "Lambda.h"

void Lambda::addOutput(State from, const Letter c, Nat out)  {
    outputs[from][c] = out;
}

void Lambda::removeOutput(State from, Letter c)  {
    outputs[from].erase(c);
    if (outputs[from].empty())
        outputs.erase(from);
}

Nat Lambda::output(State from, Letter c) {
    if (outputs.count(from) == 0 || outputs[from].count(c) == 0)
        return NotNat;
    else 
        return outputs[from][c];
}