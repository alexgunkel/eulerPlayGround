#include "fibonacci.hpp"

#include "gtest/gtest.h"

TEST(Fibonacci, TestsUntilTen) {
    // 1, 1, 2, 3, 5, 8, 13, 21, 34
    EXPECT_EQ(10, eu2::Fibonacci(10).get());
    EXPECT_EQ(44, eu2::Fibonacci(40).get());
}
