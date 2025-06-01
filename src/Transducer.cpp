#include <iostream>
#include <cassert>
#include "Transducer.h"
#include "macros.h"

void Transducer::setIota(Nat iota) {
    this->iota = iota;
}

void Transducer::setPsi(State q, Nat out) {
    psi[q] = out;
}

void Transducer::removePsi(State q) {
    psi.erase(q);
}

void Transducer::addState(bool isFinal) {
    stateMax++;
    statesCount++;
    if (isFinal)
        finalStates.insert(stateMax);
}

void Transducer::removeState(State q) {
    if (statesCount == 0)
        throw std::logic_error("Removing state from empty transducer.");

    if (q == stateMax) 
        stateMax--;
    else
        deletedStates.insert(q);

    if (finalStates.count(q) == 1)
        finalStates.erase(q);

    statesCount--;
}

void Transducer::addTransition(State from, Letter c, State to) {
    delta.addTransition(from, c, to);
}

void Transducer::removeTransition(State from, Letter c) {
    delta.removeTransition(from, c);
}

void Transducer::addOutput(State from, Letter c, Nat output) {
    lambda.addOutput(from, c, output);
}

void Transducer::removeOutput(State from, Letter c) {
    lambda.removeOutput(from, c);
}

Nat Transducer::traverse(const Letter* word) {
    Nat res = iota;
    State curr = 0;

    for (int i = 0; word[i] != '\0'; ++i) {
        Nat out = lambda.output(curr, word[i]);
        res += out;
        curr = delta.next(curr, word[i]);
        if (curr == NotState)
            return NotNat;

        // if transition is defined, output should also be defined
        assert(out != NotNat);  
    }

    if (finalStates.find(curr) != finalStates.end())
        return res + psi[curr];
    else   
        return NotNat;
}