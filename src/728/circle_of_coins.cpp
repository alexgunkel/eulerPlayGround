
#include "circle_of_coins.hpp"
#include "gcd.hpp"
#include <cassert>
#include <set>

CircleOfCoins::CircleOfCoins(uint64_t coins, uint64_t flips)
    : coins_{coins}, flips_{flips}, coinMask_{(1ull << coins)-1}, operations_{} {
    operations_.reserve(coins_);
    for (uint64_t i = 0; i < coins_; i++) {
        const uint64_t mask = ((1ull << flips_) - 1) << i;

        operations_.push_back(normalize(mask));
    }
}

std::set<uint64_t> CircleOfCoins::reachableStates(uint64_t start) const {
    assert(start <= coinMask_);

    std::set<uint64_t> reached{start};

    for (const auto operation : operations_) {
        for (const auto value : reached) {
            reached.insert(normalize(value ^ operation));
        }
    }

    return reached;
}
uint64_t CircleOfCoins::normalize(uint64_t value) const {
    const uint64_t afterEnd = value >> coins_;

    return (value | afterEnd) & coinMask_;
}
uint64_t CircleOfCoins::numberOfPossibleSolutions() const {
    uint64_t mod = smallestModulo();
    uint64_t flipsCopy{mod};
    while (flipsCopy < coins_) {
        if (coins_ - flipsCopy > 1) {
            mod = std::min<uint64_t>(mod, coins_-flipsCopy+1);
        }

        flipsCopy += mod;
    }
    const auto pow = coins_ - mod;
    assert(pow < 63);

    return 2ull << pow;
}
uint64_t CircleOfCoins::smallestModulo() const {
    uint64_t res{flips_}, runner{flips_};
    const uint64_t max = 2*coins_;

    do {
        runner += flips_;
        runner %= max;

        if (runner) {
            res = std::min(res, runner);
        } else {
            res = std::min(res, flips_);
        }
    } while (runner != flips_);

    return res;
}
