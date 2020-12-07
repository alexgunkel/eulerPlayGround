#include "circle_of_coins.hpp"
#include <iostream>
#include <bitset>

int run()
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

int main()
{
    CircleOfCoins circleOfCoins{18, 6};
    CircleOfCoins circleOfCoins2{18, 12};
    auto res = circleOfCoins.reachableStates(0);
    auto res2 = circleOfCoins2.reachableStates(0);
    std::vector<uint64_t> diff{};
    diff.reserve(res.size() - res2.size());
    std::set_difference(res.begin(), res.end(), res2.begin(), res2.end(), diff.begin());

    for (const auto& state : res) {
        if (!res2.contains(state)) {
            std::cout << std::bitset<32>{state} << "\n";
        }
    }
    return 0;
}
