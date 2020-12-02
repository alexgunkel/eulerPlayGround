#ifndef EULERPLAYGROUND_PALINDROME_SUMS_HPP
#define EULERPLAYGROUND_PALINDROME_SUMS_HPP

#include <cinttypes>
#include <optional>

class PalindromeSums {
  public:
    static std::optional<uint64_t> findFriend(uint64_t given);
    static uint64_t sumUp(uint64_t max);
};

#endif // EULERPLAYGROUND_PALINDROME_SUMS_HPP
