#include "truth_table.hpp"
#include <iostream>

int main()
{
    TruthTableChain<uint64_t, 6> chain{};

    for (const auto& circle : chain.matrix()) {
        for (const auto& entry : circle) {
            std::cout << int(entry) << " ";
        }

        std::cout << "total: " << circle.size() << "\n";
    }

    return 0;
}
