#pragma once

#include <concepts>
#include <whippyunits/quantity.hpp>

namespace whippyunits::concepts {
    template<class Q>
    concept IsQuantity = requires(Q q) {
        std::same_as<Q, Quantity<Q::UNIT, typename Q::TYPE>>;
    };

    template<class Q, Dimension D, typename T>
    concept Unscaled = requires {
        std::is_arithmetic_v<T>;
        IsQuantity<Q>;
        Q::UNIT.dimension == D;
    };
}