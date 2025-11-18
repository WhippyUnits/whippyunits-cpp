// Copyright (c) whippyunits contributors

#pragma once

#include <cmath>
#include <format>
#include <string>

#include <catch2/matchers/catch_matchers_templated.hpp>

template <typename T>
struct WithinAbs: Catch::Matchers::MatcherGenericBase {
    WithinAbs(T target, T margin) : target{target}, margin{margin} {}

    bool match(const T& matchee) const {
        using std::abs;
        return abs(target - matchee) <= margin;
    }

    std::string describe() const override {
        return std::format("\n==\n{}", target);
    }

    private:
        T target;
        T margin;
};
