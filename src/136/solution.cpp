#include "solution.hpp"

#include <cassert>
#include <exception>
#include <stdexcept>

Solution::Solution(int64_t x, int64_t y, int64_t z) : x_{x}, y_{y} {
    assert((x < y) == (y < z));
    assert(y - x == z - y);
    assert(z > 0);
}

Solution::Solution(int64_t x, int64_t y) : Solution{x, y, 2 * y - x} {}

bool Solution::solves(int64_t n) const {
    return y_ * (4 * x_ - 5 * y_) == n;
}

Solution::Solution(N n, int64_t y): x_{0}, y_{y} {
    if (n.v % y) {
        throw std::runtime_error{"not evenly dividable"};
    }

    const auto interim{n.v/y + 5*y};
    if (interim % 4) {
        throw std::runtime_error{"not a multiple of 4"};
    }

    x_ = interim / 4;
    assert(x_ > y_);
    assert(x_ < 2*y_);
}
