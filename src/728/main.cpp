#include "circle_of_coins.hpp"
#include <iostream>

int main()
{
    uint64_t sum{0};
    for (uint64_t i = 1; i <= 20; ++i) {
        for (uint64_t j = 1; j <= i; ++j) {
            const CircleOfCoins circle(i, j);
            const uint64_t options = circle.numberOfPossibleSolutions();
            const auto reachables = circle.reachableStates(0ull);

            sum = (sum + reachables.size()) % 1'000'000'007;

            std::cout << i << ", " << j << ": " << options << ", " << reachables.size() << "\n";
        }

        std::cout << "\t\t\tafter " << i << ": " << sum << "\n";
    }

    std::cout << sum << "\n";
}
