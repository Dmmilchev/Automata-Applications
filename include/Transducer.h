#pragma once

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include "Delta.h"
#include "Lambda.h"

struct Transducer {
// Class implementation of a subsequential transducer with initial output

    // inSigma is char
    // outSigma is Nat
    // states are State
    
    uint32_t statesCount = 0;
    uint32_t stateMax = UINT32_MAX;
    // std::unordered_set<State> deletedStates;  // used when removing word from language
    // initial state is 0

    std::unordered_set<State> finalStates;
    Delta delta;
    Lambda lambda;
    Nat iota = 0;
    std::unordered_map<State, Nat> psi;


    void setIota(Nat iota);
    void setPsi(State q, Nat out);
    void removePsi(State q);

    void addState(bool isFinal);
    // void removeState(State q);

    void addTransition(State from, Letter c, State to);
    void removeTransition(State from, Letter c);

    void addOutput(State from, Letter c, Nat output);
    void removeOutput(State from, Letter c);

    Nat traverse(const Letter* word);
};