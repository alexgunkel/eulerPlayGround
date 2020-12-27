#include "strategy.hpp"

#include "gtest/gtest.h"

namespace strategy::test {
struct WorstCaseSample {
    uint64_t given;
    uint64_t expected;
};
std::ostream &operator<<(std::ostream &out, const WorstCaseSample &ws) {
    out << "given: " << ws.given << ", expected: " << ws.expected;

    return out;
}
} // namespace strategy::test

using strategy::test::WorstCaseSample;

class StrategySumTest : public testing::TestWithParam<WorstCaseSample> {};

TEST_P(StrategySumTest, testTotalSum) {
    Strategy strategy{GetParam().given};

    EXPECT_EQ(GetParam().expected, strategy.sum(GetParam().given));
}

INSTANTIATE_TEST_SUITE_P(
    testTotalSum, StrategySumTest,
    testing::Values(WorstCaseSample{100, 17'575}, WorstCaseSample{8, 43}
                    ,WorstCaseSample{200'000, 261'019'124'465}
 ));

class StrategyTest : public testing::TestWithParam<WorstCaseSample> {};

TEST_P(StrategyTest, objectOrientedVersion) {
    Strategy strategy{GetParam().given};
    auto result = strategy.at(GetParam().given);
    EXPECT_EQ(GetParam().expected, result) << GetParam();
}

INSTANTIATE_TEST_SUITE_P(
    worstCases, StrategyTest,
    testing::Values(WorstCaseSample{1, 0}, WorstCaseSample{2, 1},
                    WorstCaseSample{3, 2}, WorstCaseSample{4, 4},
                    WorstCaseSample{5, 6}, WorstCaseSample{6, 8},
                    WorstCaseSample{7, 10}, WorstCaseSample{8, 12},
                    WorstCaseSample{9, 14}, WorstCaseSample{10, 16},
                    WorstCaseSample{11, 18}, WorstCaseSample{12, 21},
                    WorstCaseSample{13, 24}, WorstCaseSample{14, 27},
                    WorstCaseSample{15, 30}, WorstCaseSample{16, 34},
                    WorstCaseSample{17, 38}, WorstCaseSample{18, 42},
                    WorstCaseSample{19, 46}, WorstCaseSample{20, 49},
                    WorstCaseSample{21, 52}, WorstCaseSample{22, 55},
                    WorstCaseSample{23, 58}, WorstCaseSample{24, 61},
                    WorstCaseSample{25, 64}, WorstCaseSample{26, 67},
                    WorstCaseSample{30, 79}, WorstCaseSample{100, 400},
                    WorstCaseSample{1000, 6753}));
