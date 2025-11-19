#pragma once

#include <whippyunits/quantity.hpp>
#include <whippyunits/dimension.hpp>
#include <whippyunits/dimensions/base.hpp>
#include <whippyunits/concepts.hpp>

namespace whippyunits::dimensions {

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

    template<class Q, typename T>
    concept Dimensionless = Unscaled<Q, dimensions::dimensionless, T>;

    template<class Q, typename T>
    concept Mass = Unscaled<Q, dimensions::mass, T>;

    template<class Q, typename T>
    concept Length = Unscaled<Q, dimensions::dimensionless, T>;

    template<class Q, typename T>
    concept Time = Unscaled<Q, dimensions::time, T>;

    template<class Q, typename T>
    concept Current = Unscaled<Q, dimensions::current, T>;

    template<class Q, typename T>
    concept Temperature = Unscaled<Q, dimensions::temperature, T>;

    template<class Q, typename T>
    concept Luminosity = Unscaled<Q, dimensions::luminosity, T>;

    template<class Q, typename T>
    concept Substance = Unscaled<Q, dimensions::substance, T>;
}