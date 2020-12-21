#include "strategy.hpp"

#include "gtest/gtest.h"

namespace {
struct WorstCaseSample {
    uint64_t given;
    uint64_t expected;
};
std::ostream& operator<<(std::ostream& out, const WorstCaseSample& ws) {
    out << "given: " << ws.given << ", expected: " << ws.expected;

    return out;
}
} // namespace

class StrategyTest : public testing::TestWithParam<WorstCaseSample> {};

TEST_P(StrategyTest, worstCaseTest) {
    EXPECT_EQ(GetParam().expected, Strategy::worstCase(GetParam().given)) << GetParam();
}

INSTANTIATE_TEST_SUITE_P(worstCases, StrategyTest,
                         testing::Values(WorstCaseSample{1, 0},
                                         WorstCaseSample{2, 1},
                                         WorstCaseSample{3, 2},
                                         WorstCaseSample{4, 4},
                                         WorstCaseSample{5, 7},
                                         WorstCaseSample{6, 9},
                                         WorstCaseSample{7, 10},
                                         WorstCaseSample{8, 12},
                                         WorstCaseSample{9, 12},
                                         WorstCaseSample{100, 400}));
