#include "gcd.hpp"

uint64_t gcd(uint64_t left, uint64_t right)
{
    while (right) {
        uint64_t tmp = right;
        right = left % right;
        left = tmp;
    }

    return left;
}

uint64_t lcm(uint64_t first, uint64_t second)
{
    const auto g{gcd(first, second)};

    return first * (second/g);
}
