#include "strategy.hpp"

#include <algorithm>
#include <cassert>

uint64_t Strategy::worstCase(uint64_t from, uint64_t to) {
    assert(from <= to);
    const uint64_t dist{to-from};
    if (!dist) {
        return 0;
    }

    if (dist == 1) {
        return from;
    }

    if (dist == 2) {
        return from+1;
    }

    const uint64_t pivot{(from+to+1) / 2};
    assert(from < pivot);
    assert(pivot < to);

    return pivot + std::max(worstCase(from, pivot - 1), worstCase(pivot + 1, to));
}
uint64_t Strategy::worstCase(uint64_t given) {
    if (given == 1) {
        return 0;
    }

    return worstCase(1, given);
}
