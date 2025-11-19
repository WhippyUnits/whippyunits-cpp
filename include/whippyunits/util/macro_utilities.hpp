#pragma once

// what in the unholy hell is this cursed macro shenanigans (works tho)
#define PARENS ()
#define _EX(...) _EX4(_EX4(_EX4(_EX4(__VA_ARGS__))))
#define _EX4(...) _EX3(_EX3(_EX3(_EX3(__VA_ARGS__))))
#define _EX3(...) _EX2(_EX2(_EX2(_EX2(__VA_ARGS__))))
#define _EX2(...) _EX1(_EX1(_EX1(_EX1(__VA_ARGS__))))
#define _EX1(...) __VA_ARGS__

#define DEFINE_SINGLE_SI_UNIT(scale, dimension, prefix, primary, symbol, ...)         \
    constexpr Unit prefix##primary = Unit<scale, dimension>{};      \
    constexpr Unit symbol = prefix##primary; \
    __VA_OPT__(_EX(_SI_UNIT_HELPER(primary, prefix, __VA_ARGS__)))

#define _SI_UNIT_HELPER(primary, prefix, alias, ...)                   \
    constexpr Unit prefix##alias = prefix##primary;                           \
    __VA_OPT__(_SI_UNIT_HELPER_2 PARENS (primary, prefix, __VA_ARGS__))

#define _SI_UNIT_HELPER_2() _SI_UNIT_HELPER

#define DEFINE_SI_UNIT(dimension, name, symbol, ...) \
    DEFINE_SINGLE_SI_UNIT(scale::base, dimension,, name, symbol, __VA_ARGS__) \
    \
    DEFINE_SINGLE_SI_UNIT(scale::quecto, dimension, quecto, name, q##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::ronto, dimension, ronto, name, r##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::yocto, dimension, yocto, name, y##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::zepto, dimension, zepto, name, z##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::atto, dimension, atto, name, a##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::femto, dimension, femto, name, f##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::pico, dimension, pico, name, p##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::nano, dimension, nano, name, n##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::micro, dimension, micro, name, µ##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::milli, dimension, milli, name, m##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::centi, dimension, centi, name, c##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::deci, dimension, deci, name, d##symbol, __VA_ARGS__) \
    \
    DEFINE_SINGLE_SI_UNIT(scale::deca, dimension, deca, name, da##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::hecto, dimension, hecto, name, h##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::kilo, dimension, kilo, name, k##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::mega, dimension, mega, name, M##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::giga, dimension, giga, name, G##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::tera, dimension, tera, name, T##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::peta, dimension, peta, name, P##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::exa, dimension, exa, name, E##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::zetta, dimension, zetta, name, Z##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::yotta, dimension, yotta, name, Y##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::ronna, dimension, ronna, name, R##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::quetta, dimension, quetta, name, Q##symbol, __VA_ARGS__)

#define DEFINE_SI_UNIT_NO_O(dimension, name, symbol, ...) \
    DEFINE_SINGLE_SI_UNIT(scale::base, dimension,, name, symbol, __VA_ARGS__) \
    \
    DEFINE_SINGLE_SI_UNIT(scale::quecto, dimension, quect, name, q##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::ronto, dimension, ront, name, r##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::yocto, dimension, yoct, name, y##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::zepto, dimension, zept, name, z##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::atto, dimension, att, name, a##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::femto, dimension, femt, name, f##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::pico, dimension, pic, name, p##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::nano, dimension, nan, name, n##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::micro, dimension, micr, name, µ##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::milli, dimension, milli, name, m##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::centi, dimension, centi, name, c##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::deci, dimension, deci, name, d##symbol, __VA_ARGS__) \
    \
    DEFINE_SINGLE_SI_UNIT(scale::deca, dimension, deca, name, da##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::hecto, dimension, hect, name, h##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::kilo, dimension, kil, name, k##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::mega, dimension, mega, name, M##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::giga, dimension, giga, name, G##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::tera, dimension, tera, name, T##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::peta, dimension, peta, name, P##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::exa, dimension, exa, name, E##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::zetta, dimension, zetta, name, Z##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::yotta, dimension, yotta, name, Y##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::ronna, dimension, ronna, name, R##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::quetta, dimension, quetta, name, Q##symbol, __VA_ARGS__)

#define DEFINE_SCALED_SI_UNIT(dimension, scale_offset, name, symbol, ...) \
    DEFINE_SINGLE_SI_UNIT(scale::base / scale_offset, dimension,, name, symbol, __VA_ARGS__) \
    \
    DEFINE_SINGLE_SI_UNIT(scale::quecto / scale_offset, dimension, quecto, name, q##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::ronto / scale_offset, dimension, ronto, name, r##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::yocto / scale_offset, dimension, yocto, name, y##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::zepto / scale_offset, dimension, zepto, name, z##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::atto / scale_offset, dimension, atto, name, a##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::femto / scale_offset, dimension, femto, name, f##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::pico / scale_offset, dimension, pico, name, p##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::nano / scale_offset, dimension, nano, name, n##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::micro / scale_offset, dimension, micro, name, µ##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::milli / scale_offset, dimension, milli, name, m##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::centi / scale_offset, dimension, centi, name, c##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::deci / scale_offset, dimension, deci, name, d##symbol, __VA_ARGS__) \
    \
    DEFINE_SINGLE_SI_UNIT(scale::deca / scale_offset, dimension, deca, name, da##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::hecto / scale_offset, dimension, hecto, name, h##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::kilo / scale_offset, dimension, kilo, name, k##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::mega / scale_offset, dimension, mega, name, M##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::giga / scale_offset, dimension, giga, name, G##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::tera / scale_offset, dimension, tera, name, T##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::peta / scale_offset, dimension, peta, name, P##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::exa / scale_offset, dimension, exa, name, E##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::zetta / scale_offset, dimension, zetta, name, Z##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::yotta / scale_offset, dimension, yotta, name, Y##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::ronna / scale_offset, dimension, ronna, name, R##symbol, __VA_ARGS__) \
    DEFINE_SINGLE_SI_UNIT(scale::quetta / scale_offset, dimension, quetta, name, Q##symbol, __VA_ARGS__)