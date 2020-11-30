#include "generator.h"

#include "benchmark/benchmark.h"

namespace {
void bm_construct_generate(benchmark::State& state) {
    for (const auto _ : state) {
        uint_fast64_t in = state.range(0);
        primes::Generator generator{in};

        generator.generate();
    }
}
}

BENCHMARK(bm_construct_generate)->Range(2, 2u<<8u);
