#pragma once

#include <whippyunits/quantity.hpp>
#include <whippyunits/dimension.hpp>
#include <whippyunits/dimensions/base.hpp>
#include <whippyunits/concepts.hpp>

namespace whippyunits::dimension {

    constexpr Dimension dimensionless = Dimension(_M(0), _L(0), _T(0), _I(0), _Θ(0), _J(0), _N(0));
    constexpr Dimension mass          = Dimension(_M(1), _L(0), _T(0), _I(0), _Θ(0), _J(0), _N(0));
    constexpr Dimension length        = Dimension(_M(0), _L(1), _T(0), _I(0), _Θ(0), _J(0), _N(0));
    constexpr Dimension time          = Dimension(_M(0), _L(0), _T(1), _I(0), _Θ(0), _J(0), _N(0));
    constexpr Dimension current       = Dimension(_M(0), _L(0), _T(0), _I(1), _Θ(0), _J(0), _N(0));
    constexpr Dimension temperature   = Dimension(_M(0), _L(0), _T(0), _I(0), _Θ(1), _J(0), _N(0));
    constexpr Dimension luminosity    = Dimension(_M(0), _L(0), _T(0), _I(0), _Θ(0), _J(1), _N(0));
    constexpr Dimension substance     = Dimension(_M(0), _L(0), _T(0), _I(0), _Θ(0), _J(0), _N(1));

}

namespace whippyunits::concepts {

    template<Unit U>
    concept Dimensionless = UnscaledUnit<U, dimension::dimensionless>;

    template<Unit U>
    concept Mass = UnscaledUnit<U, dimension::mass>;

    template<Unit U>
    concept Length = UnscaledUnit<U, dimension::length>;

    template<Unit U>
    concept Time = UnscaledUnit<U, dimension::time>;

    template<Unit U>
    concept Current = UnscaledUnit<U, dimension::current>;

    template<Unit U>
    concept Temperature = UnscaledUnit<U, dimension::temperature>;

    template<Unit U>
    concept Luminosity = UnscaledUnit<U, dimension::luminosity>;

    template<Unit U>
    concept Substance = UnscaledUnit<U, dimension::substance>;
}