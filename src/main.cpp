#include <iostream>
#include "Transducer.h"
#include "Minimal.h"
#include "StateSignature.h"

int main() {
    Transducer t;
    
    t.addState(true);
    t.addState(true);

    t.addTransition(0, 'a', 0);
    t.addTransition(0, 'b', 0);
    t.addTransition(0, 'c', 1);
    t.addTransition(1, 'a', 1);
    t.addTransition(1, 'b', 1);
    t.addTransition(1, 'c', 1);

    t.addOutput(0, 'a', 2);
    t.addOutput(0, 'b', 3);
    t.addOutput(0, 'c', 0);
    t.addOutput(1, 'a', 0);
    t.addOutput(1, 'b', 0);
    t.addOutput(1, 'c', 0);

    t.setPsi(1, 100);
    
    StateSignature sign0(t, 0);
    StateSignature sign1(t, 1);

    sign0.print();
    sign1.print();

    return 0;
}