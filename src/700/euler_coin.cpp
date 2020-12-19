#include "euler_coin.hpp"
#include "gcd.hpp"
#include "modulo.hpp"
#include <cassert>
#include <iostream>

EulerCoin::EulerCoin(uint64_t factor, uint64_t mod)
    : factor_{factor}, mod_{mod}, min_{gcd(mod_, factor_)} {}

uint64_t EulerCoin::print(uint64_t number) const noexcept {
    uint64_t minus{mod_ % factor_};
    uint64_t runner{107};
    uint64_t last{mod_};
    uint64_t sum{0};

    while (--number && runner > 1 && runner < last) {
        sum += runner;
        std::cout << number << ".: " << runner << " diff: " << (last - runner)
                  << "\n";

        last = runner;

        if (minus < runner) {
            runner -= minus;
        } else {
            do {
                uint64_t repeat{((mod_ - runner) / factor_ + 1)};
                uint64_t next = (factor_ * (repeat) + runner) % mod_;
                std::cout << "\t" << repeat << " repetitions --> " << next
                          << "\n";
                assert(next < factor_);

                if (next > runner) {
                    uint64_t diff{next - runner};
                    if (diff < runner) {
                        next = std::min(((factor_ - next) / diff) * diff +
                                            2 * next - factor_,
                                        next);
                        std::cout << "jump forward to " << next << "\n";
                    } else {
                        uint64_t minusDiff{factor_ - diff + runner};
                        if (minusDiff < next) {
                            next -= ((next / minusDiff) * minusDiff);
                        } else {
                            next += factor_;
                            next -= ((next / minusDiff) * minusDiff);
                        }
                        std::cout << "jump back to " << next << "\n";
                    }
                } else {
                    if (next > runner / 2) {
                        next -= (runner - next);
                    }
                }

                runner = next;

                assert(runner != last);
            } while (runner > last);
        }

        minus = last - runner;
    }

    return sum;
}

EulerCoin::Result EulerCoin::first() const {
    Result result{
        .value = factor_,
        .previous = 0,
        .factor = 1,
    };

    return result;
}
EulerCoin::Result EulerCoin::next(const EulerCoin::Result &last) const {
    assert(last.value != 0);
    assert(last.value <= factor_);
    Result result{.value = last.value,
                  .previous = last.value,
                  .factor = last.factor,
                  .previousFactor = last.factor};

    while (result.value != min_ && result.value >= last.value) {
        auto hint{previousJumps_.upper_bound(result.value)};
        if (hint == previousJumps_.end()) {
            uint64_t dist{(mod_ - result.value) / factor_ + 1};
            result.value += factor_ * dist;
            result.value %= mod_;
            result.factor += dist;
        } else if (hint->second.difference > result.value) {
            if (hint->second.difference >= result.value) {
                result.factor += hint->second.distance + 1;
                result.value += factor_ - hint->second.difference;
            }
            assert(result.value <= factor_);
            assert(result.value > result.previous);
        } else {
            result.factor += hint->second.distance;
            result.value -= hint->second.difference;
        }
    }

    assert(!last.diff() || (result.diff() <= last.diff()));
    assert(result.value <= result.previous);
    assert(result.factor >= last.factor);

    previousJumps_.emplace_hint(
        previousJumps_.end(),
        std::pair{result.previous,
                  Jump{.distance = (result.factor - last.factor),
                       .difference = result.diff()}});

    return result;
}
