#include "prime_factorizer.h"

PrimeFactorizer::Result PrimeFactorizer::factorize(uint_fast64_t given) {
    PrimeFactorizer::Result result{};
    uint_fast64_t index{1};

    while (++index <= given) {
        while (given % index == 0) {
            result[index]++;
            given /= index;
        }
    }

    return result;
}
