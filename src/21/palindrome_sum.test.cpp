#include "palindrome_sums.hpp"

#include "gtest/gtest.h"

TEST(Palindrome, TestFriends) {
    const auto result = PalindromeSums::findFriend(220);

    EXPECT_TRUE(result);
    EXPECT_EQ(284, result.value());
}

TEST(Palindrome, AllLessEqual) {
    EXPECT_EQ(0, PalindromeSums::sumUp(9));
    EXPECT_EQ(0, PalindromeSums::sumUp(99));
    EXPECT_EQ(504, PalindromeSums::sumUp(999));
    EXPECT_EQ(31626, PalindromeSums::sumUp(9999));
}
