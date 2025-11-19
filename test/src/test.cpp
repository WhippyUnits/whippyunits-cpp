// Copyright (c) whippyunits contributors

#include <catch2/catch_test_macros.hpp>

#include <catch2/matchers/catch_matchers.hpp>
#include <whippyunits/quantity.hpp>
#include <whippyunits/concepts.hpp>
#include <whippyunits/dimensions/base.hpp>
#include <whippyunits/units/si.hpp>
//#include "catch_matchers.hpp"

using namespace whippyunits;
using namespace whippyunits::units;

template<Unit U>
requires concepts::Length<U>
constexpr auto square(Quantity<U, double> value) {
    return value * value;
}

TEST_CASE("Basic test", "[basic]") {

    constexpr Quantity<m/s> vel {1.0};
    constexpr Quantity<s> time_traveling {10.0};

    constexpr Quantity<m> distance = vel * time_traveling;

    constexpr Quantity<m> test = 1.0*m;
    constexpr Quantity<m*m> test_sqr = square(test);

    constexpr Quantity<J> test2 = 1.0 * N*m;

    constexpr auto my_mass = 1.0 * kg + (1.0*g).rescale_to<kg>();
    constexpr double mass_value = my_mass.value_in<milligrams>();

    constexpr Quantity<kV> my_voltage = 1.0*kW/A;

    test2.value_in<J>();
    my_voltage.value_in<V>();

    //constexpr auto test_sqr_2 = square2(test);

    REQUIRE(vel.value_in<m/s>() == 1.0);
    REQUIRE(distance.value_in<m>() == 10.0);
    REQUIRE(test.value_in<m>() == 1.0);
    REQUIRE(test_sqr.value_in<m*m>() == 1.0);
    REQUIRE(mass_value <= 1000000.0);

}