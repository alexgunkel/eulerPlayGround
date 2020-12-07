
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
    if (coins_ == flips_) {
        return 2ull;
    }

    if (gcd(flips_, coins_) > 2) {
        const uint64_t diff = std::min(flips_, coins_-flips_);
        return (1ull << (coins_-diff+1));
    }

    if (!(flips_ & 1ull)) {
        return 1ull << (coins_ - 1);
    }

    return 1ull << coins_;
}
