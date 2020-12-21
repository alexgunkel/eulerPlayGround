#ifndef EULERPLAYGROUND_STRATEGY_HPP
#define EULERPLAYGROUND_STRATEGY_HPP

#include <cinttypes>
#include <vector>

class Strategy {
  public:
    explicit Strategy(uint64_t size);
    [[nodiscard]] uint64_t at(uint64_t position) const;
    [[nodiscard]] uint64_t sum(uint64_t until) const;

  private:
    std::vector<uint64_t> cache_;
};

#endif // EULERPLAYGROUND_STRATEGY_HPP
