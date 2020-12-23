#ifndef EULERPLAYGROUND_DISTANCE_FINDER_HPP
#define EULERPLAYGROUND_DISTANCE_FINDER_HPP

#include <cinttypes>

class DistanceFinder {
  public:
    DistanceFinder(uint64_t from, uint64_t top);

    [[nodiscard]] static uint64_t next(uint64_t from, uint64_t top) ;

  private:
    uint64_t from_;
    uint64_t top_;
};

#endif // EULERPLAYGROUND_DISTANCE_FINDER_HPP
