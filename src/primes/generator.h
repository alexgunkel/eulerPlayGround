#ifndef EULERPLAYGROUND_GENERATOR_H
#define EULERPLAYGROUND_GENERATOR_H

#include <cinttypes>
#include <vector>

namespace primes {
class Generator {
  public:
    explicit Generator(uint_fast64_t);
    std::vector<uint_fast64_t> generate() const;

  private:
    std::vector<bool> v_;
};
} // namespace primes

#endif // EULERPLAYGROUND_GENERATOR_H
