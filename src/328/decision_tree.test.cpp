#include "decision_tree.hpp"

#include "gtest/gtest.h"

TEST(DecisionTreeTest, testEmpty) {
    DecisionTree leaf{2};

    EXPECT_EQ(2ul, leaf.max());
}

TEST(DecisionTreeTest, testNodes) {
    DecisionTree node{7,
                      std::make_unique<DecisionTree>(
                          5, std::make_unique<DecisionTree>(
                                 3, std::make_unique<DecisionTree>(1))),
                      std::make_unique<DecisionTree>(9)};

    EXPECT_EQ(16ul, node.max());
}

TEST(BuildTest, testSamples)
{
    const auto tree{DecisionTree::build(8)};

    EXPECT_EQ(5ul, tree.value());
    EXPECT_EQ(12, tree.max());
}

TEST(BuildTest, biggerSample)
{
    const auto tree{DecisionTree::build(100)};

    EXPECT_EQ(400ul, tree.max());
    EXPECT_EQ(85ul, tree.value());
}

class ExtenderTest : public testing::TestWithParam<std::tuple<uint64_t, uint64_t, uint64_t>> {};

TEST_P(ExtenderTest, testExtension)
{
    DecisionTree tree{std::get<0>(GetParam())};
    tree.extend(std::get<1>(GetParam()));

    EXPECT_EQ(std::get<2>(GetParam()), tree.max());
}

INSTANTIATE_TEST_SUITE_P(extensions, ExtenderTest, testing::Values(std::make_tuple(99, 96, 99+97)));


TEST(DecisionTreeTest, testMultipleExtension)
{
    DecisionTree tree{19};
    tree.extend(14);
    EXPECT_EQ(19u + 17u, tree.max());
    tree.extend(10);
    EXPECT_EQ(45ul, tree.max());
    tree.extend(6);
    EXPECT_EQ(50ul, tree.max());
    tree.extend(2);
    EXPECT_EQ(51ul, tree.max());
}

TEST(DecisionTreeTest, fromHundred)
{
    DecisionTree tree{99};

    for (int64_t i = 94; i >= 0; i -= 4) {
        tree.extend(i);
    }

    EXPECT_EQ(400, tree.max());
}
