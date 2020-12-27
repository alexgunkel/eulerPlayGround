#include "strategy.hpp"
#include <iostream>

int main() {
    constexpr uint64_t max{100};
    Strategy strategy{max};

    std::cout << strategy.sum(max) << "\n";
}
