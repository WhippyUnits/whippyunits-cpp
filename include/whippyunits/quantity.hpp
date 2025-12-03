// Copyright (c) whippyunits contributors

#pragma once

#include <type_traits>
#include <whippyunits/unit.hpp>
#include <whippyunits/scaled_unit.hpp>
#include <whippyunits/affine_unit.hpp>
#include <whippyunits/util/constexpr_utilities.hpp>
#include "whippyunits/scaled_affine_unit.hpp"

namespace whippyunits {

    struct ZeroQuantity {};
    const constexpr ZeroQuantity ZERO = ZeroQuantity{};

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
        constexpr TYPE value_in() const {
            TYPE ratio = UNIT.scale.template ratio<TYPE>(U.scale);
            return value * ratio;
        }

        template<ScaledUnit U>
        requires (UNIT.dimension == U.base.dimension)
        constexpr TYPE value_in() const {
            return this->value_in<U.base>() / U.scale;
        }

        template<AffineUnit U>
        requires (UNIT.dimension == U.base.dimension)
        constexpr TYPE value_in() const {
            return this->value_in<U.base>() - static_cast<TYPE>(U.offset);
        }

        template<ScaledAffineUnit U>
        requires (UNIT.dimension == U.base.base.dimension)
        constexpr TYPE value_in() const {
            return this->value_in<U.base>() / U.scale;
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
    template<Unit U, typename T>
    constexpr auto operator*(T left, Quantity<U, T> right) {
        return right * left;
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
    constexpr auto operator*(T left, Unit<S, D>) {
        return Quantity<Unit<S, D>{}, T>{left};
    }

    template<typename T, Unit U>
    constexpr auto operator*(T left, ScaledUnit<U> right) {
        return Quantity<U, T>{static_cast<T>(right.scale * static_cast<long double>(left))};
    }

    template<Unit U, Scale S, Dimension D, typename T>
    constexpr auto operator*(Quantity<U, T> left, Unit<S, D>) {
        return Quantity<U * Unit<S, D>{}, T>{left.value};
    }

    template<Unit U0, Unit U1, typename T>
    constexpr auto operator*(Quantity<U0, T> left, ScaledUnit<U1> right) {
        return Quantity<U0 * U1, T>{static_cast<T>(right.scale * static_cast<long double>(left.value))};
    }

    template<Unit U, Scale S, Dimension D, typename T>
    constexpr auto operator/(Quantity<U, T> left, Unit<S, D>) {
        return Quantity<U / Unit<S, D>{}, T>{left.value};
    }

    template<Unit U0, Unit U1, typename T>
    constexpr auto operator/(Quantity<U0, T> left, ScaledUnit<U1> right) {
        return Quantity<U0 / U1, T>{static_cast<T>(static_cast<long double>(left.value) / right.scale)};
    }

    constexpr bool operator==(ZeroQuantity, ZeroQuantity) {
        return true;
    }

    template<Unit U, typename T>
    constexpr bool operator==(Quantity<U, T> left, ZeroQuantity) {
        return left.value == static_cast<T>(0.0);
    }

    template<Unit U, typename T>
    constexpr bool operator==(ZeroQuantity, Quantity<U, T> right) {
        return right == ZeroQuantity{};
    }

    template<Unit U, typename T>
    constexpr bool operator==(Quantity<U, T> left, Quantity<U, T> right) {
        return left.value == right.value;
    }

    template<Unit U, typename T>
    constexpr bool operator<=(Quantity<U, T> left, ZeroQuantity) {
        return left.value <= static_cast<T>(0.0);
    }

    template<Unit U, typename T>
    constexpr bool operator<=(ZeroQuantity, Quantity<U, T> right) {
        return right <= ZeroQuantity{};
    }

    template<Unit U, typename T>
    constexpr bool operator<=(Quantity<U, T> left, Quantity<U, T> right) {
        return left.value <= right.value;
    }

    template<Unit U, typename T>
    constexpr bool operator>=(Quantity<U, T> left, ZeroQuantity) {
        return left.value <= static_cast<T>(0.0);
    }

    template<Unit U, typename T>
    constexpr bool operator>=(ZeroQuantity, Quantity<U, T> right) {
        return right >= ZeroQuantity{};
    }

    template<Unit U, typename T>
    constexpr bool operator>=(Quantity<U, T> left, Quantity<U, T> right) {
        return left.value >= right.value;
    }

}