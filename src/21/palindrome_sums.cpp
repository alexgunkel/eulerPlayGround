#include "palindrome_sums.hpp"
#include "../primes/factorizing.hpp"

#include <numeric>
#include <set>

std::optional<uint64_t> PalindromeSums::findFriend(uint64_t given) {
    const auto factorized = allDivisors<uint64_t>(given);
    const uint64_t sum = std::accumulate(factorized.begin(), factorized.end(), 0ul);

    const auto back = allDivisors(sum);
    const auto backSum = std::accumulate(back.begin(), back.end(), 0ul);

    return backSum == given ? std::optional<uint64_t >{sum} : std::nullopt;
}
uint64_t PalindromeSums::sumUp(uint64_t max) {
    uint64_t result{0};
    std::set<uint64_t> found{};

    for (int i = 1; i <= max; ++i) {
        if (!found.contains(i)) {
            if (const auto fr = findFriend(i); fr && fr.value() != i) {
                found.insert(fr.value());
                result += i + fr.value();
            }
        }
    }

    return result;
}
