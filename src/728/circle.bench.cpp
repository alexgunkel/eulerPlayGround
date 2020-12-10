#include "circle_of_coins.hpp"

#include "benchmark/benchmark.h"

namespace
{
void benchPossibleSolutions(benchmark::State& state)
{
    const uint64_t max = state.range();
    CircleOfCoins circleOfCoins{max};
    for (const auto& _ : state) {
        for (uint64_t i = 1; i <= max; ++i) {
            circleOfCoins.numberOfPossibleSolutions(max, i);
        }
    }
}
}

BENCHMARK(benchPossibleSolutions)->RangeMultiplier(10)->Range(1'000u, 1'000'000)->Complexity();

namespace
{
void benchPossibleSolutionsForAllFlips(benchmark::State& state)
{
    const uint64_t coins = state.range(0);
    CircleOfCoins circleOfCoins{coins};
    volatile uint64_t res{0};

    for (const auto& _ : state) {
        res = circleOfCoins.numberOfPossibleSolutions(coins);
    }

    assert(res == 123);
}
}

BENCHMARK(benchPossibleSolutionsForAllFlips)->RangeMultiplier(10)->Range(100, 1'000'000)->Complexity();

namespace
{
void benchPossibleSolutionsMax(benchmark::State& state)
{
    const uint64_t coins = state.range(0);
    volatile uint64_t res{0};

    for (const auto& _ : state) {
        CircleOfCoins circleOfCoins{coins};
        res = circleOfCoins.numberOfPossibleSolutions();
    }

    assert(res == 123);
}
}

BENCHMARK(benchPossibleSolutionsMax)->RangeMultiplier(10)->Range(10, 1'000'000)->Complexity();
