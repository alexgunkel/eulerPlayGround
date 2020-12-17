#ifndef EULERPLAYGROUND_EULER_COIN_HPP
#define EULERPLAYGROUND_EULER_COIN_HPP

#include <cinttypes>
class EulerCoin {

  public:
    EulerCoin(uint64_t factor, uint64_t mod);

    uint64_t print(uint64_t number) const noexcept;

  private:
    uint64_t factor_;
    uint64_t mod_;
};

#endif // EULERPLAYGROUND_EULER_COIN_HPP
