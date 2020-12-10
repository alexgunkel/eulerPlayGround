
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

namespace
{
inline bool even(uint64_t n)
{
    return 0 == n % 2;
}
inline bool odd(uint64_t n)
{
    return 1 == n% 2;
}
}

uint64_t CircleOfCoins::numberOfPossibleSolutions(uint64_t coins, uint64_t flips) const {
    if (coins == flips) {
        return power_.get(1);
    }

    const uint64_t gcd_ = gcd(coins, flips);

    if (odd(flips)) {
        return power_.get(coins-gcd_+1);
    }

    uint64_t modulo = gcd(2*coins, flips);

    if (gcd_==1 || modulo == gcd_) {
        return power_.get(coins-modulo+1);
    }

    return power_.get(coins - gcd_);
}

uint64_t CircleOfCoins::smallestModulo(uint64_t coins, uint64_t flips) {
    assert(coins >= flips);
    assert(flips > 0);

    return gcd(flips, 2*coins);
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
