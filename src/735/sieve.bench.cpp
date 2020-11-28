#include "sieve.hpp"

#include <benchmark/benchmark.h>

static void benchSieve(benchmark::State& state) {
    for (const auto _ : state) {
        eu_735::Sieve::solve(state.range(0));
    }
}

static void benchSieveParallel(benchmark::State& state) {
    for (const auto _ : state) {
        eu_735::Sieve::solveParallel(state.range(0));
    }
}

BENCHMARK(benchSieve)->RangeMultiplier(10)->Range(10, 1e8);
BENCHMARK(benchSieveParallel)->RangeMultiplier(10)->Range(10, 1e8);
