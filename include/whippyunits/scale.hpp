#pragma once

#include <whippyunits/util/constexpr_utilities.hpp>

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

        template<typename T>
        constexpr T ratio(Scale other) const {
            double exp_2 = utils::constexpr_pow(2.0, P2.EXP - other.P2.EXP);
            double exp_3 = utils::constexpr_pow(3.0, P3.EXP - other.P3.EXP);
            double exp_5 = utils::constexpr_pow(5.0, P5.EXP - other.P5.EXP);
            double exp_π = utils::constexpr_pow(3.14159265358979323846264338327950288, Pπ.EXP - other.Pπ.EXP);
            return static_cast<T>(exp_2 * exp_3 * exp_5 * exp_π);
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
    constexpr Scale operator^(Scale left, int right) {
        return Scale {
            _2{left.P2.EXP * right},
            _3{left.P3.EXP * right},
            _5{left.P5.EXP * right},
            _π{left.Pπ.EXP * right}
        };
    }
    constexpr bool operator==(Scale left, Scale right) {
        return 
            left.P2.EXP == right.P2.EXP &&
            left.P3.EXP == right.P3.EXP &&
            left.P5.EXP == right.P5.EXP &&
            left.Pπ.EXP == right.Pπ.EXP;
    }

}