#include "generator.h"

#include "benchmark/benchmark.h"

#include <cmath>

namespace {
void bm_construct_generate(benchmark::State& state) {
    for (const auto _ : state) {
        uint_fast64_t in = state.range(0);
        primes::Generator generator{in};

        generator.generate();
    }
}
}

BENCHMARK(bm_construct_generate)->RangeMultiplier(10)->Range(10, std::pow(10, 7));
