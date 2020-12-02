#ifndef EULERPLAYGROUND_PRIME_FACTORIZER_H
#define EULERPLAYGROUND_PRIME_FACTORIZER_H

#include <cinttypes>
#include <map>

class PrimeFactorizer {
  public:
    using Result = std::map<uint_fast64_t, uint_fast64_t>;
    static Result factorize(uint_fast64_t);
};

#endif // EULERPLAYGROUND_PRIME_FACTORIZER_H
