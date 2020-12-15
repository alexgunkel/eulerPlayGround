#include "exponential_explorer.hpp"

#include "primes.hpp"

#include <cassert>

ExponentialExplorer::ExponentialExplorer(uint64_t max): max_{max} {}
uint64_t ExponentialExplorer::count(uint64_t root, uint64_t factor, uint64_t exp) const {
    const uint64_t value{power(root, exp) * factor};
    if (value > max_) {
        return 0;
    }

    assert(count_.find(value) == count_.end());

    const uint64_t divisor{power(root, (exp+1)/2)*((factor+1)/2)};
    uint64_t add = (max_ - value)/divisor + 1;
    count_[value] = add;
    if (factor==1) {
        add += count(root, factor, exp+1);
    }
    add += count(root, 2*factor, exp);

    return add;
}
