#include "distance_finder.hpp"

#include <algorithm>
#include <cassert>

DistanceFinder::DistanceFinder(uint64_t from, uint64_t top)
    : from_{from}, top_{top} {}

uint64_t DistanceFinder::next(uint64_t from, uint64_t top) {
    if (top == 0) {
        return from - 2;
    }

    uint64_t alternative{from - 2};
    uint64_t distance{2};

    do {
        distance <<= 1u;

        alternative += distance < from ? from - distance : 0;
    } while (alternative < top && distance < from);

    return from - std::min(distance, from);
}
