#include "palindrome_sums.hpp"
#include "../primes/factorizing.hpp"

#include <numeric>

std::optional<uint64_t> PalindromeSums::findFriend(uint64_t given) {
    const auto factorized = allDivisors<uint64_t>(given);
    const uint64_t sum = std::accumulate(factorized.begin(), factorized.end(), 0ul);

    const auto back = allDivisors(sum);
    const auto backSum = std::accumulate(back.begin(), back.end(), 0ul);

    return backSum == given ? std::optional<uint64_t >{sum} : std::nullopt;
}
