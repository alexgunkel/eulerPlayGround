#include "primes.hpp"

#include "gtest/gtest.h"

#include <numeric>

TEST(FactorizingTest, testSmallSamples)
{
    const auto result{factorize(100ull)};

    EXPECT_EQ(2, result.size());
    EXPECT_EQ(2, result.at(2));
    EXPECT_EQ(2, result.at(5));
}

TEST(FactorizingTest, testBigExample)
{
    const auto result{factorize(1'000'000'007ull)};

    EXPECT_EQ(13, result.size());
}

TEST(FactorizingTest, testBiggerRange)
{
    for (uint64_t i = 1; i < 1000; ++i) {
        const auto result{factorize(i)};

        uint64_t sum{1};
        for (const auto& [key, value] : result) {
            sum *= power(key, value);
        }

        EXPECT_EQ(sum, i);
    }
}
