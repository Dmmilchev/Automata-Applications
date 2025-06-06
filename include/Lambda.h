#pragma once

#include <unordered_map>
#include "ILambda.h"


struct Lambda : public ILambda {
    std::unordered_map<State, std::unordered_map<Letter, Nat>> outputs;

    void addOutput(State from, const Letter c, Nat to) override;
    void removeOutput(State from, Letter c) override;
    Nat output(State from, Letter c) override;
};