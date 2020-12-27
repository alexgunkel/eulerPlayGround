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

TEST_P(DecisionTreeBuilderTest, testCosts)
{
    const auto tree{DecisionTree::build(GetParam().max)};

    std::vector<uint64_t> results(GetParam().max, 0);

    uint64_t maximum{tree.max()};

    for (uint64_t i{1}; i <= GetParam().max; i++) {
        results[i-1] = tree.cost(i);
        EXPECT_LE(results[i-1], GetParam().worstCaseCost);
    }

    EXPECT_EQ(GetParam().max, results.size());
}

INSTANTIATE_TEST_SUITE_P(instantiateTrees, DecisionTreeBuilderTest,
                         testing::Values(BuilderTestSample{8, 12, 5},
                                         BuilderTestSample{100, 400, 85},
                                         BuilderTestSample{200, 900, 85},
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

