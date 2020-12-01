
#include "fibonacci.hpp"
#include <array>

namespace
{
template <uint8_t factor>
struct position
{
    uint8_t pos;
    position operator+(uint8_t r) const {
        return position{static_cast<uint8_t>((pos + r) % factor)};
    }
    explicit operator int() const {
        return pos;
    }
};
}

eu2::Fibonacci::Fibonacci(uint_fast64_t limit) {
    std::array<uint_fast64_t, 3> cache{1, 1, 2};
    position<3> pos{2};

    while (cache.at(int(pos)) <= limit) {
        if (!(cache.at(int(pos)) & 1u)) {
            sum_ += cache.at(int(pos));
        }

        pos = pos + 1;
        cache.at(int(pos)) = cache.at(int(pos + 1)) + cache.at(int(pos + 2));
    }
}
uint_fast64_t eu2::Fibonacci::get() const noexcept { return sum_; }
