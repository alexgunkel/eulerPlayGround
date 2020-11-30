#include "generator.h"

namespace primes {
Generator::Generator(uint_fast64_t l) : v_(l-1, true) {
    for (auto it = v_.begin(); it != v_.end(); it++) {
        if (*it) {
            size_t number = it - v_.begin() + 2;
            for (size_t i = number; i < v_.size(); i += number) {
                *(it+i) = false;
            }
        }
    }
}

std::vector<uint_fast64_t> Generator::generate() const {
    std::vector<uint_fast64_t> res{};
    for (auto it = v_.begin(); it != v_.end(); it++) {
        if (*it) {
            res.push_back(it-v_.begin() + 2);
        }
    }

    return res;
}

} // namespace primes
