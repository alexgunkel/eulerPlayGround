#ifndef EULERPLAYGROUND_MODULO_HPP
#define EULERPLAYGROUND_MODULO_HPP

#include <cassert>
#include <cinttypes>
#include <cmath>
#include <memory>
#include <vector>

uint64_t findSmallestMultiple(uint64_t base, uint64_t modulo);
uint64_t findSmallestMultipleFast(uint64_t base, uint64_t modulo);

struct Factors {
    uint64_t interval;
    uint64_t power;
};
constexpr Factors log(uint64_t base, uint64_t value) {
    uint64_t res{1};
    uint64_t runner{base};

    while (runner < value) {
        res++;
        runner *= base;
    }

    return {res, runner};
}

template <uint64_t Base, uint64_t Modulo> class Power {
    static constexpr Factors interval_{log(Base, Modulo)};
    static std::shared_ptr<Power> instance_;
    std::vector<uint64_t> cache_{1};

  public:
    void raiseSize(uint64_t size);
    explicit Power(uint64_t size) { raiseSize(size); };

    [[nodiscard]] uint64_t get(uint64_t key) const {
        const auto i = interval_.interval;
        const auto lastBase = key / interval_.interval;
        const auto additional = key % i;
        assert(lastBase < cache_.size());
        const auto basis = cache_.at(lastBase);
        const uint64_t result = basis * std::pow(Base, additional);

        return result % Modulo;
    }

    static std::shared_ptr<Power> getInstance(uint64_t size) {
        if (!instance_) {
            instance_ = std::make_shared<Power>(size);
        }

        return instance_;
    };
};

template <uint64_t Basis, uint64_t Modulo>
void Power<Basis, Modulo>::raiseSize(uint64_t size) {
    size = (size / interval_.interval);
    cache_.reserve(size);
    while (size--) {
        cache_.push_back((cache_.back() * interval_.power) % Modulo);
    }
};

class ModuloMultiplier {
    uint64_t base_;
    uint64_t mod_;
    uint64_t maxFactor_;

  public:
    explicit ModuloMultiplier(uint64_t base, uint64_t mod)
        : base_{base}, mod_{mod},
          maxFactor_{std::numeric_limits<uint64_t>::max() / base_} {};

    [[nodiscard]] uint64_t multiply(uint64_t in) const {
        uint64_t res{1};
        uint64_t cache{};
        while (in >= maxFactor_) {
            in -= maxFactor_;
            cache = (base_ * maxFactor_) % mod_;
            res = (res*cache) % mod_;
        }

        res *= (in * base_) % mod_;

        return res % mod_;
    }
};

#endif // EULERPLAYGROUND_MODULO_HPP
