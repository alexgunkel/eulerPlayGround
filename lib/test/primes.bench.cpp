#include "primes.hpp"

#include "benchmark/benchmark.h"

namespace
{
void bmPrimeFactorization(benchmark::State& state)
{
    uint64_t value = state.range() + 3;
    for (const auto& _ : state) {
        for (uint64_t ex = value-1000; ex < value; ex++) {
            factorize(value);
        }
    }
}
}

BENCHMARK(bmPrimeFactorization)->RangeMultiplier(10)->Range(1'000'000, 1'000'000'000)->Complexity();
