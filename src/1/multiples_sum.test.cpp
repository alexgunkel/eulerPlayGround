#include "multiples_sum.hpp"

#include "gtest/gtest.h"

TEST(MultiplesSum, ExamplesTest) {
    eu1::MultiplesSum three{3u};

    EXPECT_EQ(18, three.sumTill(10));
    EXPECT_EQ(45, three.sumTill(15));
    EXPECT_EQ(23, eu1::MultiplesSum(3u, 5u).sumTill(9));
}
