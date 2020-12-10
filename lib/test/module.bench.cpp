#include "modulo.hpp"
#include "gcd.hpp"

#include "benchmark/benchmark.h"

namespace
{
void benchThemAll(benchmark::State& state)
{
    for (const auto& _ : state) {
        const uint64_t r = state.range(0);
        for (uint64_t i = 1; i < r; ++i) {
            findSmallestMultiple(i, r);
        }
    }
}
}

BENCHMARK(benchThemAll)->RangeMultiplier(10)->Range(100, 1'000'000)->Complexity();

namespace
{
void benchGcd(benchmark::State& state)
{
    for (const auto& _ : state) {
        const uint64_t r = state.range(0);
        for (uint64_t i = 1; i < r; ++i) {
            gcd(i, r);
        }
    }
}
}

BENCHMARK(benchGcd)->RangeMultiplier(10)->Range(100, 1'000'000)->Complexity();

namespace
{
void benchmarkPower(benchmark::State& state)
{
    const uint64_t max = state.range(0);
    Power<2, 1'000'000'007> power{max};

    for (const auto& _ : state) {
        for (uint64_t i = 0; i <= max; ++i) {
            power.get(i);
        }
    }
}
}

BENCHMARK(benchmarkPower)->RangeMultiplier(10)->Range(100, 1'000'000)->Complexity();
