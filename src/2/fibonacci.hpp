
#ifndef EULERPLAYGROUND_FIBONACCI_HPP
#define EULERPLAYGROUND_FIBONACCI_HPP

#include <cinttypes>

namespace eu2 {
class Fibonacci {
  public:
    explicit Fibonacci(uint_fast64_t limit);
    [[nodiscard]] uint_fast64_t get() const noexcept;

  private:
    uint_fast64_t sum_{0};
};
}
#endif // EULERPLAYGROUND_FIBONACCI_HPP
