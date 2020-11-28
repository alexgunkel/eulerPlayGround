
#ifndef EULERPLAYGROUND_SOLVER_HPP
#define EULERPLAYGROUND_SOLVER_HPP

#include <cinttypes>

namespace eu_735 {
using Integer = uint_fast64_t ;
class Solver {
  public:
    static Integer solve(Integer input);
    static Integer solveParallel(Integer input);
};
} // namespace eu_735
#endif // EULERPLAYGROUND_SOLVER_HPP
