#include "sieve.hpp"
#include <cassert>
#include <cmath>
#include <numeric>
#include <tbb/tbb.h>
#include <vector>

namespace eu_735 {

namespace {
const Sieve::Input maxPossible =
    std::sqrt(std::numeric_limits<Sieve::Input>::max());
bool dividedBy(Sieve::Input v, Sieve::Input divisor) {
    if (auto mod = 2 % divisor; mod) {
        assert(std::numeric_limits<Sieve::Input>::max() / mod > v);
        if (mod = (mod * v) % divisor; mod) {
            assert(std::numeric_limits<Sieve::Input>::max() / mod > v);
            return (mod * v) % divisor == 0;
        }
    }

    return true;
}
} // namespace

Sieve::Result Sieve::solve(Sieve::Input input) {
    std::vector<bool> sieve(input, true);
    for (auto it = sieve.begin(); it != sieve.end(); it++) {
        auto pos = it - sieve.begin() + 1;
        if (!dividedBy(input, pos)) {
            *it = false;
        }
    }

    return std::accumulate(sieve.begin(), sieve.end(), 0);
}
Sieve::Result Sieve::solveParallel(Sieve::Input input) {
    bool* sieve = new bool[input];
    std::fill(sieve, sieve+input, true);

    tbb::parallel_for(
        tbb::blocked_range<Sieve::Input>(0, input),
        [sieve, input](const tbb::blocked_range<Sieve::Input> &range) {
            for (auto i = range.begin(); i < range.end(); ++i) {
                if (!dividedBy(input, i + 1)) {
                    sieve[i] = false;
                }
            }
        });

    auto res = std::accumulate(sieve, sieve+input, 0);
    delete [] sieve;

    return res;
}
} // namespace eu_735
