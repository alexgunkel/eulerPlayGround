#ifndef EULERPLAYGROUND_GCD_HPP
#define EULERPLAYGROUND_GCD_HPP

#include <cinttypes>
#include <concepts>

#include <numeric>

uint64_t gcd(uint64_t left, uint64_t right);

uint64_t lcm(uint64_t first, uint64_t second);

template<std::input_iterator InputIt>
uint64_t lcm(InputIt first, InputIt end)
{
    uint64_t firstValue = *first;
    if (++first == end) {
        return firstValue;
    }

    return std::accumulate(first+1, end, *first, [](uint64_t first, uint64_t second) -> uint64_t {
      return lcm(first, second);
    });
}

#endif // EULERPLAYGROUND_GCD_HPP
