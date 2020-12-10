
#ifndef EULERPLAYGROUND_CIRCLE_OF_COINS_HPP
#define EULERPLAYGROUND_CIRCLE_OF_COINS_HPP

#include <cinttypes>
#include <vector>
#include <set>

#include "modulo.hpp"

class CircleOfCoins {
  public:
    CircleOfCoins(uint64_t coins, uint64_t flips);
    explicit CircleOfCoins(uint64_t maxSize);

    [[nodiscard]] std::set<uint64_t> reachableStates(uint64_t coins, uint64_t flips, uint64_t start) const;
    [[nodiscard]] uint64_t numberOfPossibleSolutions(uint64_t coins, uint64_t flips) const;
    [[nodiscard]] uint64_t numberOfPossibleSolutions(uint64_t coins) const;
    [[nodiscard]] uint64_t numberOfPossibleSolutions() const;
    [[nodiscard]] static uint64_t smallestModulo(uint64_t coins, uint64_t flips) ;

  private:
    static constexpr uint64_t mod{1'000'000'007};
    uint64_t maxSize_;
    Power<2u, mod> power_;

    [[nodiscard]] static uint64_t normalize(uint64_t coins, uint64_t value) ;
};

#endif // EULERPLAYGROUND_CIRCLE_OF_COINS_HPP
