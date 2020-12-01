#include "sieve.hpp"

namespace eu_735 {
Sieve::Sieve(Sieve::Input i): length_{i}, sieve_(i, 0) {
    const auto max{length_*length_*2};
    Input k, v;
    for (Input j = 1; j <= length_; ++j) {
        k = j;
        v = k*k;
        auto start{2*j*j};
        while (start <= max) {
            if (start % 2 == 0) {
                const auto half = start/2;
                while (v < half) {
                    k++;
                    v = k*k;
                }

                if (v == half) {
                    sieve_[k-1]++;
                }
            }
            start += j;
        }
    }
}

Sieve::Result Sieve::solve() {
    Sieve::Result res{};
    for (Input i = 1; i <= length_; i++) {
        res += sieve_[i-1];
    }

    return res;
}
} // namespace eu_735
