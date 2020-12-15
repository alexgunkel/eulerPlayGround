#include "gcd.hpp"
#include "primes.hpp"

#include <iostream>
#include <cinttypes>
#include <string>

int main()
{
    const uint64_t max{1'000'000};
    Generator generator{1'000'000};
    std::cout << generator.size() << " " << generator.last() << "\n";
    uint64_t maxLength{0};
    Factorizer factorizer{max};

    for (uint64_t i = 1; i < max; ++i) {
        std::cout << i << ": ";
        const auto res{factorizer.factorize(i)};

        for (const auto prim : res) {
            std::cout << prim << ", ";
        }

        std::cout << "\n";
    }

    std::cout << "\n" << maxLength << "\n";

    return 0;
}
