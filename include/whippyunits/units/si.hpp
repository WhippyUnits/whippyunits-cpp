#pragma once

#include <whippyunits/si_scales.hpp>
#include <whippyunits/dimensions/si_named.hpp>
#include <whippyunits/util/macro_utilities.hpp>

namespace whippyunits::units {

    // DEFINE_SI_UNIT(dimension, primary, symbol, aliases)
    
    DEFINE_SCALED_SI_UNIT(dimension::mass, scale::kilo, gram, g, grams);
    DEFINE_SI_UNIT(dimension::length, meter, m, meters);
    DEFINE_SI_UNIT(dimension::time, second, s, seconds);
    DEFINE_SI_UNIT(dimension::current, ampere, A, amperes);
    DEFINE_SI_UNIT(dimension::temperature, kelvin, K);
    DEFINE_SI_UNIT(dimension::luminosity, candela, cd);
    DEFINE_SI_UNIT(dimension::substance, mole, mol, moles);

    DEFINE_SI_UNIT(dimension::frequency, Hz, hertz);
    DEFINE_SI_UNIT(dimension::angle, radian, rad, radians);
    DEFINE_SI_UNIT(dimension::solid_angle, steradian, sr, steradians);
    DEFINE_SI_UNIT(dimension::force, newton, N, newtons);
    DEFINE_SI_UNIT(dimension::pressure, pascal, Pa, pascals);
    DEFINE_SI_UNIT(dimension::energy, joule, J, joules);
    DEFINE_SI_UNIT(dimension::power, watt, W, watts);
    DEFINE_SI_UNIT(dimension::charge, coulomb, C, coulombs);
    DEFINE_SI_UNIT(dimension::voltage, volt, V, volts);
    DEFINE_SI_UNIT(dimension::capacitance, farad, F, farads);
    DEFINE_SI_UNIT_NO_O(dimension::resistance, ohm, Ω, ohms);
    DEFINE_SI_UNIT(dimension::conductance, siemens, S);
    DEFINE_SI_UNIT(dimension::magnetic_flux, weber, Wb, webers);
    DEFINE_SI_UNIT(dimension::magnetic_induction, tesla, T, teslas);
    DEFINE_SI_UNIT(dimension::inductance, henry, henrys, H, henries);
    DEFINE_SI_UNIT(dimension::luminous_flux, lumen, lm, lumens);
    DEFINE_SI_UNIT(dimension::illuminance, lux, lx);
    DEFINE_SI_UNIT(dimension::radioactivity, becquerel, Bq, becquerels);
    DEFINE_SI_UNIT(dimension::absorbed_dose, gray, Gy, grays);
    DEFINE_SI_UNIT(dimension::equivalent_dose, sievert, Sv, sieverts);
    DEFINE_SI_UNIT(dimension::catalytic_activity, katal, kat, katals);

}