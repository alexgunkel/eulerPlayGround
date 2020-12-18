#include "euler_coin.hpp"

#include "gtest/gtest.h"

TEST(EulerCoin, testFirst)
{
    EulerCoin eulerCoin{31, 117};
    const auto res{eulerCoin.first()};
    EXPECT_EQ(4, res.factor);
    EXPECT_EQ(7, res.next);
    EXPECT_EQ(31, res.previous);
}

TEST(EulerCoin, testNext)
{
    EulerCoin eulerCoin{31, 117};
    EulerCoin::Result given{.next=7, .previous=31, .factor=4};
    const auto result{eulerCoin.next(given)};

    EXPECT_LT(result.next, 7);
    EXPECT_EQ(result.previous, given.next);
    EXPECT_EQ((31*result.factor)%117, result.next);
}
