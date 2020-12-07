#include "circle_of_coins.hpp"

#include "gtest/gtest.h"

TEST(CircleOfCoins, testGetReachables)
{
    CircleOfCoins circle(14, 8);

    std::vector<std::set<uint64_t>> res{};
    res.reserve(15);
    for (int i = 0; i < 15; ++i) {
        res.push_back(circle.reachableStates(i));
    }

    EXPECT_EQ(circle.numberOfPossibleSolutions(), res.at(0).size());
}

TEST(CircleOfCoins, smallestModuloProduct) {
    EXPECT_EQ(4, CircleOfCoins(6, 4).smallestModulo());
    EXPECT_EQ(4, CircleOfCoins(10, 4).smallestModulo());
    EXPECT_EQ(2, CircleOfCoins(10, 6).smallestModulo());
    EXPECT_EQ(3, CircleOfCoins(9, 3).smallestModulo());
    EXPECT_EQ(4, CircleOfCoins(14, 8).smallestModulo());
    EXPECT_EQ(6, CircleOfCoins(18, 6).smallestModulo());
    EXPECT_EQ(12, CircleOfCoins(18, 12).smallestModulo());
    EXPECT_EQ(18, CircleOfCoins(18, 18).smallestModulo());
}

TEST(CircleOfCoins, numberOfPossibleSolutions)
{
    for (uint64_t i = 1; i <= 20; ++i) {
        for (uint64_t j = 1; j <= i; ++j) {
            CircleOfCoins circle(i, j);
            EXPECT_EQ(circle.reachableStates(0).size(), circle.numberOfPossibleSolutions()) << i << " " << j << " " << circle.smallestModulo();
        }
    }
}

uint64_t sumUpTo(uint64_t limit)
{
    uint64_t sum{0};

    for (uint64_t i = 1; i <= limit; ++i) {
        for (uint64_t j = 1; j <= i; ++j) {
            uint64_t next = CircleOfCoins(i, j).numberOfPossibleSolutions();
            sum += next;
            sum %= 1'000'000'007;
        }
    }

    return sum;
}

TEST(CircleOfCoins, testAccumulation)
{
    EXPECT_EQ(22, sumUpTo(3));
    EXPECT_EQ(10444, sumUpTo(10));
    EXPECT_EQ(853837042, sumUpTo(1000));
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
