#include "analyzer.hpp"
#include <cassert>
#include <cmath>
#include <numeric>
#include <tbb/tbb.h>
#include <vector>

namespace eu_735 {

namespace {
const Analyzer::Input maxPossible =
    std::sqrt(std::numeric_limits<Analyzer::Input>::max());
bool dividedBy(Analyzer::Input v, Analyzer::Input divisor) {
    if (auto mod = 2 % divisor; mod) {
        assert(std::numeric_limits<Analyzer::Input>::max() / mod > v);
        if (mod = (mod * v) % divisor; mod) {
            assert(std::numeric_limits<Analyzer::Input>::max() / mod > v);
            return (mod * v) % divisor == 0;
        }
    }

    return true;
}
} // namespace

Analyzer::Result Analyzer::solve(Analyzer::Input input) {
    std::vector<bool> Analyzer(input, true);
    for (auto it = Analyzer.begin(); it != Analyzer.end(); it++) {
        auto pos = it - Analyzer.begin() + 1;
        if (!dividedBy(input, pos)) {
            *it = false;
        }
    }

    return std::accumulate(Analyzer.begin(), Analyzer.end(), 0);
}
Analyzer::Result Analyzer::solveParallel(Analyzer::Input input) {
    bool* Analyzer = new bool[input];
    std::fill(Analyzer, Analyzer+input, true);

    tbb::parallel_for(
        tbb::blocked_range<Analyzer::Input>(0, input),
        [Analyzer, input](const tbb::blocked_range<Analyzer::Input> &range) {
          for (auto i = range.begin(); i < range.end(); ++i) {
              if (!dividedBy(input, i + 1)) {
                  Analyzer[i] = false;
              }
          }
        });

    auto res = std::accumulate(Analyzer, Analyzer+input, 0);
    delete [] Analyzer;

    return res;
}
} // namespace eu_735
