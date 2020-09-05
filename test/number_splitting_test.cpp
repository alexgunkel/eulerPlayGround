#include "number_splitting.h"
#include "gtest/gtest.h"

TEST(NumberSplittingTest, testSums) {
    std::map<std::string, std::vector<int>> samples;
    samples["1"] = {1};
    samples["12"] = {3, 12};
    samples["124"] = {7, 16, 25, 124};
    samples["1234"] = {10, 19, 28, 37, 46, 127, 235, 1234};

    for (const auto& sample : samples) {
        auto result = calculateSums<int>(sample.first);

        std::sort(result.begin(), result.end());

        EXPECT_EQ(sample.second, result);
    }
}

TEST(NumberSplittingTest, testSplitting) {
    std::map<int, bool> samples;
    samples[19] = true;
    samples[1234] = true;
    samples[1239] = false;
    samples[0] = false;

    for (const auto& sample : samples) {
        EXPECT_EQ(sample.second, hasSplittingTo<int>(1234, sample.first));
    }
}
