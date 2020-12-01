#include "sieve.hpp"

#include <gtest/gtest.h>

TEST(SolverTest, defaultCase) {
    EXPECT_EQ(6, eu_735::Sieve{3}.solve());
    EXPECT_EQ(63, eu_735::Sieve{15}.solve());
    EXPECT_EQ(15066, eu_735::Sieve{1000}.solve());
    EXPECT_EQ(35193, eu_735::Sieve{2000}.solve());
}
