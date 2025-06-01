#include <catch2/catch_test_macros.hpp>
#include "Delta.h"
#include "macros.h"

TEST_CASE("Delta works", "[delta]") {
    Delta d;
    d.addTransition(1, 'c', 2);
    d.addTransition(2, 'b', 4);

    REQUIRE(d.next(1, 'c') == 2);
    REQUIRE(d.next(2, 'b') == 4);
    REQUIRE(d.next(3, 'a') == NotState);
    REQUIRE(d.next(1, 'b') == NotState);

    d.removeTransition(1, 'c');
    d.removeTransition(2, 'b');
    REQUIRE(d.next(1, 'c') == NotState);
    REQUIRE(d.next(2, 'b') == NotState);
}