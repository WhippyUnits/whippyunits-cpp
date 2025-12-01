#pragma once

#include <whippyunits/affine_unit.hpp>
#include <whippyunits/quantity.hpp>

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

        template<AffineUnit U>
        requires (UNIT.base.dimension == U.base.dimension)
        constexpr TYPE value_in() const {
            TYPE ratio = UNIT.base.scale.template ratio<TYPE>(U.base.scale);
            return (value + static_cast<TYPE>(UNIT.offset)) * ratio - static_cast<TYPE>(U.offset);
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

}