
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
    uint64_t times = (coins-1)/mod;
    if (uint64_t flipsCopy = times*mod; 1 + flipsCopy < coins) {
        mod = std::min<uint64_t>(mod, coins-flipsCopy+1);
    }
    const auto pow = coins - mod;

    return power_.get(pow+1);
}

uint64_t CircleOfCoins::smallestModulo(uint64_t coins, uint64_t flips) {
    assert(coins >= flips);
    assert(flips > 0);

    return findSmallestMultiple(flips, 2*coins);
}
CircleOfCoins::CircleOfCoins(uint64_t maxSize): maxSize_{maxSize}, power_{maxSize} {}
uint64_t CircleOfCoins::numberOfPossibleSolutions(uint64_t coins) const {
    uint64_t res{0};
    for (uint64_t i = 1; i <= coins; i++) {
        res += numberOfPossibleSolutions(coins, i);
        res %= mod;
    }

    return res;
}
uint64_t CircleOfCoins::numberOfPossibleSolutions() const {
    uint64_t res{0};
    for (uint64_t coins = 1; coins <= maxSize_; coins++) {
        res += numberOfPossibleSolutions(coins);
        res %= mod;
    }

    return res;
}
