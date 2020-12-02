#ifndef EULERPLAYGROUND_FACTORIZING_HPP
#define EULERPLAYGROUND_FACTORIZING_HPP

#include <map>
#include <vector>

template <typename UnsignedInteger>
std::map<UnsignedInteger, UnsignedInteger> factorize(UnsignedInteger given)
{
    std::map<UnsignedInteger, UnsignedInteger> result{};
    UnsignedInteger index{1};

    while (++index <= given) {
        while (given % index == 0) {
            given /= index;
            result[index]++;
        }
    }

    return result;
}

template <typename UnsignedInteger>
std::vector<UnsignedInteger> allDivisors(UnsignedInteger given)
{
    std::vector<UnsignedInteger> result{};
    UnsignedInteger index{0};
    const auto threshold = given >> 1u;

    while (++index <= threshold) {
        if (given % index == 0) {
            result.push_back(index);
        }
    }

    return result;
}

#endif // EULERPLAYGROUND_FACTORIZING_HPP
