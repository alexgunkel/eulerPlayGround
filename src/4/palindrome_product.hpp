#ifndef EULERPLAYGROUND_PALINDROME_PRODUCT_HPP
#define EULERPLAYGROUND_PALINDROME_PRODUCT_HPP

#include <array>
#include <cinttypes>

class PalindromeProduct {
  public:
    static bool check(uint_fast64_t given) {
        std::array<uint8_t, 10> cache{0};
        auto it = cache.begin();
        while (given) {
            *(it++) = given % 10;
            given /= 10;
        }

        return std::equal(cache.begin(), it, std::reverse_iterator{it},
                          std::reverse_iterator{cache.begin()});
    };

    static uint_fast64_t largestProduct(const uint_fast64_t min, const uint_fast64_t max) {
        uint_fast64_t result{0};
        uint_fast64_t k, l;
        for (uint_fast64_t i = min; i <= max; i++) {
            for (uint_fast64_t j = i; j <= max; ++j) {
                if (const uint_fast64_t p = i*j; check(p) && p > result) {
                    result = p;
                    k = i; l = j;
                }
            }
        }

        return result;
    };
};

#endif // EULERPLAYGROUND_PALINDROME_PRODUCT_HPP
