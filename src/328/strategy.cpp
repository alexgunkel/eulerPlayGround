#include "strategy.hpp"
#include "distance_finder.hpp"

#include <algorithm>
#include <cassert>
#include <numeric>

Strategy::Strategy(uint64_t size) : cache_{} {
    cache_.reserve(size);
    assert(cache_.capacity() >= size);
    cache_.push_back(0);
    cache_.push_back(1);
    cache_.push_back(2);
    cache_.push_back(4);

    for (uint64_t max = 5; max <= size; max++) {
        uint64_t fromTop{0};
        uint64_t pivot;
        uint64_t nextPosition{max - 1};
        uint64_t result{std::numeric_limits<uint64_t>::max()};

        do {
            pivot = nextPosition;
            uint64_t fromCache{cache_.at(pivot - 2)};
            result = std::min(result, pivot + std::max(fromTop, fromCache));

            nextPosition = DistanceFinder::next(pivot, fromTop);
            fromTop += pivot;
        } while (0 < nextPosition);

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
