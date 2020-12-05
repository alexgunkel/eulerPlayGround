
#ifndef EULERPLAYGROUND_FIBONACCI_HPP
#define EULERPLAYGROUND_FIBONACCI_HPP

#include <array>
#include <cinttypes>
#include <vector>

namespace eu::fibonacci {

class Generator {
    mutable std::vector<uint_fast64_t> found_;
    mutable std::array<uint_fast64_t, 3> cache_;
    mutable decltype(cache_.begin()) cachePtr_;
    void buildUntil(uint_fast64_t size) const
    {
        size++;
        const auto next = [this] (const decltype(cache_.begin())& ptr, size_t add) {
            const size_t pos = ptr - cache_.begin();
            const auto newPos = (pos+add) % 3;
            const auto next = ptr+newPos-pos;

            return next;
        };
        for (uint_fast64_t i = found_.size(); i <= size; ++i) {
            const auto nextValue = *next(cachePtr_, 1) + *next(cachePtr_, 2);
            found_.push_back(nextValue);
            *cachePtr_ = nextValue;
            cachePtr_ = next(cachePtr_, 1);
        }
    }

  public:
    explicit Generator(size_t size)
        : found_{1, 1, 2}, cache_{1, 1, 2}, cachePtr_{cache_.begin()} {
        found_.reserve(size+1);
        buildUntil(size);
    };

    uint_fast64_t get(uint_fast64_t size) const {
        if (found_.size() <= size) {
            buildUntil(size);
        }

        return found_.at(size);
    }

    uint_fast64_t greatest(uint_fast64_t threshold) const {
        uint_fast64_t arg{0}, result{0}, next{0};

        while ((next = get(arg++)) <= threshold) {
            result = next;
        }

        return result;
    }
};

} // namespace eu::fibonacci

#endif // EULERPLAYGROUND_FIBONACCI_HPP
