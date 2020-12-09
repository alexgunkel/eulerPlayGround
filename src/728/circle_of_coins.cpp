
#include "circle_of_coins.hpp"
#include "modulo.hpp"
#include "gcd.hpp"
#include <cassert>
#include <set>

CircleOfCoins::CircleOfCoins(uint64_t coins, uint64_t flips)
    : CircleOfCoins{1ull << coins} {}

std::set<uint64_t> CircleOfCoins::reachableStates(uint64_t coins, uint64_t flips, uint64_t start) const {
    uint64_t coinMask{(1ull << coins)-1};
    assert(start <= coinMask);
    std::vector<uint64_t> operations{};
    operations.reserve(coins);
    for (uint64_t i = 0; i < coins; i++) {
        const uint64_t mask = ((1ull << flips) - 1) << i;

        operations.push_back(normalize(coins, mask));
    }

    std::set<uint64_t> reached{start};

    for (const auto operation : operations) {
        for (const auto value : reached) {
            reached.insert(normalize(coins, value ^ operation));
        }
    }

    return reached;
}
uint64_t CircleOfCoins::normalize(uint64_t coins, uint64_t value) {
    const uint64_t coinMask{(1ull << coins)-1};
    const uint64_t afterEnd = value >> coins;

    return (value | afterEnd) & coinMask;
}

uint64_t CircleOfCoins::numberOfPossibleSolutions(uint64_t coins, uint64_t flips) const {
    uint64_t mod = smallestModulo(coins, flips);
    uint64_t flipsCopy{mod};
    while (flipsCopy < coins) {
        if (1 + flipsCopy < coins) {
            mod = std::min<uint64_t>(mod, coins-flipsCopy+1);
        }

        flipsCopy += mod;
    }
    const auto pow = coins - mod;

    return power_.get(pow+1);
}

uint64_t CircleOfCoins::smallestModulo(uint64_t coins, uint64_t flips) {
    assert(coins >= flips);
    assert(flips > 0);

    uint64_t res{flips}, runner{flips};
    const uint64_t max = 2*coins;

    do {
        assert(runner < max);
        const uint64_t times = ((max-runner) / flips)+1;
        runner += flips*times;
        assert(runner >= max);
        runner %= max;

        if (runner) {
            res = std::min(res, runner);
        } else {
            res = std::min(res, flips);
        }
    } while (runner != flips && res > 1);

    return res;
}
CircleOfCoins::CircleOfCoins(uint64_t maxSize): power_{maxSize} {}
