#pragma once

#include <whippyunits/unit.hpp>

namespace whippyunits {

    template<Unit B>
    struct ScaledUnit {
        static constexpr Unit base = B;
        long double scale;
    };

    template<Scale S, Dimension D, Unit U>
    constexpr auto operator*(Unit<S, D>, ScaledUnit<U> right) {
        return ScaledUnit<Unit<S, D>{} * U>{right.scale};
    }
    template<Scale S, Dimension D, Unit U>
    constexpr auto operator*(ScaledUnit<U> left, Unit<S, D>) {
        return ScaledUnit<U * Unit<S, D>{}>{left.scale};
    }
    template<Unit B0, Unit B1>
    constexpr auto operator*(ScaledUnit<B0> left, ScaledUnit<B1> right) {
        return ScaledUnit<B0 * B1>{left.scale * right.scale};
    }
    template<Scale S, Dimension D, Unit U>
    constexpr auto operator/(Unit<S, D>, ScaledUnit<U> right) {
        return ScaledUnit<Unit<S, D>{} / U>{right.scale};
    }
    template<Scale S, Dimension D, Unit U>
    constexpr auto operator/(ScaledUnit<U> left, Unit<S, D>) {
        return ScaledUnit<U / Unit<S, D>{}>{left.scale};
    }
    template<Unit B0, Unit B1>
    constexpr auto operator/(ScaledUnit<B0> left, ScaledUnit<B1> right) {
        return ScaledUnit<B0 / B1>{left.scale / right.scale};
    }

}