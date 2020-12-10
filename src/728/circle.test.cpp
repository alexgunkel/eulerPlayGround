#include "circle_of_coins.hpp"

#include "gtest/gtest.h"

TEST(CircleOfCoins, testGetReachables)
{
    CircleOfCoins circle(14, 8);

    std::vector<std::set<uint64_t>> res{};
    res.reserve(15);
    for (int i = 0; i < 15; ++i) {
        res.push_back(circle.reachableStates(14, 8, i));
    }

    EXPECT_EQ(circle.numberOfPossibleSolutions(14, 8), res.at(0).size());
}

TEST(CircleOfCoins, smallestModuloProduct) {
    CircleOfCoins circleOfCoins{18, 1};
    EXPECT_EQ(1, circleOfCoins.smallestModulo(501, 101));
    EXPECT_EQ(1, circleOfCoins.smallestModulo(17, 9));
    EXPECT_EQ(1, circleOfCoins.smallestModulo(1'000'000, 999'999));
    EXPECT_EQ(2, circleOfCoins.smallestModulo(1'000'000, 999'998));
    EXPECT_EQ(1, circleOfCoins.smallestModulo(9, 5));
    EXPECT_EQ(4, circleOfCoins.smallestModulo(6, 4));
    EXPECT_EQ(4, circleOfCoins.smallestModulo(10, 4));
    EXPECT_EQ(2, circleOfCoins.smallestModulo(10, 6));
    EXPECT_EQ(3, circleOfCoins.smallestModulo(9, 3));
    EXPECT_EQ(4, circleOfCoins.smallestModulo(14, 8));
    EXPECT_EQ(6, circleOfCoins.smallestModulo(18, 6));
    EXPECT_EQ(9, circleOfCoins.smallestModulo(18, 9));
    EXPECT_EQ(12, circleOfCoins.smallestModulo(18, 12));
    EXPECT_EQ(18, circleOfCoins.smallestModulo(18, 18));
}

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
    EXPECT_EQ(853837042, sumUpTo(1'000'000));
}

TEST(CircleOfCoins, testAccumulationMethod)
{
    EXPECT_EQ(22, CircleOfCoins{3}.numberOfPossibleSolutions());
    EXPECT_EQ(10444, CircleOfCoins{10}.numberOfPossibleSolutions());
    EXPECT_EQ(853837042, CircleOfCoins{1000}.numberOfPossibleSolutions());
    EXPECT_EQ(813362526, CircleOfCoins{10'000}.numberOfPossibleSolutions());
}

TEST(CircleOfCoins, testDividables)
{
    CircleOfCoins circleOfCoins{2ull << 18ul};
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
