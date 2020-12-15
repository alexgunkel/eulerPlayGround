#ifndef EULERPLAYGROUND_PRIMES_HPP
#define EULERPLAYGROUND_PRIMES_HPP

#include <exception>
#include <map>
#include <stdexcept>
#include <vector>

template <typename Integer>
std::map<Integer, Integer> factorize(Integer given)
{
    std::map<Integer, Integer> result{};

    Integer divisor{1};
    while (given > divisor++) {
        while (given % divisor == 0) {
            given /= divisor;
            result[divisor]++;
        }
    }

    return result;
}


class Generator {
  public:
    explicit Generator(uint_fast64_t);
    [[nodiscard]] std::vector<uint_fast64_t> generate() const;
    [[nodiscard]] uint_fast64_t size() const;
    [[nodiscard]] uint_fast64_t last() const;

  private:
    size_t n_{0};
    uint_fast64_t last_{0};
    std::vector<bool> v_;
};

class Factorizer
{
  private:
    using Integer = uint64_t ;
    std::vector<Integer> primes_;

  public:
    explicit Factorizer(Integer max) {
        Generator generator{max};
        primes_ = generator.generate();
    };
    std::vector<Integer> factorize(Integer given) {
        std::vector<Integer> result{};
        auto divisor{primes_.begin()};
        u_int64_t sec{given};

        while (divisor != primes_.end() && *divisor <= given) {
            while (given % *divisor == 0) {
                given /= *divisor;
                result.push_back(*divisor);
                sec--;
                if (!sec) {
                    throw std::logic_error{"check A"};
                }
            }

            ++divisor;
        };

        return result;
    }

    [[nodiscard]] const std::vector<uint64_t>& primes() const {
        return primes_;
    }
};

template <typename Integer>
Integer power(Integer i, Integer exp)
{
    Integer result{1};
    while (exp--) {
        result *= i;
    }

    return result;
}

#endif // EULERPLAYGROUND_PRIMES_HPP
