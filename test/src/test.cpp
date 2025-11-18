// Copyright (c) whippyunits contributors

#include <catch2/catch_test_macros.hpp>

#include <catch2/matchers/catch_matchers.hpp>
#include <whippyunits/quantity.hpp>
#include "catch_matchers.hpp"

using namespace whippyunits;

TEST_CASE("Basic test", "[basic]") {

    constexpr Scale BASE = Scale::_10(0);
    constexpr Scale KILO = Scale::_10(3);
    constexpr Dimension DIMENSIONLESS = Dimension{_M{0}, _L{0}, _T{0}, _I{0}, _Θ{0}, _J{0}, _N{0}};
    //constexpr Dimension LENGTH = Dimension{_M{0}, _L{1}, _T{0}, _I{0}, _Θ{0}, _J{0}, _N{0}};

    constexpr Quantity<BASE, DIMENSIONLESS, double, void> q0 {1.0};
    constexpr Quantity<KILO, DIMENSIONLESS, double, void> q1 {1.0};

    constexpr auto q2 = q0 * q1;
    constexpr auto q3 = q2.rescale_to<Quantity<BASE, DIMENSIONLESS, double, void>>();

    CHECK_THAT(q2.value, WithinAbs(1.0, 0.0001));
    CHECK_THAT(q2.SCALE.P2.EXP, WithinAbs(3.0, 0.0001));
    CHECK_THAT(q3.value, WithinAbs(1000.0, 0.0001));

}
