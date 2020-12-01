
#ifndef EULERPLAYGROUND_MULTIPLES_SUM_HPP
#define EULERPLAYGROUND_MULTIPLES_SUM_HPP

#include <cinttypes>
#include <vector>

namespace eu1 {
class MultiplesSum {
  public:
    explicit MultiplesSum(std::vector<uint_fast64_t> factors) noexcept;

    template <typename ...args>
    explicit MultiplesSum(args... a): MultiplesSum{std::vector<uint_fast64_t>{a...}} {};

    [[nodiscard]] uint_fast64_t sumTill(uint_fast64_t limit) const;

  private:
    std::vector<uint_fast64_t> factors_;
};
} // namespace eu1
#endif // EULERPLAYGROUND_MULTIPLES_SUM_HPP
