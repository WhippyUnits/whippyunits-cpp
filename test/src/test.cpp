// Copyright (c) whippyunits contributors

#include <catch2/catch_test_macros.hpp>

#include <catch2/matchers/catch_matchers.hpp>
#include <whippyunits/quantity.hpp>
#include <whippyunits/concepts.hpp>
#include <whippyunits/dimensions/base.hpp>
#include <whippyunits/units/si.hpp>
#include "whippyunits/affine_unit.hpp"
#include "whippyunits/scaled_affine_unit.hpp"
#include "whippyunits/scaled_unit.hpp"
#include <whippyunits/affine_quantity.hpp>
//#include "catch_matchers.hpp"

/**
 * This file doesn't really contain tests, more brief checks that certain things result in the way I expect them to.
 * Proper tests are coming soon
 */

using namespace whippyunits;
using namespace whippyunits::units;

template<Unit U>
requires concepts::Length<U>
constexpr auto square(Quantity<U, double> value) {
    return value * value;
}

constexpr ScaledUnit ft = ScaledUnit<dm>{3.048l};

constexpr ScaledAffineUnit degrees_fahrenheit = ScaledAffineUnit<AffineUnit<kelvin, 45967.0l/180.0l>{}>{5.0l / 9.0l};
constexpr auto deg_F = degrees_fahrenheit;

constexpr AffineUnit degrees_celsius = AffineUnit<kelvin, 273.15l>{};
constexpr auto deg_C = degrees_celsius;

TEST_CASE("Basic test", "[basic]") {

    constexpr Quantity<m/s> vel {1.0};
    constexpr Quantity<s> time_traveling {10.0};

    constexpr Quantity<m> distance = vel * time_traveling;

    constexpr Quantity<m> test = 1.0*m;
    constexpr Quantity<m*m> test_sqr = square(test);

    constexpr Quantity<J> test2 = 1.0 * N*m;

    constexpr Quantity test3 = 1.0*ft/s;

    constexpr AffineQuantity a_test = 1.0 * deg_C;
    constexpr AffineQuantity b_test = 2.0 * deg_C;
    constexpr Quantity c_test = 1.0*K;
    constexpr Quantity d_test = b_test - a_test;
    constexpr AffineQuantity e_test = a_test + c_test;

    constexpr AffineQuantity test_a = 32.0 * deg_F;
    constexpr AffineQuantity test_b = 0.0 * deg_C;
    constexpr Quantity test_c = 273.15 * K;

    test_a.value_in<K>();
    test_b.value_in<deg_F>();
    test_c.value_in<deg_C>();
    test_c.value_in<deg_F>();

    c_test.value_in<deg_C>();
    e_test.value_in<deg_C>();
    e_test.value_in<K>();
    d_test.value_in<K>();

    test3.value_in<ft/s>();

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