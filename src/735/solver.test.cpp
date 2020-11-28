#include "solver.hpp"

#include <gtest/gtest.h>

TEST(SolverTest, DefaultExamples) {
    eu_735::Solver solver{};

    EXPECT_EQ(63, solver.solve(15));
    EXPECT_EQ(15066, solver.solve(1e3));
}

TEST(SolverTest, DefaultExamplesParallel) {
    eu_735::Solver solver{};

    EXPECT_EQ(63, solver.solveParallel(15));
    EXPECT_EQ(15066, solver.solveParallel(1e3));
}
