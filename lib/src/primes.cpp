#include "primes.hpp"
#include <cassert>

Generator::Generator(uint_fast64_t l) : v_(l - 1, true) {
    assert(l > 2);
    for (auto it = v_.begin(); it != v_.end(); it++) {
        if (*it) {
            n_++;
            const size_t number = it - v_.begin() + 2;
            last_ = number;
            const auto max = v_.end() - it;
            for (size_t i = number; i < max; i += number) {
                auto t = it + i;
                assert(t < v_.end());
                *t = false;
            }
        }
    }

    assert(n_ > 0 && n_ < l);
    assert(last_ > 1 && last_ <= l);
}

std::vector<uint_fast64_t> Generator::generate() const {
    std::vector<uint_fast64_t> res{};
    res.reserve(n_);
    for (auto it = v_.begin(); it != v_.end(); it++) {
        if (*it) {
            res.push_back(it - v_.begin() + 2);
        }
    }

    assert(res.back() == last_);
    assert(res.size() == n_);
    return res;
}

uint_fast64_t Generator::size() const { return n_; }
uint_fast64_t Generator::last() const {
    assert(last_ > 1);
    return last_;
}