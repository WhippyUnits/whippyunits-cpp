#include <limits>

namespace whippyunits::utils {
    /**
     * constexpr newton-raphson square root approximation tail-recursive function
     * @param x value to square root
     * @param current current iteration
     * @param previous previous iteration
     * @returns next iteration if not at correct precision, otherwise the result of the square root
     */
    inline constexpr double constexpr_sqrt_newton_raphson(double x, double current, double previous) {
        return current == previous ?
            current : constexpr_sqrt_newton_raphson(x, 0.5 * (current + x / current), current);
    }

    /**
     * constexpr square root
     * @param x value to square root
     * @returns square root of `x` if 0 <= x <= ∞, otherwise NaN
     */
    inline constexpr double constexpr_sqrt(double x) {
        return x >= 0 && x < std::numeric_limits<double>::infinity() ? 
            constexpr_sqrt_newton_raphson(x, x, 0.0) : std::numeric_limits<double>::quiet_NaN();
    }

    /**
     * Constexpr double exponentiation by integer power.
     * 
     * unfortunately, due to the C++ stdlib not having a constexpr exponentiation function, 
     * compile-time exponentation requires a recursive method.
     * However, due to the exp method used, no more than 32 iterations will occur.
     * @param x value to raise
     * @param exp integer exponent
     * @returns `x ^ exp` when `exp` isn't the integer minimum, 0.0
     */
    inline constexpr double constexpr_pow(double x, int exp) {
        // rare edge case, when exp == int::min(), -exp is itself. return 0.0
        if(exp == std::numeric_limits<int>::min()) { return 0.0; }
        if(exp < 0) { return constexpr_pow(1.0/x, -exp); }
        if(exp == 0) { return 1.0; }
        if(exp % 2 == 0) { return constexpr_pow(x * x, exp / 2); }
        return x * constexpr_pow(x * x, (exp - 1) / 2);
    }
}