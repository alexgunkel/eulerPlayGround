#include "distance_finder.hpp"

#include "gtest/gtest.h"

struct DistanceFinderSample {
    uint64_t fromTop;
    uint64_t position;
    uint64_t expected;
};

class DistanceFinderTest : public testing::TestWithParam<DistanceFinderSample> {
};

TEST_P(DistanceFinderTest, testNextDistance) {
    const auto sample{GetParam()};

    const DistanceFinder distanceFinder{sample.position, sample.fromTop};

    EXPECT_EQ(sample.expected,
              distanceFinder.next(sample.position, sample.fromTop));
}

INSTANTIATE_TEST_SUITE_P(InstantiationWithNormalCases, DistanceFinderTest,
                         testing::Values(//DistanceFinderSample{19, 17, 13},
                                         //DistanceFinderSample{19 + 17, 13, 0},
                                         //DistanceFinderSample{1110, 1108, 1104},
                                         DistanceFinderSample{2218, 1104, 1096},
                                         DistanceFinderSample{3322, 1096, 1080}));
