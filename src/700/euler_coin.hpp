#ifndef EULERPLAYGROUND_EULER_COIN_HPP
#define EULERPLAYGROUND_EULER_COIN_HPP

#include <cassert>
#include <cinttypes>
class EulerCoin {

  public:
    EulerCoin(uint64_t factor, uint64_t mod);

    [[nodiscard]] uint64_t print(uint64_t number) const noexcept;

    struct Result
    {
        uint64_t value{};
        uint64_t previous{};
        uint64_t factor{};
        uint64_t previousFactor{};

        operator bool() const {
            return value && value != previous;
        }

        [[nodiscard]] uint64_t diff() const {
            return previous ? previous-value : 0;
        }
    };

    [[nodiscard]] Result first() const;
    Result next(const Result& last) const;

  private:
    uint64_t factor_;
    uint64_t mod_;
    uint64_t min_;
};

#endif // EULERPLAYGROUND_EULER_COIN_HPP
