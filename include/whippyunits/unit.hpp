#pragma once

#include <whippyunits/scale.hpp>
#include <whippyunits/dimension.hpp>

namespace whippyunits {

    template<Scale S, Dimension D>
    struct Unit {
        static constexpr Scale scale = S;
        static constexpr Dimension dimension = D;
    };

    template<Scale S0, Scale S1, Dimension D0, Dimension D1>
    constexpr auto operator*(Unit<S0, D0>, Unit<S1, D1>) {
        return Unit<S0 * S1, D0 * D1>{};
    }
    template<Scale S0, Scale S1, Dimension D0, Dimension D1>
    constexpr auto operator/(Unit<S0, D0>, Unit<S1, D1>) {
        return Unit<S0 / S1, D0 / D1>{};
    }
    template<Scale S0, Scale S1, Dimension D0, Dimension D1>
    constexpr bool operator==(Unit<S0, D0>, Unit<S1, D1>) {
        return S0 == S1 && D0 == D1;
    }

}