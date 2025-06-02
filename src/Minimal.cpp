#include <iostream>
#include "macros.h"
#include "Transducer.h"

Transducer createInitialTransducer(const Letter* word, Nat output) {
    Transducer t;
    t.setIota(output);

    if (word[0] == '\0') {
        t.addState(true);
        return t;
    }
    else {
        t.addState(false);
    }
    
    int i;
    for (i = 0; word[i + 1] != '\0'; ++i) {
        t.addState(false);
        t.addTransition(t.stateMax - 1, word[i], t.stateMax);
        t.addOutput(t.stateMax - 1, word[i], 0);
    }
    t.addState(true);
    t.addTransition(t.stateMax - 1, word[i], t.stateMax);
    t.addOutput(t.stateMax - 1, word[i], 0);

    return t;
}