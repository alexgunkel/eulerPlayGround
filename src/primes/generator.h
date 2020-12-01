#ifndef EULERPLAYGROUND_GENERATOR_H
#define EULERPLAYGROUND_GENERATOR_H

#include <cinttypes>
#include <vector>

namespace primes {
class Generator {
  public:
    explicit Generator(uint_fast64_t);
    [[nodiscard]] std::vector<uint_fast64_t> generate() const;
    [[nodiscard]] uint_fast64_t size() const;
    [[nodiscard]] uint_fast64_t last() const;

  private:
    size_t n_{0};
    uint_fast64_t last_{0};
    std::vector<bool> v_;
};
} // namespace primes

#endif // EULERPLAYGROUND_GENERATOR_H
