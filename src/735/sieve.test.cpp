#include "sieve.hpp"

#include <gtest/gtest.h>

TEST(SolverTest, defaultCase) {
    eu_735::Sieve sieve{};

    EXPECT_EQ(6, sieve.solve(10));
    EXPECT_EQ(8, sieve.solve(15));
    EXPECT_EQ(14, sieve.solve(100));
    EXPECT_EQ(27, sieve.solve(1e3));
    EXPECT_EQ(43, sieve.solve(1e4));
    EXPECT_EQ(64, sieve.solve(1e5));
    EXPECT_EQ(88, sieve.solve(1e6));
    EXPECT_EQ(117, sieve.solve(1e7));
    EXPECT_EQ(150, sieve.solve(1e8));
    EXPECT_EQ(186, sieve.solve(1e9));
}

TEST(SolverTest, defaultCaseParallel) {
    eu_735::Sieve sieve{};

    EXPECT_EQ(6, sieve.solveParallel(10));
    EXPECT_EQ(8, sieve.solveParallel(15));
    EXPECT_EQ(14, sieve.solveParallel(100));
    EXPECT_EQ(27, sieve.solveParallel(1e3));
    EXPECT_EQ(43, sieve.solveParallel(1e4));
    EXPECT_EQ(64, sieve.solveParallel(1e5));
    EXPECT_EQ(88, sieve.solveParallel(1e6));
    EXPECT_EQ(117, sieve.solveParallel(1e7));
    EXPECT_EQ(150, sieve.solveParallel(1e8));
    EXPECT_EQ(186, sieve.solveParallel(1e9));
}
