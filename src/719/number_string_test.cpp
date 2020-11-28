#include "number_string.h"

#include <gtest/gtest.h>

TEST(NumberStringTest, testInitialization) {
    NumberString<int,5> numberString{1234};

    EXPECT_EQ(4, numberString.at(4));
    EXPECT_EQ(3, numberString.at(3));
    EXPECT_EQ(2, numberString.at(2));
    EXPECT_EQ(1, numberString.at(1));
}

TEST(NumberStringTest, testSum) {
    using TestType = NumberString<int, 5>;
    EXPECT_EQ(8, TestType{224}.sum());
    EXPECT_EQ(4, TestType{004}.sum());
    EXPECT_EQ(6, TestType{224}.sum(2));
    EXPECT_EQ(2, TestType{224}.sum(1,1));
    EXPECT_EQ(9, TestType{3456}.sum(1,2));
}

TEST(NumberStringTest, testToInt) {
    using TestType = NumberString<int, 5>;

    EXPECT_EQ(1234, TestType{1234}.toInt());
    EXPECT_EQ(12, TestType{1234}.toInt(0,1));
    EXPECT_EQ(123, TestType{1234}.toInt(0,2));
    EXPECT_EQ(1234, TestType{1234}.toInt(0,3));
}
