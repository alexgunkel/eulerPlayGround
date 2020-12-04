#include "truth_table.hpp"

#include "gtest/gtest.h"

#include <numeric>

TEST(TruthValueAssignment, testNext)
{
    using type = TruthValueAssigment<uint64_t, 6>;

    EXPECT_EQ(type{0}, ++type{0});
    EXPECT_EQ(type{2}, ++type{1});
    EXPECT_EQ(type{4}, ++type{2});
    EXPECT_EQ(type{1}, ++type{1u << 5u});
}

TEST(TruthTableChain, testMatrix)
{
    TruthTableChain<uint64_t, 6> chain{};

    const auto& m = chain.matrix();

    EXPECT_EQ(6, m.size());

    const auto total = std::accumulate(m.begin(), m.end(), 0, [](size_t carry, const auto& circle) -> size_t {
        return carry + circle.size();
    });

    EXPECT_EQ(64, total);
}
