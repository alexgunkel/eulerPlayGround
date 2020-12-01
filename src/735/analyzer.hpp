
#ifndef EULERPLAYGROUND_ANALYZER_HPP
#define EULERPLAYGROUND_ANALYZER_HPP

#include <cinttypes>

namespace eu_735 {
class Analyzer {
  public:
    using Result = uint_fast64_t;
    using Input = uint_fast64_t;
    static Result solve(Input input) ;
    static Result solveParallel(Input input) ;
};

} // namespace eu_735

#endif // EULERPLAYGROUND_ANALYZER_HPP
