#include "solver.hpp"

#include <benchmark/benchmark.h>

static void benchSolve(benchmark::State& state) {
    for (const auto _ : state) {
        eu_735::Solver::solve(state.range(0));
    }
}

static void benchParallelSolve(benchmark::State& state) {
    for (const auto _ : state) {
        eu_735::Solver::solveParallel(state.range(0));
    }
}

BENCHMARK(benchSolve)->RangeMultiplier(10)->Range(10, 1e5);
BENCHMARK(benchParallelSolve)->RangeMultiplier(10)->Range(10, 1e5);
