#include "exponential_explorer.hpp"

#include "gtest/gtest.h"

TEST(ExponentialExplorerTest, testSingleSummary)
{
    ExponentialExplorer explorer{100};
    const auto result{explorer.count(3, 1, 1)};

    EXPECT_EQ(76, result);
}
