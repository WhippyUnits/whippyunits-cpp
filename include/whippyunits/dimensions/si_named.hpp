#pragma once

#include <whippyunits/dimensions/base.hpp>
#include "whippyunits/concepts.hpp"

namespace whippyunits::dimension {

    constexpr Dimension frequency           = dimensionless / time;
    constexpr Dimension angle               = dimensionless;
    constexpr Dimension solid_angle         = angle * angle;
    constexpr Dimension force               = mass * length / time / time;
    constexpr Dimension pressure            = force / length / length;
    constexpr Dimension energy              = force * length;
    constexpr Dimension power               = energy / time;
    constexpr Dimension charge              = current * time;
    constexpr Dimension voltage             = power / current;
    constexpr Dimension capacitance         = charge / voltage;
    constexpr Dimension resistance          = voltage / current;
    constexpr Dimension conductance         = dimensionless / resistance;
    constexpr Dimension magnetic_flux       = energy / current;
    constexpr Dimension magnetic_induction  = magnetic_flux / length / length;
    constexpr Dimension inductance          = resistance * time;
    constexpr Dimension luminous_flux       = luminosity * solid_angle;
    constexpr Dimension illuminance         = luminous_flux / length / length;
    constexpr Dimension radioactivity       = dimensionless / time;
    constexpr Dimension absorbed_dose       = energy / mass;
    constexpr Dimension equivalent_dose     = energy / mass;
    constexpr Dimension catalytic_activity  = substance / time;

}

namespace whippyunits::concepts {

    template<Unit U>
    concept Frequency = UnscaledUnit<U, dimension::frequency>;

    template<Unit U>
    concept Angle = UnscaledUnit<U, dimension::angle>;

    template<Unit U>
    concept SolidAngle = UnscaledUnit<U, dimension::solid_angle>;

    template<Unit U>
    concept Force = UnscaledUnit<U, dimension::force>;

    template<Unit U>
    concept Pressure = UnscaledUnit<U, dimension::pressure>;

    template<Unit U>
    concept Energy = UnscaledUnit<U, dimension::energy>;

    template<Unit U>
    concept Power = UnscaledUnit<U, dimension::power>;

    template<Unit U>
    concept Charge = UnscaledUnit<U, dimension::charge>;

    template<Unit U>
    concept Voltage = UnscaledUnit<U, dimension::voltage>;

    template<Unit U>
    concept Capacitance = UnscaledUnit<U, dimension::capacitance>;

    template<Unit U>
    concept Resistance = UnscaledUnit<U, dimension::resistance>;

    template<Unit U>
    concept Conductance = UnscaledUnit<U, dimension::conductance>;

    template<Unit U>
    concept MagneticFlux = UnscaledUnit<U, dimension::magnetic_flux>;

    template<Unit U>
    concept MagneticInduction = UnscaledUnit<U, dimension::magnetic_induction>;

    template<Unit U>
    concept Inductance = UnscaledUnit<U, dimension::inductance>;

    template<Unit U>
    concept LuminousFlux = UnscaledUnit<U, dimension::luminous_flux>;

    template<Unit U>
    concept Illuminance = UnscaledUnit<U, dimension::illuminance>;

    template<Unit U>
    concept Radioactivity = UnscaledUnit<U, dimension::radioactivity>;

    template<Unit U>
    concept AbsorbedDose = UnscaledUnit<U, dimension::absorbed_dose>;

    template<Unit U>
    concept EquivalentDose = UnscaledUnit<U, dimension::equivalent_dose>;

    template<Unit U>
    concept CatalyticActivity = UnscaledUnit<U, dimension::catalytic_activity>;

}