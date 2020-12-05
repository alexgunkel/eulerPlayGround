#include "fibonacci.hpp"

#include "gtest/gtest.h"

TEST(Fibonacci, TestsUntilTen) {
    // 1, 1, 2, 3, 5, 8, 13, 21, 34
    eu::fibonacci::Generator generator{40};

    EXPECT_EQ(8, generator.greatest(10));
    EXPECT_EQ(34, generator.greatest(40));
}

TEST(Fibonacci, testPositions)
{
    eu::fibonacci::Generator generator{10};

    EXPECT_EQ(1, generator.get(0));
    EXPECT_EQ(1, generator.get(1));
    EXPECT_EQ(2, generator.get(2));
    EXPECT_EQ(3, generator.get(3));
    EXPECT_EQ(5, generator.get(4));
    EXPECT_EQ(8, generator.get(5));
}
