#include "circle_of_coins.hpp"

#include "gtest/gtest.h"

TEST(CircleOfCoins, numberOfPossibleSolutions)
{
    CircleOfCoins circle(20);
    for (uint64_t i = 1; i <= 20; ++i) {
        for (uint64_t j = 1; j <= i; ++j) {
            EXPECT_EQ(circle.reachableStates(i, j, 0).size(), circle.numberOfPossibleSolutions(i, j)) << i << " " << j;
        }
    }
}

uint64_t sumUpTo(uint64_t limit)
{
    uint64_t sum{0};
    CircleOfCoins circleOfCoins{limit};

    for (uint64_t i = 1; i <= limit; ++i) {
        sum += circleOfCoins.numberOfPossibleSolutions(i);
        sum %= 1'000'000'007;
    }

    return sum;
}

TEST(CircleOfCoins, testAccumulation)
{
    EXPECT_EQ(22, sumUpTo(3));
    EXPECT_EQ(10444, sumUpTo(10));
    EXPECT_EQ(853837042, sumUpTo(1000));
}

TEST(CircleOfCoins, testAccumulationMethod)
{
    EXPECT_EQ(356, CircleOfCoins{6}.numberOfPossibleSolutions());
    //EXPECT_EQ(22, CircleOfCoins{3}.numberOfPossibleSolutions());
    //EXPECT_EQ(10444, CircleOfCoins{10}.numberOfPossibleSolutions());
    //EXPECT_EQ(853837042, CircleOfCoins{1000}.numberOfPossibleSolutions());
    //EXPECT_EQ(813362526, CircleOfCoins{10'000}.numberOfPossibleSolutions());
}

TEST(CircleOfCoins, testFlipwise)
{
    EXPECT_EQ(0b1111110ull, CircleOfCoins{6}.numberOfPossibleSolutionsForFLipNumber(1));
    EXPECT_EQ(0b0111110ull, CircleOfCoins{6}.numberOfPossibleSolutionsForFLipNumber(2));
    EXPECT_EQ(0b0100010ull, CircleOfCoins{6}.numberOfPossibleSolutionsForFLipNumber(3));
}

TEST(CircleOfCoins, testDividables)
{
    CircleOfCoins circleOfCoins{2ull << 18ul};
    EXPECT_EQ(0b1000000ul, circleOfCoins.numberOfPossibleSolutions(6, 1));
    EXPECT_EQ(1u << 18u, circleOfCoins.reachableStates(18, 1, 0).size());
    EXPECT_EQ(1u << 18u, circleOfCoins.numberOfPossibleSolutions(18, 1));
    EXPECT_EQ(1u << 17u, circleOfCoins.reachableStates(18, 2, 0).size());
    EXPECT_EQ(1u << 17u, circleOfCoins.numberOfPossibleSolutions(18, 2));
    EXPECT_EQ(1u << 16u, circleOfCoins.reachableStates(18, 3, 0).size());
    EXPECT_EQ(1u << 16u, circleOfCoins.numberOfPossibleSolutions(18, 3));
    EXPECT_EQ(1u << 16u, circleOfCoins.reachableStates(18, 4, 0).size());
    EXPECT_EQ(1u << 16u, circleOfCoins.numberOfPossibleSolutions(18, 4));
    EXPECT_EQ(1u << 18u, circleOfCoins.reachableStates(18, 5, 0).size());
    EXPECT_EQ(1u << 18u, circleOfCoins.numberOfPossibleSolutions(18, 5));
    EXPECT_EQ(1u << 13u, circleOfCoins.reachableStates(18, 6, 0).size());
    EXPECT_EQ(1u << 13u, circleOfCoins.numberOfPossibleSolutions(18, 6));
}

TEST(CircleOfCoins, testSets)
{
    CircleOfCoins circleOfCoins(8, 4);
    const auto res = circleOfCoins.reachableStates(8, 4, 7);

    EXPECT_EQ(32, res.size());
}
