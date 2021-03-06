#include "number_splitting.h"
#include "gtest/gtest.h"

TEST(NumberSplittingTest, testSums) {
    std::map<std::string, std::vector<int>> samples;
    samples["1"] = {1};
    samples["12"] = {3, 12};
    samples["884"] = {20, 92, 92, 884};
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

TEST(NumberSplittingTest, testHasSum) {
    std::map<std::string, std::vector<int>> samples;
    samples["1"] = {1};
    samples["12"] = {3, 12};
    samples["884"] = {20, 92};
    samples["81"] = {9, 81};
    samples["124"] = {7, 16, 25, 124};
    samples["1234"] = {10, 19, 28, 37, 46, 127, 235, 1234};

    for (const auto& sample : samples) {
        for (const auto& correctSum : sample.second) {
            EXPECT_TRUE(hasSum<int>(sample.first, correctSum)) << sample.first << " not splittable to " << correctSum;
        }
    }
}

TEST(NumberSplittingTest, testHasNotSum) {
    std::map<std::string, std::vector<int>> samples;
    samples["1"] = {0};
    samples["12"] = {4, 11};
    samples["124"] = {72, 6, 5, 24};
    samples["1234"] = {100, 0};
    samples["1369"] = {37};

    for (const auto& sample : samples) {
        for (const auto& correctSum : sample.second) {
            EXPECT_FALSE(hasSum<int>(sample.first, correctSum)) << sample.first << " splittable to " << correctSum;
        }
    }
}

TEST(NumberSplittingTest, testCheckSum) {
    EXPECT_FALSE(hasCheckSum("1234", 1133));
    EXPECT_TRUE(hasCheckSum("1234", 19));
}

TEST(FromStringTest, testresults) {
    const char* in = "012345";

    EXPECT_EQ(12345, fromString<int>(in, 6));
    EXPECT_EQ(1234, fromString<int>(in, 5));
}

TEST(NumberSplittingChar, testCstrings) {
    EXPECT_TRUE(hasSum("222", 3, 6));
    EXPECT_TRUE(hasSum("222", 3, 24));
    EXPECT_TRUE(hasSum("222", 2, 4));
    EXPECT_TRUE(hasSum("222", 1, 2));
    EXPECT_TRUE(hasSum("222", 0, 0));
}

TEST(NumberStringHasSum, testHasSum) {
    using String = NumberString<int, 6>;

    EXPECT_TRUE((stringHasSum<int, 6>(String{1234}, 0, 4, 10)));
    EXPECT_TRUE((stringHasSum<int, 6>(String{1234}, 0, 6, 10)));
    EXPECT_TRUE((stringHasSum<int, 6>(String{1234}, 0, 3, 9)));
    EXPECT_TRUE((stringHasSum<int, 6>(String{1234}, 0, 2, 7)));
    EXPECT_TRUE((stringHasSum<int, 6>(String{1234}, 0, 1, 4)));
    EXPECT_TRUE((stringHasSum<int, 6>(String{1234}, 1, 4, 6)));
    EXPECT_TRUE((stringHasSum<int, 6>(String{1234}, 1, 3, 3)));
    EXPECT_TRUE((stringHasSum<int, 6>(String{1234}, 2, 4, 2)));
    EXPECT_TRUE((stringHasSum<int, 6>(String{12}, 0, 2, 12)));
}
