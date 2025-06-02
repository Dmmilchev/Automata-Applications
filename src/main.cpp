#include <iostream>
#include "Transducer.h"
#include "Minimal.h"

int main() {
    Transducer t1 = createInitialTransducer("abcdabca", 10);
    std::cout << t1.statesCount << " " <<t1.stateMax << std::endl;

    Transducer t2 = createInitialTransducer("", 10);
    std::cout << t2.statesCount << " " <<t2.stateMax << std::endl;

    Transducer t3 = createInitialTransducer("aaaa", 10);
    std::cout << t3.statesCount << " " <<t3.stateMax << std::endl;

    return 0;
}