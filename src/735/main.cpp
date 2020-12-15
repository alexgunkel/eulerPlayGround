#include "analyzer.hpp"
#include "solver.hpp"
#include <iostream>
#include <string>
#include "primes.hpp"

int main(int argc, char** argv) {
    eu_735::Integer i{100};

    uint64_t count{0};
    for (int j = 1; j <= i; ++j) {
        std::cout << j << ": ";
        for (int k = 1; k <= j; ++k) {
            if ((2*j*j) % k == 0) {
                std::cout << k << ", ";
                count++;
            }
        }
        std::cout << "\n";
    }
    std::cout << "count: " << count << "\n";

    std::cout << "times\n";

    Generator generator{i};
    uint64_t sum = 0;
    for (const auto prime : generator.generate()) {

        for (uint64_t cur = prime, p=1; cur <= i; cur = power<uint64_t>(prime, ++p)) {
            uint64_t add = (i - cur)/power<uint64_t>(prime, (p+1)/2) + 1;
            std::cout << prime << "  " << cur << ": " << add << "\n";
            sum += add;
        }
    }
    std::cout << sum << "\n";

    return 0;
}
