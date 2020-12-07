
#ifndef EULERPLAYGROUND_CIRCLE_OF_COINS_HPP
#define EULERPLAYGROUND_CIRCLE_OF_COINS_HPP

#include <cinttypes>
#include <vector>
#include <set>

class CircleOfCoins {
  public:
    CircleOfCoins(uint64_t coins, uint64_t flips);

    [[nodiscard]] std::set<uint64_t> reachableStates(uint64_t start) const;
    [[nodiscard]] uint64_t numberOfPossibleSolutions() const;
    uint64_t smallestModulo() const;

  private:
    uint64_t coins_;
    uint64_t flips_;
    uint64_t coinMask_;
    std::vector<uint64_t> operations_;

    [[nodiscard]] uint64_t normalize(uint64_t value) const;
};

#endif // EULERPLAYGROUND_CIRCLE_OF_COINS_HPP
