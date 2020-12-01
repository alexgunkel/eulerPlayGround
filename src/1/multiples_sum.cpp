#include "multiples_sum.hpp"

#include <utility>

namespace eu1
{

MultiplesSum::MultiplesSum(std::vector<uint_fast64_t> factor) noexcept: factors_{std::move(factor)} {}
uint_fast64_t MultiplesSum::sumTill(uint_fast64_t limit) const {
    std::vector<bool> v(limit+1, false);
    uint_fast64_t sum{0};

    for (auto f : factors_) {
        for (auto it = f; it <= limit; it += f) {
            if (!v.at(it)) {
                v.at(it) = true;
                sum += it;
            }
        }
    }

    return sum;
}

}
