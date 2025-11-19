// Copyright (c) whippyunits contributors

#include <catch2/catch_test_macros.hpp>

#include <catch2/matchers/catch_matchers.hpp>
#include <whippyunits/unit.hpp>
//#include "catch_matchers.hpp"

using namespace whippyunits;

TEST_CASE("Units test", "[basic]") {

    constexpr Scale base = Scale::_10(0);
    constexpr Dimension length = Dimension{_M{0}, _L{1}, _T{0}, _I{0}, _Θ{0}, _J{0}, _N{0}};
    constexpr Dimension area = Dimension{_M{0}, _L{2}, _T{0}, _I{0}, _Θ{0}, _J{0}, _N{0}};

    constexpr Unit meters = Unit<base, length>{};
    constexpr Unit meters_squared = Unit<base, area>{};

    REQUIRE((meters*meters) == meters_squared);

}

/*

constexpr Unit meters = Unit{BASE, LENGTH};

constexpr Quantity<m/s> test = 1.0_m/s;

*/