#pragma once

#include <whippyunits/dimensions/base.hpp>
#include "whippyunits/concepts.hpp"

namespace whippyunits::dimension {

    constexpr Dimension area = length ^ 2;
    constexpr Dimension volume = length ^ 3;

}

namespace whippyunits::concepts {

    template<Unit U>
    concept Area = UnscaledUnit<U, dimension::area>;

    template<Unit U>
    concept Volume = UnscaledUnit<U, dimension::volume>;

}