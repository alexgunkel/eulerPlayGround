#include "strategy.hpp"

#include <algorithm>
#include <cassert>
#include <numeric>

uint64_t Strategy::worstCase(uint64_t from, uint64_t to) {
    assert(from <= to);
    const uint64_t dist{to - from};
    if (!dist) {
        return 0;
    }

    if (dist == 1) {
        return from;
    }

    if (dist == 2) {
        return from + 1;
    }

    uint64_t pivot{to};
    assert(pivot - 3 >= from);
    uint64_t result{std::numeric_limits<uint64_t>::max()};

    while (pivot - 3 >= from) {
        pivot -= 3;
        assert(from <= pivot);
        assert(pivot < to);
        auto left{from < pivot ? worstCase(from, pivot - 1) : 0};
        auto right{worstCase(pivot + 1, to)};
        result = std::min(result, pivot + std::max(left, right));
    }

    return result;
}
uint64_t Strategy::worstCase(uint64_t given) {
    if (given == 1) {
        return 0;
    }

    return worstCase(1, given);
}

Strategy::Strategy(uint64_t size) : cache_{} {
    cache_.reserve(size);
    assert(cache_.capacity() >= size);
    cache_.push_back(0);
    cache_.push_back(1);
    cache_.push_back(2);
    cache_.push_back(4);

    for (uint64_t max = 5; max <= size; max++) {
        uint64_t fromTop{0};
        uint64_t pivot{0};
        uint64_t nextDistance{2};
        uint64_t result{std::numeric_limits<uint64_t>::max()};

        do {
            pivot = max + 1 - nextDistance;
            uint64_t fromCache{cache_.at(pivot - 2)};
            result =
                std::min(result, pivot + std::max(fromTop, fromCache));

            fromTop += pivot;
            nextDistance <<= 1u;
        } while (max > nextDistance);

        cache_.push_back(result);
    }
}
uint64_t Strategy::at(uint64_t position) const {
    assert(position <= cache_.size());
    return cache_.at(position - 1);
}
uint64_t Strategy::sum(uint64_t until) const {
    assert(until <= cache_.size());
    return std::accumulate(cache_.begin(), cache_.begin() + until, 0ul);
}
