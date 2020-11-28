
#ifndef EULERPLAYGROUND_SIEVE_HPP
#define EULERPLAYGROUND_SIEVE_HPP

#include <cinttypes>

namespace eu_735 {
class Sieve {
public:
    using Result = uint_fast64_t;
    using Input = uint_fast64_t;
    static Result solve(Input input) ;
    static Result solveParallel(Input input) ;
};

} // namespace eu_735

#endif // EULERPLAYGROUND_SIEVE_HPP
