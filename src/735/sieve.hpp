
#ifndef EULERPLAYGROUND_SIEVE_HPP
#define EULERPLAYGROUND_SIEVE_HPP

#include <cinttypes>
#include <vector>

namespace eu_735 {
class Sieve {
public:
    using Result = uint_fast64_t;
    using Input = uint_fast64_t;
    explicit Sieve(Input i);
    Result solve() ;

  private:
    Input length_;
    std::vector<Input> sieve_;
};

} // namespace eu_735

#endif // EULERPLAYGROUND_SIEVE_HPP
