#ifndef EULERPLAYGROUND_STRATEGY_HPP
#define EULERPLAYGROUND_STRATEGY_HPP

#include <cinttypes>
#include <vector>

class Strategy {
  public:
    Strategy(uint64_t size);
    static uint64_t worstCase(uint64_t given);
    uint64_t at(uint64_t position) const;
    uint64_t sum(uint64_t until) const;

  private:
    static uint64_t worstCase(uint64_t from, uint64_t to);

    std::vector<uint64_t> cache_;
};

#endif // EULERPLAYGROUND_STRATEGY_HPP
