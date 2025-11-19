// Copyright (c) whippyunits contributors

#include <catch2/catch_test_macros.hpp>

#include <catch2/matchers/catch_matchers.hpp>
#include <whippyunits/quantity.hpp>
#include <whippyunits/concepts.hpp>
#include <whippyunits/dimensions/base.hpp>
//#include "catch_matchers.hpp"

using namespace whippyunits;

constexpr Scale base = Scale::_10(0);
constexpr Unit m = Unit<base, dimensions::length>{};
constexpr Unit s = Unit<base, dimensions::time>{};

template<concepts::Length<double> Q>
constexpr auto square(Q value) {
    return value * value;
}

TEST_CASE("Basic test", "[basic]") {

    constexpr Quantity<m/s> vel {1.0};
    constexpr Quantity<s> time_traveling {10.0};

    constexpr Quantity<m> distance = vel * time_traveling;

    constexpr Quantity<m> test = 1.0*m;
    constexpr Quantity<m*m> test_sqr = square(test);

    REQUIRE(vel.in<m/s>() == 1.0);
    REQUIRE(distance.in<m>() == 10.0);
    REQUIRE(test.in<m>() == 1.0);
    REQUIRE(test_sqr.in<m*m>() == 1.0);

}