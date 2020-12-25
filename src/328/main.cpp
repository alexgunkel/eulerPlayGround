#include "strategy.hpp"
#include <iostream>
#include <map>

int main() {
    constexpr uint64_t max{50};
    Strategy strategy{max};
    std::map<uint64_t, uint64_t> count{};

    for (uint64_t i = 2; i <= max; i++) {
        count[strategy.at(i) - strategy.at(i - 1)]++;
        std::cout << i << ") " << strategy.at(i) << "\n";
    }
}
