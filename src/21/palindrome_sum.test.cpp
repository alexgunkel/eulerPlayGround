#include "palindrome_sums.hpp"

#include "gtest/gtest.h"

TEST(Palindrome, TestFriends) {
    const auto result = PalindromeSums::findFriend(220);

    EXPECT_TRUE(result);
    EXPECT_EQ(284, result.value());
}

TEST(Palindrome, AllLessEqual) {
    uint64_t result{0};

    for (int i = 0; i < 10000; ++i) {
        if (const auto res = PalindromeSums::findFriend(i); res) {
            result += res.value();
        }
    }

    EXPECT_EQ(40284, result);
}
