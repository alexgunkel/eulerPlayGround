
#include "circle_of_coins.hpp"
#include "modulo.hpp"
#include "gcd.hpp"
#include "primes.hpp"
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

inline bool divisibleBy(uint64_t divided, uint64_t divisor)
{
    return (divided % divisor) == 0;
}
}

uint64_t CircleOfCoins::numberOfPossibleSolutions(uint64_t coins, uint64_t flips) const {
    return power_.get(numberOfPossibleSolutionsPower(coins, flips));
}

uint64_t CircleOfCoins::numberOfPossibleSolutionsPower(uint64_t coins, uint64_t flips) {
    if (coins == flips) {
        return 1;
    }

    if (odd(flips)) {
        const uint64_t gcd_{gcd(coins, flips)};
        return coins-gcd_+1;
    }


    if (uint64_t modulo = gcd(2*coins, flips); divisibleBy(coins, modulo)) {
        return coins-modulo+1;
    }

    return coins - gcd(coins, flips);
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

uint64_t CircleOfCoins::numberOfPossibleSolutionsForFLipNumber(uint64_t flips) const {
    uint64_t res{0};
    uint64_t lowerBound{flips};
    uint64_t upperBound{std::min((2*flips), maxSize_+1)};
    uint64_t part{0};
    for (uint64_t i = lowerBound; i < upperBound; ++i) {
        part += numberOfPossibleSolutions(i, flips);
        part %= mod;
    }
    uint64_t ratio{((maxSize_-lowerBound+1)/(upperBound-lowerBound))};
    for (int i = 0; i < ratio; ++i) {
        res += power_.get(i*lowerBound) * part;
        res %= mod;
    }
    for (uint64_t i = (maxSize_-lowerBound)+2; i <= maxSize_; ++i) {
        res += numberOfPossibleSolutions(i, flips);
        res %= mod;
    }

    uint64_t alternative{0};
    for (uint64_t i = 1; i <= flips; i++) {
        alternative += numberOfPossibleSolutions(maxSize_, i);
        alternative &= mod;
    }

    assert(alternative == res);

    return res;
}

uint64_t CircleOfCoins::numberOfPossibleSolutions() const {
    uint64_t compare{0};
    for (uint64_t coins = 1; coins <= maxSize_; coins++) {
        compare += numberOfPossibleSolutions(coins);
        compare %= mod;
    }

    return compare;
}
