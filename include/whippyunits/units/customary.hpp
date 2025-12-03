#pragma once

#include <whippyunits/si_scales.hpp>
#include <whippyunits/dimensions/base.hpp>
#include <whippyunits/dimensions/si_named.hpp>
#include <whippyunits/dimensions/customary_named.hpp>
#include <whippyunits/util/macro_utilities.hpp>

namespace whippyunits::units {

    DEFINE_SCALED_UNIT(dimension::length, scale::centi, 2.54, inch, inches, in);
    DEFINE_SCALED_UNIT(dimension::length, scale::deci, 3.048, foot, feet, ft);
    DEFINE_SCALED_UNIT(dimension::length, scale::base, 0.9144, yard, yards, yd);
    DEFINE_SCALED_UNIT(dimension::length, scale::kilo, 1.60934, mile, miles, mi);

    DEFINE_SCALED_UNIT(dimension::mass, scale::deca, 2.83495, ounce, ounces, oz);
    DEFINE_SCALED_UNIT(dimension::length, scale::deca, 0.453592, pound, pounds, lb, lbs);
    DEFINE_SCALED_UNIT(dimension::length, scale::mega, 0.907185, ton, tons, tn);

    DEFINE_SCALED_UNIT(dimension::force, scale::deca, 0.444822, pound_force, pounds_force, lbf);

    DEFINE_SCALED_UNIT(dimension::area, scale::hecto, 0.404686, acre, acres, ac);

    DEFINE_SCALED_UNIT(dimension::volume, Scale::_10(-5), 0.492892, teaspoon, teaspoons, tsp);
    DEFINE_SCALED_UNIT(dimension::volume, Scale::_10(-5), 1.47868, tablespoon, tablespoons, tbsp);
    DEFINE_SCALED_UNIT(dimension::volume, Scale::_10(-5), 2.95735, fluid_ounce, fluid_ounces, fl_oz);
    DEFINE_SCALED_UNIT(dimension::volume, Scale::_10(-4), 2.36588, cup, cups);
    DEFINE_SCALED_UNIT(dimension::volume, scale::milli, 0.568261, pint, pints, pt);
    DEFINE_SCALED_UNIT(dimension::volume, scale::milli, 0.946353, quart, quarts, qt);
    DEFINE_SCALED_UNIT(dimension::volume, scale::centi, 0.378541, gallon, gallons, gal);

    DEFINE_SCALED_UNIT(dimension::temperature, scale::base, 5.0l/9.0l, fahrenheit_degree, fahrenheit_degrees, F_deg);
    DEFINE_SCALED_AFFINE_UNIT(dimension::temperature, scale::base, 5.0l/9.0l, 45967.0l/180.0l, degree_fahrenheit, degrees_fahrenheit, deg_F);

}