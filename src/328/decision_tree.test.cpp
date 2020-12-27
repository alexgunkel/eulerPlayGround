#include "decision_tree.hpp"

#include "gtest/gtest.h"

struct BuilderTestSample {
    uint64_t max;
    uint64_t worstCaseCost;
    uint64_t firstLevel;
};

class DecisionTreeBuilderTest
    : public testing::TestWithParam<BuilderTestSample> {};

TEST_P(DecisionTreeBuilderTest, testSamples) {
    const auto tree{DecisionTree::build(GetParam().max)};

    EXPECT_EQ(GetParam().firstLevel, tree.value());
    EXPECT_EQ(GetParam().worstCaseCost, tree.max());
    EXPECT_EQ(GetParam().max, tree.upperBoundary());
    EXPECT_EQ(1ul, tree.lowerBoundary());
}

INSTANTIATE_TEST_SUITE_P(instantiateTrees, DecisionTreeBuilderTest,
                         testing::Values(BuilderTestSample{8, 12, 5},
                                         BuilderTestSample{100, 400, 85},
                                         BuilderTestSample{1'000, 6'753, 873}));

class ExtenderTest
    : public testing::TestWithParam<std::tuple<uint64_t, uint64_t, uint64_t>> {
};

TEST_P(ExtenderTest, testExtension) {
    DecisionTree tree{std::get<0>(GetParam())};
    tree.extend(std::get<1>(GetParam()));

    EXPECT_EQ(std::get<2>(GetParam()), tree.max());
}

INSTANTIATE_TEST_SUITE_P(extensions, ExtenderTest,
                         testing::Values(std::make_tuple(99, 96, 99 + 97)));

