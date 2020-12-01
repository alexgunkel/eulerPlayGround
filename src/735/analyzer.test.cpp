
#include "analyzer.hpp"

#include <gtest/gtest.h>

TEST(AnalyzerTest, defaultCase) {
    eu_735::Analyzer analyzer{};
    EXPECT_EQ(3, analyzer.solve(3));
    EXPECT_EQ(8, analyzer.solve(15));
    EXPECT_EQ(27, analyzer.solve(1000));
    EXPECT_EQ(33, analyzer.solve(2000));
}

TEST(AnalyzerTest, defaultCaseParallel) {
    eu_735::Analyzer analyzer{};
    EXPECT_EQ(3, analyzer.solveParallel(3));
    EXPECT_EQ(3, analyzer.solveParallel(4));
    EXPECT_EQ(8, analyzer.solveParallel(15));
    EXPECT_EQ(27, analyzer.solveParallel(1000));
    EXPECT_EQ(33, analyzer.solveParallel(2000));
}
