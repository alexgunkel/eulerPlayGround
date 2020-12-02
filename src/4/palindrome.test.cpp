#include "palindrome_product.hpp"

#include "gtest/gtest.h"

TEST(Palindrome, checkTest) {
    EXPECT_TRUE(PalindromeProduct::check(1001));
    EXPECT_TRUE(PalindromeProduct::check(999));
    EXPECT_TRUE(PalindromeProduct::check(32123));
    EXPECT_TRUE(PalindromeProduct::check(2112));

    EXPECT_FALSE(PalindromeProduct::check(2113));
    EXPECT_FALSE(PalindromeProduct::check(21123));
    EXPECT_FALSE(PalindromeProduct::check(0212));
}

TEST(Challenge, TestLargest) {
    uint_fast64_t result{0};

    for (int i = 10; i < 100; ++i) {
        for (int j = 10; j < 100; ++j) {
            const auto product = i*j;
            if (PalindromeProduct::check(product)) {
                result = product;
            }
        }
    }

    EXPECT_EQ(9009, result);
}

TEST(Challenge, TestLargestReal) {
    uint_fast64_t result{0};

    for (int i = 100; i < 1000; ++i) {
        for (int j = 100; j < 1000; ++j) {
            const auto product = i*j;
            if (PalindromeProduct::check(product)) {
                result = product;
            }
        }
    }

    EXPECT_EQ(580085, result);
}
