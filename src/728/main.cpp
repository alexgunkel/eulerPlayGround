#include "circle_of_coins.hpp"
#include <iostream>
#include <bitset>

int run()
{
    const uint64_t stage{10*10*10*10*10*10*10};
    const CircleOfCoins circle{stage};
    uint64_t sum{0};
    for (uint64_t i = 1; i <= stage; ++i) {
        for (uint64_t j = 1; j <= i; ++j) {
            const uint64_t options = circle.numberOfPossibleSolutions(i, j);

            sum = (sum + options) % 1'000'000'007;
        }

        if (! (i % 1'000)) {
            std::cout << "\t\t\tafter " << i << ": " << sum << "\n";
        }
    }

    std::cout << sum << "\n";

    return 0;
}

int print()
{
    const uint64_t max{50};
    std::string sep{","};
    for (uint64_t i = 1; i <= max; i++) {
        std::cout << sep << i;
    }
    std::cout << "\n";

    for (uint64_t coins = 1; coins <= max; coins++) {
        std::cout << coins;
        for (uint64_t flips = 1; flips <= max; flips++) {
            std::cout << sep;
            if (flips <= coins) {
                const uint64_t pow{CircleOfCoins::numberOfPossibleSolutionsPower(coins, flips)};
                std::cout << (coins-pow) << "-" << pow;
            }
        }

        std::cout << "\n";
    }

    return 0;
}

int main()
{
    return print();
}

/**
 * 6-4 -2
 * 9-6 -3
 * 10-8 -2
 */
