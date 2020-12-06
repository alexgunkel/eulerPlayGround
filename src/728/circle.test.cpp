#include "circle_of_coins.hpp"

#include "gtest/gtest.h"

TEST(CircleOfCoins, testGetReachables)
{
    CircleOfCoins circle(9, 3);

    const auto res = circle.reachableStates(0);

    EXPECT_EQ(4, res.size());
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
