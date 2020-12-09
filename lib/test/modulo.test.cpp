#include "modulo.hpp"

#include "gtest/gtest.h"

TEST(Modulo, testLog)
{
    const auto res = log(2, 10);

    EXPECT_EQ(4, res.interval);
    EXPECT_EQ(16, res.power);
}

TEST(Modulo, testSimpleExamples)
{
    Power<2, 10> power{100};

    EXPECT_EQ(4, power.get(2));
    EXPECT_EQ(6, power.get(4));

    EXPECT_EQ(5, (Power<5, 10>){10}.get(3));
}
