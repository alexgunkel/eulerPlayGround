#include "solution.hpp"

#include "gtest/gtest.h"

TEST(Solution, testInit)
{
    Solution solution{4, 3};

    EXPECT_TRUE(solution.solves(4*4-3*3-2*2));
    EXPECT_FALSE(solution.solves(4*4-3*3));
}

TEST(FindSOlution, findSingle)
{
    const Solution solution{N{20}, 10};
    EXPECT_EQ(13, solution.x_);
}

TEST(FindSOlution, multiplesOfFour)
{
    std::set<uint32_t> found{};
    std::set<uint32_t> doubled{};
    for (int y = 10; y <=50'000'000; y++) {
        for (int64_t n = y; n <= 50'000'000; n += y) {
            const auto interim{n / y + 5* y};
            if ((interim % 4) || n/y >= 3*y) {
                continue;
            }
            
            if (found.contains(n)) {
                doubled.insert(n);
            } else {
                found.insert(n);
            }
        }
    }

    EXPECT_EQ(2544559ul, found.size() - doubled.size());
}
