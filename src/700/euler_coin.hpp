#ifndef EULERPLAYGROUND_EULER_COIN_HPP
#define EULERPLAYGROUND_EULER_COIN_HPP

#include <cinttypes>
class EulerCoin {

  public:
    EulerCoin(uint64_t factor, uint64_t mod);

    [[nodiscard]] uint64_t print(uint64_t number) const noexcept;

    struct Result
    {
        uint64_t next;
        uint64_t previous;
        uint64_t factor;
    };

    [[nodiscard]] Result first() const;
    Result next(const Result& last) const;

  private:
    uint64_t factor_;
    uint64_t mod_;
};

#endif // EULERPLAYGROUND_EULER_COIN_HPP
