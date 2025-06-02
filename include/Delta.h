#pragma once
#include <iostream>
#include <unordered_map>
#include "macros.h"
#include "IDelta.h"

struct Delta : public IDelta {
    std::unordered_map<State, std::unordered_map<Letter, State>> transitions;

    void addTransition(State from, const Letter c, State to) override;
    void removeTransition(State from, Letter c) override;
    State next(State from, Letter c) override;
};