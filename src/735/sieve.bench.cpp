#include "sieve.hpp"

#include <benchmark/benchmark.h>

static void benchSieve(benchmark::State& state) {
    for (const auto _ : state) {
        auto in = static_cast<eu_735::Sieve::Input>(state.range(0));
        eu_735::Sieve{in}.solve();
    }
}

BENCHMARK(benchSieve)->RangeMultiplier(10)->Range(10, 1e4);
