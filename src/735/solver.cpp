#include "solver.hpp"

#include "analyzer.hpp"

#include <cassert>
#include <tbb/tbb.h>

namespace eu_735 {
Integer Solver::solve(Integer input) {
    Integer res{};

    for (Integer i = 0; i <= input; i++) {
        res += Analyzer::solve(i);
    }

    return res;
}
Integer Solver::solveParallel(Integer input) {
    Integer res{};

    res = tbb::parallel_reduce(
        tbb::blocked_range<Integer>(1, input + 1), 0,
        [](const tbb::blocked_range<Integer> &range, Integer given) {
            for (auto i = range.begin(); i < range.end(); i++) {
                assert(given < std::numeric_limits<decltype(given)>::max() / 2);
                given += Analyzer::solveParallel(i);
            }

            return given;
        },
        std::plus<>{});

    return res;
}
} // namespace eu_735
