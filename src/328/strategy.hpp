#ifndef EULERPLAYGROUND_STRATEGY_HPP
#define EULERPLAYGROUND_STRATEGY_HPP

#include <cinttypes>

class Strategy {
  public:
    static uint64_t worstCase(uint64_t given);

  private:
    static uint64_t worstCase(uint64_t from, uint64_t to);
};

#endif // EULERPLAYGROUND_STRATEGY_HPP
