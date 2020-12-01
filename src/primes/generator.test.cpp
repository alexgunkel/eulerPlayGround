#include "generator.h"

#include "gtest/gtest.h"

TEST(GeneratorTest, testSmallPrimes) {
    primes::Generator generator{10};

    EXPECT_EQ(4, generator.size());
    EXPECT_EQ(7, generator.last());

    auto r = generator.generate();

    EXPECT_EQ(4, r.size());
    EXPECT_EQ(2, r[0]);
    EXPECT_EQ(3, r[1]);
    EXPECT_EQ(5, r[2]);
    EXPECT_EQ(7, r[3]);
}

TEST(GeneratorTest, testBiggerNumber) {
    primes::Generator generator{10000};

    EXPECT_EQ(1229, generator.size());
}
