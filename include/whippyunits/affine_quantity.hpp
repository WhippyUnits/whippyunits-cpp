#pragma once

#include <whippyunits/affine_unit.hpp>
#include <whippyunits/quantity.hpp>
#include <whippyunits/scaled_affine_unit.hpp>

namespace whippyunits {

    template<AffineUnit _UNIT, typename T = double>
    struct AffineQuantity {

        T value;

        using TYPE = T;
        static constexpr AffineUnit UNIT = _UNIT;

        template<Unit U>
        requires (UNIT.base.dimension == U.dimension)
        constexpr Quantity<U, TYPE> rescale_to() const {
            TYPE ratio = UNIT.base.scale.template ratio<TYPE>(U.scale);
            return Quantity<U, TYPE>{(value + static_cast<TYPE>(UNIT.offset)) * ratio};
        }

        template<AffineUnit U>
        requires (UNIT.base.dimension == U.base.dimension)
        constexpr AffineQuantity<U, TYPE> rescale_to() const {
            TYPE ratio = UNIT.base.scale.template ratio<TYPE>(U.base.scale);
            return AffineQuantity<U, TYPE>{(value + static_cast<TYPE>(UNIT.offset)) * ratio - static_cast<TYPE>(U.offset)};
        }

        template<Unit U>
        requires (UNIT.base.dimension == U.dimension)
        constexpr TYPE value_in() const {
            TYPE ratio = UNIT.base.scale.template ratio<TYPE>(U.scale);
            return (value + static_cast<TYPE>(UNIT.offset)) * ratio;
        }

        template<ScaledUnit U>
        requires (UNIT.base.dimension == U.base.dimension)
        constexpr TYPE value_in() const {
            return this->value_in<U.base>() / U.scale;
        }

        template<AffineUnit U>
        requires (UNIT.base.dimension == U.base.dimension)
        constexpr TYPE value_in() const {
            return this->value_in<U.base>() - static_cast<TYPE>(U.offset);
        }

        template<ScaledAffineUnit U>
        requires (UNIT.base.dimension == U.base.base.dimension)
        constexpr TYPE value_in() const {
            return this->value_in<U.base>() / U.scale;
        }
    };

    template<AffineUnit U, typename T>
    constexpr auto operator+(AffineQuantity<U, T> left, Quantity<U.base, T> right) {
        return AffineQuantity<U, T>{left.value + right.value};
    }
    template<AffineUnit U, typename T>
    constexpr auto operator+(Quantity<U.base, T> left, AffineQuantity<U, T> right) {
        return AffineQuantity<U, T>{left.value + right.value};
    }
    
    template<AffineUnit U, typename T>
    constexpr auto operator-(AffineQuantity<U, T> left, Quantity<U.base, T> right) {
        return AffineQuantity<U, T>{left.value - right.value};
    }
    template<AffineUnit U, typename T>
    constexpr auto operator-(AffineQuantity<U, T> left, AffineQuantity<U, T> right) {
        return Quantity<U.base, T>{left.value - right.value};
    }

    template<typename T, Unit U, long double O>
    constexpr auto operator*(T left, AffineUnit<U, O>) {
        return AffineQuantity<AffineUnit<U, O>{}, T>{left};
    }

    template<typename T, AffineUnit U>
    constexpr auto operator*(T left, ScaledAffineUnit<U> right) {
        return AffineQuantity<U, T>{static_cast<T>(right.scale * static_cast<long double>(left))};
    }

    template<AffineUnit U, typename T>
    constexpr bool operator==(AffineQuantity<U, T> left, AffineQuantity<U, T> right) {
        return left.value == right.value;
    }

    template<AffineUnit U, typename T>
    constexpr bool operator<=(AffineQuantity<U, T> left, AffineQuantity<U, T> right) {
        return left.value <= right.value;
    }

    template<AffineUnit U, typename T>
    constexpr bool operator>=(AffineQuantity<U, T> left, AffineQuantity<U, T> right) {
        return left.value >= right.value;
    }

    template<AffineUnit U, typename T>
    constexpr bool operator<(AffineQuantity<U, T> left, AffineQuantity<U, T> right) {
        return left.value < right.value;
    }

    template<AffineUnit U, typename T>
    constexpr bool operator>(AffineQuantity<U, T> left, AffineQuantity<U, T> right) {
        return left.value > right.value;
    }

}