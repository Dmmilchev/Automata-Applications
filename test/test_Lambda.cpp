#include <catch2/catch_test_macros.hpp>
#include "Lambda.h"

TEST_CASE("Lambda words", "[lambda]") {
    Lambda l;
    l.addOutput(1, 'c', 2);
    l.addOutput(2, 'b', 4);

    REQUIRE(l.output(1, 'c') == 2);
    REQUIRE(l.output(2, 'b') == 4);
    REQUIRE(l.output(3, 'a') == NotNat);
    REQUIRE(l.output(1, 'b') == NotNat);

    l.removeOutput(1, 'c');
    l.removeOutput(2, 'b');
    REQUIRE(l.output(1, 'c') == NotNat);
    REQUIRE(l.output(2, 'b') == NotNat);
}