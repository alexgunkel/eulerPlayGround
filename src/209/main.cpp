#include "fibonacci.hpp"
#include "truth_table.hpp"
#include <iostream>
#include <numeric>
#include <cassert>

int main() {
    TruthTableChain<uint64_t, 6> chain{};
    eu::fibonacci::Generator generator{64};
    std::vector<uint_fast64_t> possibilities{};

    const auto& circles = chain.matrix();
    for (const auto &circle : circles) {
        for (const auto &entry : circle) {
            std::cout << int(entry) << " ";
        }

        const auto size = circle.size();
        std::cout << "total: " << size << "\n";
        const uint_fast64_t possible =
            generator.get(size) + (size < 2 ? 0 : generator.get(size - 2));
        possibilities.push_back(possible);
        std::cout << "possibility: " << possible << "\n";
    }

    assert(circles.size() == possibilities.size());

    const auto total = std::accumulate(
        possibilities.begin(), possibilities.end(), uint_fast64_t{1},
        std::multiplies<uint_fast64_t>{});

    std::cout << "result: " << total << "\n";

    return 0;
}
