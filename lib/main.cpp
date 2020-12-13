#include "gcd.hpp"

#include <iostream>
#include <cinttypes>
#include <string>

int main()
{
    const uint64_t max{100};

    std::string trenner{","};
    std:: cout << 1;
    for (int j = 0; j <= max; ++j) {
        std::cout << trenner << j;
    }
    std::cout << "\n";

    for (uint64_t i = 1; i <= max; ++i) {
        std::cout << i;
        for (uint64_t j = 1; j <= max; ++j) {
            std::cout << trenner;
            if (i <= j) {
                std::cout << gcd(j, i) << "-" << gcd(2*j, i);
            }
        }

        std::cout << "\n";
        trenner = "";
    }
    return 0;
}
