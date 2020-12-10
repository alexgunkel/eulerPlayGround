#include "modulo.hpp"

#include "gtest/gtest.h"

TEST(Modulo, testLog) {
    const auto res = log(2, 10);

    EXPECT_EQ(4, res.interval);
    EXPECT_EQ(16, res.power);
}

TEST(Modulo, testSimpleExamples) {
    Power<2, 10> power{100};

    EXPECT_EQ(4, power.get(2));
    EXPECT_EQ(6, power.get(4));

    EXPECT_EQ(5, (Power<5, 10>){10}.get(3));
    EXPECT_EQ(1539587653, (Power<2, 10'000'000'007>){10'000}.get(4'000));
}

struct SmallestMultiplesSample {
    uint64_t base;
    uint64_t modulo;
    uint64_t expected;
};
class SmallestMultipleTest
    : public testing::TestWithParam<SmallestMultiplesSample> {};

TEST_P(SmallestMultipleTest, testExamples) {
    const auto sample = GetParam();

    const auto result{findSmallestMultiple(sample.base, sample.modulo)};
    EXPECT_EQ(sample.expected, result);
}

INSTANTIATE_TEST_SUITE_P(TestSamples, SmallestMultipleTest,
                         testing::Values(SmallestMultiplesSample{3, 5, 1},
                                         SmallestMultiplesSample{3, 10, 1},
                                         SmallestMultiplesSample{4, 10, 2},
                                         SmallestMultiplesSample{8, 10, 2},
                                         SmallestMultiplesSample{9, 34, 1},
                                         SmallestMultiplesSample{999'998, 1'000'000, 2},
                                         SmallestMultiplesSample{8, 10, 2},
                                         SmallestMultiplesSample{101, 1002, 1}));
