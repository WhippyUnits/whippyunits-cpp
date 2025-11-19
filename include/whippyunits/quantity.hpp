// Copyright (c) whippyunits contributors

#pragma once

#include <type_traits>
#include <whippyunits/unit.hpp>
#include <whippyunits/util/constexpr_utilities.hpp>

namespace whippyunits {

    template<Unit _UNIT, typename T = double>
    requires std::is_arithmetic_v<T>
    struct Quantity {
        T value;

        using TYPE = T;

        static constexpr Unit UNIT = _UNIT;

        template<Unit U>
        requires (UNIT.dimension == U.dimension)
        constexpr Quantity<U, TYPE> rescale_to() const {
            TYPE ratio = UNIT.scale.template ratio<TYPE>(U.scale);
            return Quantity<U, TYPE>{value * ratio};
        }

        template<Unit U>
        requires (UNIT.dimension == U.dimension)
        constexpr TYPE in() const {
            TYPE ratio = UNIT.scale.template ratio<TYPE>(U.scale);
            return value * ratio;
        }
    };

    template<Unit U, typename T>
    constexpr auto operator+(Quantity<U, T> left, Quantity<U, T> right) {
        return Quantity<U, T>{left.value + right.value};
    }

    template<Unit U, typename T>
    constexpr auto operator-(Quantity<U, T> left, Quantity<U, T> right) {
        return Quantity<U, T>{left.value - right.value};
    }

    template<Unit U, typename T>
    constexpr auto operator*(Quantity<U, T> left, T right) {
        return Quantity<U, T>{left.value * right};
    }
    template<Unit U0, Unit U1, typename T>
    constexpr auto operator*(Quantity<U0, T> left, Quantity<U1, T> right) {
        return Quantity<U0 * U1, T>{left.value * right.value};
    }

    template<Unit U0, Unit U1, typename T>
    constexpr auto operator/(Quantity<U0, T> left, Quantity<U1, T> right) {
        return Quantity<U0 / U1, T>{left.value / right.value};
    }

    template<typename T, Scale S, Dimension D>
    constexpr auto operator*(T value, Unit<S, D>) {
        return Quantity<Unit<S, D>{}, T>{value};
    }

    template<Unit U, Scale S, Dimension D, typename T>
    constexpr auto operator*(Quantity<U, T> left, Unit<S, D>) {
        return Quantity<U * Unit<S, D>{}, T>{left.value};
    }

    template<Unit U, Scale S, Dimension D, typename T>
    constexpr auto operator/(Quantity<U, T> left, Unit<S, D>) {
        return Quantity<U / Unit<S, D>{}, T>{left.value};
    }

}