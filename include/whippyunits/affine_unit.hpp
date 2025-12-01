#pragma once

#include <whippyunits/unit.hpp>

namespace whippyunits {

    template<Unit B, long double O>
    struct AffineUnit {
        static constexpr Unit base = B;
        static constexpr long double offset = O;
    };

}