#include <iostream>
#include "Transducer.h"

int main() {
    Transducer t;
    t.addState(true);
    t.setIota(0);
    t.addTransition(0, 'a', 0);
    t.addTransition(0, 'b', 0);

    t.addOutput(0, 'a', 1);
    t.addOutput(0, 'b', 0);

    std::cout << t.traverse("bbb") << std::endl;
    std::cout << t.traverse("aaa") << std::endl;
    std::cout << t.traverse("abbbaaaaaab") << std::endl;
    std::cout << t.traverse("aaca") << std::endl;

    return 0;
}