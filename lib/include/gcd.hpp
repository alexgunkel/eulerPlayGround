#ifndef EULERPLAYGROUND_GCD_HPP
#define EULERPLAYGROUND_GCD_HPP

#include <cinttypes>

uint64_t gcd(uint64_t left, uint64_t right)
{
    while (right) {
        uint64_t tmp = right;
        right = left % right;
        left = tmp;
    }

    return left;
}

#endif // EULERPLAYGROUND_GCD_HPP
