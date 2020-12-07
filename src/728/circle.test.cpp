#include "circle_of_coins.hpp"

#include "gtest/gtest.h"

TEST(CircleOfCoins, testGetReachables)
{
    CircleOfCoins circle(9, 6);

    std::vector<std::set<uint64_t>> res{};
    res.reserve(15);
    for (int i = 0; i < 15; ++i) {
        res.push_back(circle.reachableStates(i));
    }

    EXPECT_EQ(4, res.size());
}

TEST(CircleOfCoins, smallestModuloProduct) {
    EXPECT_EQ(1, CircleOfCoins(8, 3).smallestModulo());
    EXPECT_EQ(3, CircleOfCoins(9, 3).smallestModulo());
    EXPECT_EQ(6, CircleOfCoins(18, 6).smallestModulo());
    EXPECT_EQ(12, CircleOfCoins(18, 12).smallestModulo());
}

TEST(CircleOfCoins, numberOfPossibleSolutions)
{
    EXPECT_EQ(4, CircleOfCoins(2, 1).numberOfPossibleSolutions());
    EXPECT_EQ(4, CircleOfCoins(3, 2).numberOfPossibleSolutions());
    EXPECT_EQ(2, CircleOfCoins(3, 3).numberOfPossibleSolutions());
    EXPECT_EQ(128, CircleOfCoins(7, 3).numberOfPossibleSolutions());
    EXPECT_EQ(256, CircleOfCoins(8, 3).numberOfPossibleSolutions());
    EXPECT_EQ(128, CircleOfCoins(9, 3).numberOfPossibleSolutions());
}

uint64_t sumUpTo(uint64_t limit)
{
    uint64_t sum{0};

    for (uint64_t i = 1; i <= limit; ++i) {
        for (uint64_t j = 1; j <= i; ++j) {
            uint64_t next = CircleOfCoins(i, j).numberOfPossibleSolutions();
            sum += next;
        }
    }

    return sum;
}

TEST(CircleOfCoins, testAccumulation)
{
    EXPECT_EQ(22, sumUpTo(3));
    EXPECT_EQ(10444, sumUpTo(10));
}

TEST(CircleOfCoins, testDividables)
{
    EXPECT_EQ(1u << 18u, CircleOfCoins(18, 1).reachableStates(0).size());
    EXPECT_EQ(1u << 18u, CircleOfCoins(18, 1).numberOfPossibleSolutions());

    EXPECT_EQ(1u << 17u, CircleOfCoins(18, 2).reachableStates(0).size());
    EXPECT_EQ(1u << 17u, CircleOfCoins(18, 2).numberOfPossibleSolutions());

    EXPECT_EQ(1u << 16u, CircleOfCoins(18, 3).reachableStates(0).size());
    EXPECT_EQ(1u << 16u, CircleOfCoins(18, 3).numberOfPossibleSolutions());

    EXPECT_EQ(1u << 16u, CircleOfCoins(18, 4).reachableStates(0).size());
    EXPECT_EQ(1u << 16u, CircleOfCoins(18, 4).numberOfPossibleSolutions());

    EXPECT_EQ(1u << 18u, CircleOfCoins(18, 5).reachableStates(0).size());
    EXPECT_EQ(1u << 18u, CircleOfCoins(18, 5).numberOfPossibleSolutions());

    EXPECT_EQ(1u << 13u, CircleOfCoins(18, 6).reachableStates(0).size());
    EXPECT_EQ(1u << 13u, CircleOfCoins(18, 6).numberOfPossibleSolutions());

    EXPECT_EQ(1u << 16u, CircleOfCoins(18, 8).reachableStates(0).size());
    EXPECT_EQ(1u << 10u, CircleOfCoins(18, 9).reachableStates(0).size());
    EXPECT_EQ(1u << 17u, CircleOfCoins(18, 10).reachableStates(0).size());
}

TEST(CircleOfCoins, testSets)
{
    CircleOfCoins circleOfCoins(8, 4);
    const auto res = circleOfCoins.reachableStates(7);

    EXPECT_EQ(32, res.size());
}
