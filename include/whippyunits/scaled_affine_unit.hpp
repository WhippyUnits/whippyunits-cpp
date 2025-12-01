#pragma once

#include <whippyunits/affine_unit.hpp>

namespace whippyunits {

    template<AffineUnit U>
    struct ScaledAffineUnit {
        static constexpr AffineUnit base = U;
        long double scale;
    };

}