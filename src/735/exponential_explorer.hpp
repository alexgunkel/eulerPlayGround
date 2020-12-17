
#ifndef EULERPLAYGROUND_EXPONENTIAL_EXPLORER_HPP
#define EULERPLAYGROUND_EXPONENTIAL_EXPLORER_HPP

#include <cinttypes>
#include <map>

class ExponentialExplorer {
  public:
    explicit ExponentialExplorer(uint64_t max);
    [[nodiscard]] uint64_t count(uint64_t root, uint64_t factor, uint64_t exp) const;
  private:
    uint64_t max_;
    mutable std::map<uint64_t, uint8_t> count_{};
};

#endif // EULERPLAYGROUND_EXPONENTIAL_EXPLORER_HPP
