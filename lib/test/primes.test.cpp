#include "primes.hpp"

#include "gtest/gtest.h"

#include <numeric>

TEST(PrimesTest, testNumberOfPrimes)
{
    Generator generator{1'000'000};

    EXPECT_EQ(78498, generator.size());
}

TEST(FactorizingTest, testSmallSamples)
{
    const auto result{factorize(100ull)};

    EXPECT_EQ(2, result.size());
    EXPECT_EQ(2, result.at(2));
    EXPECT_EQ(2, result.at(5));
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

TEST(FactorizerTest, testBiggerRange)
{
    Factorizer fac{1000};
    for (uint64_t i = 1; i <= 1000; ++i) {
        const auto result{fac.factorize(i)};

        uint64_t sum{1};
        for (const auto& value : result) {
            sum *= value;
        }

        EXPECT_EQ(sum, i);
    }
}
