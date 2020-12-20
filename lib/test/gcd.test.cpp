#include "gcd.hpp"

#include "gtest/gtest.h"

TEST(GCD, testGcd)
{
    EXPECT_EQ(2, gcd(8, 6));
    EXPECT_EQ(2, gcd(6, 8));
    EXPECT_EQ(1, gcd(17, 11));
    EXPECT_EQ(4, gcd((4*17), 44));
}

TEST(LCM, testTwo)
{
    EXPECT_EQ(18u, lcm(6, 9));
    EXPECT_EQ(15u, lcm(3, 5));
}

TEST(LCM, testArray)
{
    std::array<uint64_t, 5> input{2, 3, 9, 12, 6};

    EXPECT_EQ(36, lcm(input.begin(), input.end()));
}

TEST(LCM, listOfValues)
{
    std::array<uint64_t, 10> input{0};
    std::iota(input.begin(), input.end(), 1ul);

    EXPECT_EQ(2520, lcm(input.begin(), input.end()));
}
TEST(LCM, listOf20Values)
{
    std::array<uint64_t, 20> input{0};
    std::iota(input.begin(), input.end(), 1ul);

    EXPECT_EQ(232792560, lcm(input.begin(), input.end()));
}
