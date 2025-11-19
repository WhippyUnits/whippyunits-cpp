#pragma once

#include <whippyunits/quantity.hpp>

namespace whippyunits::concepts {
    template<Unit U, Dimension D>
    concept UnscaledUnit = requires {
        requires U.dimension == D;
    };
}