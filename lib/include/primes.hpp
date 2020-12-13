#ifndef EULERPLAYGROUND_PRIMES_HPP
#define EULERPLAYGROUND_PRIMES_HPP

#include <map>

template <typename Integer>
std::map<Integer, Integer> factorize(Integer given)
{
    std::map<Integer, Integer> result{};

    Integer divisor{1};
    while (given > divisor++) {
        while (given % divisor == 0) {
            given /= divisor;
            result[divisor]++;
        }
    }

    return result;
}

template <typename Integer>
Integer power(Integer i, Integer exp)
{
    Integer result{1};
    while (exp--) {
        result *= i;
    }

    return result;
}

#endif // EULERPLAYGROUND_PRIMES_HPP
