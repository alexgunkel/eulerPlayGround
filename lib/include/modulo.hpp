#ifndef EULERPLAYGROUND_MODULO_HPP
#define EULERPLAYGROUND_MODULO_HPP
#include <cinttypes>
#include <cmath>
#include <memory>
#include <vector>

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

template <uint64_t Base, uint64_t Modulo>
class Power
{
    static constexpr Factors interval_{log(Base, Modulo)};
    static std::shared_ptr<Power> instance_;
    std::vector<uint64_t> cache_{1};
  public:
    void raiseSize(uint64_t size);
    explicit Power(uint64_t size) {
        raiseSize(size);
    };

    uint64_t get(uint64_t key) {
        const auto i = interval_.interval;
        const auto lastBase = key / interval_.interval;
        const auto additional = key % i;
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
        cache_.push_back(
            (cache_.back() * interval_.power) % Modulo
        );
    }
};

#endif // EULERPLAYGROUND_MODULO_HPP
