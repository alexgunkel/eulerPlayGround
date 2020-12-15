#include "analyzer.hpp"
#include "solver.hpp"
#include <iostream>
#include <string>
#include "primes.hpp"

int main(int argc, char** argv) {
    eu_735::Integer i{100};

    uint64_t count{0};
    std::map<uint64_t, uint64_t> real{};
    for (int j = 1; j <= i; ++j) {
        std::cout << j << ": ";
        for (int k = 1; k <= j; ++k) {
            if ((2*j*j) % k == 0) {
                std::cout << k << ", ";
                real[k]++;
            }
        }
        std::cout << "\n";
    }
    std::cout << "count: " << count << "\n";

    std::cout << "times\n";

    Generator generator{i};
    uint64_t sum = 0;
    std::map<uint64_t, uint64_t> counted{};
    counted[1] = i;
    counted[2] = i-1;
    for (const auto prime : generator.generate()) {
        if (prime < 3) {
            continue;
        }

        for (uint64_t cur = prime, p=1; cur <= i; cur = power<uint64_t>(prime, ++p)) {
            uint64_t add = (i - cur)/power<uint64_t>(prime, (p+1)/2) + 1;
            counted[cur] = add;
        }
    }

    for (uint64_t j = 1; j <= i; ++j) {
        std::cout << j << " real: " << real[j] << ", counted: " << counted[j] << "\n";
    }

    return 0;
}
