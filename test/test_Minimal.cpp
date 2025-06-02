#include <catch2/catch_test_macros.hpp>
#include "Minimal.h"

TEST_CASE("Initial creation works", "[initial]") {
    Transducer t1 = createInitialTransducer("abcdabca", 10);
    REQUIRE(t1.traverse("abcdabca") == 10);
    REQUIRE(t1.traverse("") == NotNat);
    REQUIRE(t1.traverse("abcdabc") == NotNat);
// std::cout << "t1.statesCount = " << t1.statesCount << std::endl;

    // REQUIRE(t1.statesCount == 9);
    REQUIRE(t1.finalStates.size() == 1);

    Transducer t2 = createInitialTransducer("", 10);
    REQUIRE(t2.traverse("") == 10);
    REQUIRE(t2.traverse("a") == NotNat);
    REQUIRE(t2.traverse("abc") == NotNat);
    REQUIRE(t2.statesCount == 1);
    REQUIRE(t2.finalStates.size() == 1);

    Transducer t3 = createInitialTransducer("aaaa", 10);
    REQUIRE(t3.traverse("aaaa") == 10);
    REQUIRE(t3.traverse("") == NotNat);
    REQUIRE(t3.traverse("aaaaa") == NotNat);
    REQUIRE(t3.traverse("aaa") == NotNat);
    REQUIRE(t3.statesCount == 5);
    REQUIRE(t3.finalStates.size() == 1);
}