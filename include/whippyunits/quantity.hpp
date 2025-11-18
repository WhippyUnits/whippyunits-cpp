// Copyright (c) whippyunits contributors

#pragma once

#include <concepts>
#include "whippyunits/util/constexpr_utilities.hpp"

namespace whippyunits {

    struct _2 { const int EXP; };
    struct _3 { const int EXP; };
    struct _5 { const int EXP; };
    struct _π { const int EXP; };
    struct Scale {
        const _2 P2;
        const _3 P3;
        const _5 P5;
        const _π Pπ;

        static constexpr Scale _10(const int exp)  {
            return Scale{_2{exp}, _3{0}, _5{exp}, _π{0}};
        }

        constexpr double double_ratio(Scale other) const {
            double exp_2 = utils::constexpr_pow(2.0, P2.EXP - other.P2.EXP);
            double exp_3 = utils::constexpr_pow(3.0, P3.EXP - other.P3.EXP);
            double exp_5 = utils::constexpr_pow(5.0, P5.EXP - other.P5.EXP);
            double exp_π = utils::constexpr_pow(3.14159265358979323846264338327950288, Pπ.EXP - other.Pπ.EXP);
            return exp_2 * exp_3 * exp_5 * exp_π;
        }
    };
    constexpr Scale operator*(Scale left, Scale right) {
        return Scale {
            _2{left.P2.EXP + right.P2.EXP},
            _3{left.P3.EXP + right.P3.EXP},
            _5{left.P5.EXP + right.P5.EXP},
            _π{left.Pπ.EXP + right.Pπ.EXP}
        };
    }
    constexpr Scale operator/(Scale left, Scale right) {
        return Scale {
            _2{left.P2.EXP - right.P2.EXP},
            _3{left.P3.EXP - right.P3.EXP},
            _5{left.P5.EXP - right.P5.EXP},
            _π{left.Pπ.EXP - right.Pπ.EXP}
        };
    }

    struct _M { const int EXP; };
    struct _L { const int EXP; };
    struct _T { const int EXP; };
    struct _I { const int EXP; };
    struct _Θ { const int EXP; };
    struct _J { const int EXP; };
    struct _N { const int EXP; };
    struct Dimension {
        const _M M;
        const _L L;
        const _T T;
        const _I I;
        const _Θ Θ;
        const _J J;
        const _N N;
    };
    constexpr Dimension operator*(Dimension left, Dimension right) {
        return Dimension {
            _M{left.M.EXP + right.M.EXP},
            _L{left.L.EXP + right.L.EXP},
            _T{left.T.EXP + right.T.EXP},
            _I{left.I.EXP + right.I.EXP},
            _Θ{left.Θ.EXP + right.Θ.EXP},
            _J{left.J.EXP + right.J.EXP},
            _N{left.N.EXP + right.N.EXP}
        };
    }
    constexpr Dimension operator/(Dimension left, Dimension right) {
        return Dimension {
            _M{left.M.EXP - right.M.EXP},
            _L{left.L.EXP - right.L.EXP},
            _T{left.T.EXP - right.T.EXP},
            _I{left.I.EXP - right.I.EXP},
            _Θ{left.Θ.EXP - right.Θ.EXP},
            _J{left.J.EXP - right.J.EXP},
            _N{left.N.EXP - right.N.EXP}
        };
    }
    constexpr bool operator==(Dimension left, Dimension right) {
        return 
            left.M.EXP == right.M.EXP &&
            left.L.EXP == right.L.EXP &&
            left.T.EXP == right.T.EXP &&
            left.I.EXP == right.I.EXP &&
            left.Θ.EXP == right.Θ.EXP &&
            left.J.EXP == right.J.EXP &&
            left.N.EXP == right.N.EXP;
    }

    template<Scale _SCALE, Dimension _DIMENSION, typename T, typename BRAND>
    struct Quantity {
        T value;

        using type = T;
        using brand = BRAND;

        static constexpr Scale SCALE = _SCALE;
        static constexpr Dimension DIMENSION = _DIMENSION;

        template<typename Q>
        requires 
            (DIMENSION == Q::DIMENSION) && 
            std::same_as<type, typename Q::type> &&
            std::same_as<brand, typename Q::brand>
        constexpr Q rescale_to() const {
            double ratio = SCALE.double_ratio(Q::SCALE);
            return Q{value * ratio};
        }

        template<typename Q>
        requires
            (DIMENSION == Q::DIMENSION) && 
            std::same_as<type, typename Q::type> &&
            std::same_as<brand, typename Q::brand>
        constexpr double in() const {
            double ratio = SCALE.double_ratio(Q::SCALE);
            return value * ratio;
        }
    };

    template<Scale S, Dimension D, typename T, typename BRAND>
    constexpr auto operator+(Quantity<S, D, T, BRAND> left, Quantity<S, D, T, BRAND> right) {
        return Quantity<S, D, T, BRAND> {
            left.value + right.value
        };
    }
    template<Scale S, Dimension D, typename T, typename BRAND>
    constexpr auto operator-(Quantity<S, D, T, BRAND> left, Quantity<S, D, T, BRAND> right) {
        return Quantity<S, D, T, BRAND> {
            left.value - right.value
        };
    }

    template<Scale S0, Dimension D0, Scale S1, Dimension D1, typename T, typename BRAND>
    constexpr auto operator*(Quantity<S0, D0, T, BRAND> left, Quantity<S1, D1, T, BRAND> right) {
        constexpr Scale S = S0 * S1;
        constexpr Dimension D = D0 * D1;
        return Quantity<S, D, T, BRAND> {
            left.value * right.value
        };
    }

    template<Scale S0, Dimension D0, Scale S1, Dimension D1, typename T, typename BRAND>
    constexpr auto operator/(Quantity<S0, D0, T, BRAND> left, Quantity<S1, D1, T, BRAND> right) {
        constexpr Scale S = S0 / S1;
        constexpr Dimension D = D0 / D1;
        return Quantity<S, D, T, BRAND> {
            left.value / right.value
        };
    }
}