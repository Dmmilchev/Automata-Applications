#include <catch2/catch_test_macros.hpp>
#include "StateSignature.h"
#include <set>

TEST_CASE("State Signature works", "[ss]") {
    Transducer t;
    t.addState(false);
    t.addState(false);
    t.addState(false);
    t.addState(true);
    t.addState(false);
    t.addState(false);
    t.addState(true);

    t.addTransition(0, 'a' ,1); t.addOutput(0, 'a', 1);
    t.addTransition(1, 'a', 2); t.addOutput(1, 'a', 1);
    t.addTransition(2, 'b', 3); t.addOutput(2, 'b', 2);
    t.addTransition(0, 'c', 4); t.addOutput(0, 'c', 5);
    t.addTransition(0, 'd', 5); t.addOutput(0, 'd', 10);
    t.addTransition(0, 'e', 6); t.addOutput(0, 'e', 0);
    t.addTransition(4, 'b', 1); t.addOutput(4, 'b', 4);
    t.addTransition(4, 'a', 3); t.addOutput(4, 'a', 3);
    t.addTransition(5, 'b', 1); t.addOutput(5, 'b', 4);
    t.addTransition(5, 'a', 3); t.addOutput(5, 'a', 3);

    t.setPsi(3, 5); t.setPsi(6, 5);
    
    std::vector<StateSignature> signs;
    for (int i = 0; i < 7; ++i) {
        signs.push_back(StateSignature(t, i));
    }

    REQUIRE(signs[4] == signs[5]);
    REQUIRE(signs[6] == signs[3]);

    std::set<StateSignature> s;
    for (auto el : signs) 
        s.insert(el);

    REQUIRE(s.size() == 5);
    for (int i = 0; i < 5; ++i)
        REQUIRE(s.find(signs[i]) != s.end());
}