#include "gcd.hpp"

#include "gtest/gtest.h"

TEST(GCD, testGcd)
{
    EXPECT_EQ(2, gcd(8, 6));
    EXPECT_EQ(2, gcd(6, 8));
    EXPECT_EQ(1, gcd(17, 11));
    EXPECT_EQ(4, gcd((4*17), 44));
}
