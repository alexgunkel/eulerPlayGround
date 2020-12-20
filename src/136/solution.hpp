
#ifndef EULERPLAYGROUND_SOLUTION_HPP
#define EULERPLAYGROUND_SOLUTION_HPP

#include <cinttypes>

struct N
{
    int64_t v;
};

class Solution {
  public:
    Solution(int64_t x, int64_t y, int64_t z);
    Solution(int64_t x, int64_t y);
    Solution(N n, int64_t x);
    [[nodiscard]] bool solves(int64_t) const;

    int64_t x_;
    int64_t y_;
};

#endif // EULERPLAYGROUND_SOLUTION_HPP
