#include "euler_coin.hpp"
#include "gcd.hpp"
#include <iostream>
#include <cassert>

EulerCoin::EulerCoin(uint64_t factor, uint64_t mod)
    : factor_{factor}, mod_{mod} {}
uint64_t EulerCoin::print(uint64_t number) const noexcept {
    uint64_t minus{mod_ % factor_};
    uint64_t runner{107};
    uint64_t last{mod_};
    uint64_t sum{0};

    while (--number && runner > 1 && runner < last) {
        sum += runner;
        std::cout << number << ".: " << runner << " diff: " << (last-runner) << "\n";

        last = runner;

        if (minus < runner) {
            runner -= minus;
        } else {
            do {
                uint64_t repeat{((mod_ - runner)/factor_ + 1)};
                uint64_t next = (factor_ * (repeat) + runner) % mod_;
                std::cout << "\t" << repeat << " repetitions --> " << next << "\n";
                assert(next < factor_);

                if (next > runner) {
                    uint64_t diff{next-runner};
                    if (diff < runner) {
                        next = std::min(((factor_-next)/diff) * diff + 2*next - factor_, next);
                        std::cout << "jump forward to " << next << "\n";
                    } else {
                        uint64_t minusDiff{factor_-diff+runner};
                        if (minusDiff < next) {
                            next -= ((next/minusDiff)*minusDiff);
                        } else {
                            next += factor_;
                            next -= ((next/minusDiff)*minusDiff);
                        }
                        std::cout << "jump back to " << next << "\n";
                    }
                } else {
                    if (next > runner/2) {
                        next -= (runner-next);
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
    const uint64_t times{mod_/factor_ + 1};

    Result result{
        .next = (times*factor_) % mod_,
        .previous = factor_,
        .factor = times,
    };

    return result;
}
EulerCoin::Result EulerCoin::next(const EulerCoin::Result &last) const {
    Result result{.next=last.next, .previous=last.next,.factor=last.factor};

    while (result.next >= last.next) {
        result.next += factor_;
        result.next %= mod_;
        result.factor++;
    }

    return result;
}
