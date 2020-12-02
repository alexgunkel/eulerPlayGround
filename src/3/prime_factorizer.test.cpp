#include "prime_factorizer.h"

#include "gtest/gtest.h"

TEST(PrimeFac, TestSomeDefaultCases) {
    const uint_fast64_t given = 2*2 * 3 * 5*5*5 * 11;

    const auto res = PrimeFactorizer::factorize(given);

    EXPECT_EQ(2, res.at(2));
    EXPECT_EQ(1, res.at(3));
    EXPECT_EQ(3, res.at(5));
    EXPECT_EQ(1, res.at(11));
}

TEST(PrimeFac, TestHighest) {
    const auto res = PrimeFactorizer::factorize(13195);

    EXPECT_EQ(4, res.size());
    EXPECT_EQ(29, (--res.end())->first);
}

TEST(PrimeFac, Challenge) {
    const auto res = PrimeFactorizer::factorize(600851475143);

    EXPECT_EQ(6857, (--res.end())->first);
}
