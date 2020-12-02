#ifndef EULERPLAYGROUND_PALINDROME_PRODUCT_HPP
#define EULERPLAYGROUND_PALINDROME_PRODUCT_HPP

#include <array>
#include <cinttypes>

class PalindromeProduct {
  public:
    static bool check(uint_fast64_t given) {
        std::array<uint8_t, 5> cache{0};
        size_t pos{0};
        auto it = cache.begin();
        while (given) {
            *(it++) = given % 10;
            given /= 10;
        }

        return std::equal(cache.begin(), it, std::reverse_iterator{it},
                          std::reverse_iterator{cache.begin()});
    };
};

#endif // EULERPLAYGROUND_PALINDROME_PRODUCT_HPP
