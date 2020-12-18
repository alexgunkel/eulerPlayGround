#include "euler_coin.hpp"

#include "gtest/gtest.h"
#include <deque>
#include <queue>

TEST(EulerCoin, testFirst)
{
    EulerCoin eulerCoin{1'504'170'715'041'707, 4'503'599'627'370'517};
    std::deque<uint64_t> expectedContainer{
        8912517754604,
        2044785486369,
        1311409677241,
        578033868113,
        422691927098,
        267349986083,
        112008045068,
        68674149121,
        25340253174,
        7346610401,
        4046188430,
        745766459,
        428410324,
        111054189,
    };
    std::queue expectedList{expectedContainer};

    auto res{eulerCoin.first()};
    EXPECT_EQ(1, res.factor);
    EXPECT_EQ(1'504'170'715'041'707, res.value);
    EXPECT_EQ(0, res.previous);

    while (!expectedList.empty()) {
        auto expected{expectedList.front()};
        expectedList.pop();

        res = eulerCoin.next(res);
        EXPECT_EQ(expected, res.value);
    }
}

class EulerCoinTest : public testing::TestWithParam<std::tuple<uint64_t, uint64_t>>
{};

TEST_P(EulerCoinTest, testPlausibilityOfFirst)
{
    const auto factor{std::get<0>(GetParam())};
    const auto mod{std::get<1>(GetParam())};
    EulerCoin eulerCoin{factor, mod};

    auto result{eulerCoin.first()};
    while (result) {
        EXPECT_EQ(result.value, (result.factor * factor) % mod);
        result = eulerCoin.next(result);
    }
}

INSTANTIATE_TEST_SUITE_P(factorsAndMods, EulerCoinTest, testing::Combine(testing::Range(7ul, 59ul), testing::Range(61ul, 113ul)));
