#pragma once

namespace whippyunits {

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
    constexpr Dimension operator^(Dimension left, int right) {
        return Dimension {
            _M{left.M.EXP * right},
            _L{left.L.EXP * right},
            _T{left.T.EXP * right},
            _I{left.I.EXP * right},
            _Θ{left.Θ.EXP * right},
            _J{left.J.EXP * right},
            _N{left.N.EXP * right}
        };
    }
    constexpr bool operator==(Dimension left, Dimension right) {
        return 
            (left.M.EXP == right.M.EXP) &&
            (left.L.EXP == right.L.EXP) &&
            (left.T.EXP == right.T.EXP) &&
            (left.I.EXP == right.I.EXP) &&
            (left.Θ.EXP == right.Θ.EXP) &&
            (left.J.EXP == right.J.EXP) &&
            (left.N.EXP == right.N.EXP);
    }

}