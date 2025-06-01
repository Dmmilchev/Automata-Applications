#include <catch2/catch_test_macros.hpp>
#include "Transducer.h"

TEST_CASE("Transducer works 1", "[transducer]") {
    Transducer t;
    t.addState(true);
    t.addTransition(0, 'a', 0);
    t.addTransition(0, 'b', 0);

    t.addOutput(0, 'a', 1);
    t.addOutput(0, 'b', 0);

    REQUIRE(t.traverse("bbb") == 0);
    REQUIRE(t.traverse("aaa") == 3);
    REQUIRE(t.traverse("abbbaaaaaab") == 7);
    REQUIRE(t.traverse("aaccaa") == NotNat);
    REQUIRE(t.traverse("") == 0);
}

TEST_CASE("Transducer works 2", "[transducer]") {
    Transducer t;
    t.addState(true);
    t.setIota(3);
    t.addTransition(0, 'a', 0);
    t.addTransition(0, 'b', 0);
    t.setPsi(0, 5);

    t.addOutput(0, 'a', 1);
    t.addOutput(0, 'b', 0);

    REQUIRE(t.traverse("bbb") == 8);
    REQUIRE(t.traverse("aaa") == 11);
    REQUIRE(t.traverse("abbbaaaaaab") == 15);
    REQUIRE(t.traverse("aaccaa") == NotNat);
    REQUIRE(t.traverse("") == 8);
}

TEST_CASE("Transducer works 3", "[transducer]") {
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
    
    SECTION("Empty string returns 0") {
        REQUIRE(t.traverse("") == 0);
    }

    SECTION("Not in language") {
        REQUIRE(t.traverse("xycz") == NotNat);
        REQUIRE(t.traverse("xaybz") == NotNat);

    }

    SECTION("String with 'c' adds 100 once and after that nothing else matters") {
        REQUIRE(t.traverse("c") == 100);
        REQUIRE(t.traverse("abc") == 105);
        REQUIRE(t.traverse("cab") == 100);
    }

    SECTION("String without 'c' computes weighted sum of 'a's and 'b's") {
        REQUIRE(t.traverse("a") == 2);      // 2*1 + 3*0 = 2
        REQUIRE(t.traverse("b") == 3);      // 2*0 + 3*1 = 3
        REQUIRE(t.traverse("aa") == 4);     // 2*2 + 3*0 = 4
        REQUIRE(t.traverse("bb") == 6);     // 2*0 + 3*2 = 6
        REQUIRE(t.traverse("ab") == 5);     // 2*1 + 3*1 = 5
        REQUIRE(t.traverse("aab") == 7);    // 2*2 + 3*1 = 7
        REQUIRE(t.traverse("bba") == 8);    // 2*1 + 3*2 = 8
    }
}