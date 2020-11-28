
#ifndef EULERPLAYGROUND_NUMBER_STRING_H
#define EULERPLAYGROUND_NUMBER_STRING_H

#include <cassert>
#include <algorithm>
#include <numeric>

template<class IntegralType, int positions>
class NumberString {
private:
    u_int8_t storage_[positions]{};
    u_int8_t length_;
public:
    using Type = IntegralType;
    explicit NumberString<positions>(Type i) {
        static_assert(sizeof(NumberString<Type , positions>) == positions+1, "");
        std::fill(storage_, storage_+positions, 0);
        int pos{};
        while (i) {
            assert(pos < positions);
            storage_[pos++] = i % 10;
            i /= 10;
        }
        length_ = pos;
    };

    Type toInt() const {
        return toInt(0, length_-1);
    }

    Type toInt(u_int8_t from, u_int8_t to) const {
        assert(from <= to);
        assert(from >= 0);
        assert(to < length_);
        auto end = length_ - from;
        auto start = length_-to;
        Type res{};
        while (start <= end) {
            res = (10 * res) + storage_[--end];
        }

        return res;
    }

    Type sum() const {
        return std::accumulate(storage_, storage_+length_, Type{});
    }

    Type sum(u_int8_t l) const {
        assert(l <= length_);
        return std::accumulate(storage_, storage_+l, Type{});
    }

    Type sum(u_int8_t begin, u_int8_t l) const {
        assert(begin >= 0 && begin + l <= length_);
        return std::accumulate(storage_+begin, storage_+begin+l, Type{});
    }

    const u_int8_t * end() const {
        return storage_+length_;
    }
    const u_int8_t * begin() const {
        return storage_;
    }
    u_int8_t at(size_t p) const {
        return storage_[length_-p];
    }
};


#endif //EULERPLAYGROUND_NUMBER_STRING_H
