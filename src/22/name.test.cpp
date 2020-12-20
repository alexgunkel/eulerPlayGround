#include "names.hpp"
#include "config.22.h"

#include "gtest/gtest.h"

TEST(NamesTest, testImport)
{
    std::filesystem::path file{dataFile};
    Names names{file};

    EXPECT_EQ(871198282, names.sum());
}
