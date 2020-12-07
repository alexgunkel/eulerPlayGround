#include "circle_of_coins.hpp"
#include <iostream>
#include <bitset>

int run()
{
    uint64_t sum{0};
    for (uint64_t i = 1; i <= 10; ++i) {
        for (uint64_t j = 1; j <= i; ++j) {
            const CircleOfCoins circle(i, j);
            const uint64_t options = circle.numberOfPossibleSolutions();
            const auto reachables = circle.reachableStates(0ull);

            sum = (sum + reachables.size()) % 1'000'000'007;

            std::cout << i << ", " << j << ": " << options << ", " << reachables.size() << "\t\t" << circle.smallestModulo() << "\n";
        }

        std::cout << "\t\t\tafter " << i << ": " << sum << "\n";
    }

    std::cout << sum << "\n";
}

int print()
{
    CircleOfCoins circleOfCoins(14, 8);
    std::cout << circleOfCoins.numberOfPossibleSolutions() << "\n";

    for (uint64_t i = 0; i < 9; i++) {
        for (const auto state : circleOfCoins.reachableStates(i)) {
            std::cout << state << " : " << std::bitset<14>{state} << "\t";
        }
        std::cout << "\n";
    }

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
