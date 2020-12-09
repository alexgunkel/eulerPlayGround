
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
    [[nodiscard]] static uint64_t smallestModulo(uint64_t coins, uint64_t flips) ;

  private:
    Power<2u, 1'000'000'007> power_;

    [[nodiscard]] static uint64_t normalize(uint64_t coins, uint64_t value) ;
};

#endif // EULERPLAYGROUND_CIRCLE_OF_COINS_HPP
