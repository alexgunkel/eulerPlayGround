#include "number_splitting.h"
#include <cmath>
#include <chrono>

#include <tbb/tbb.h>
#include <sstream>
#include <atomic>

namespace {
    using MyType = unsigned long long int;
    const MyType maximum = std::sqrt(std::numeric_limits<MyType>::max());
    constexpr MyType halfMax = std::numeric_limits<MyType>::max() / 2;

    MyType accumulateRange(const MyType start, const MyType end, MyType given) {
        MyType res = 0;
        assert(end <= maximum);
        for (auto begin = start; begin <= end; begin++) {
            const MyType number = begin * begin;
            const std::string toString = std::to_string(number);
            if (hasSum<MyType>(toString.c_str(), toString.length(), begin)) {
                res += number;
            }
        }

        return res + given;
    }
}

int main() {
    for (int max = 9000; max <= pow(10, 5); max += 100) {
        std::atomic<int> tasks{0};
        std::cout << max << std::endl;
        std::cout << halfMax << std::endl;
        auto start = std::chrono::high_resolution_clock::now();
        unsigned long long int result = 0;
        assert(std::sqrt(std::numeric_limits<unsigned long long int>::max()) > pow(10, 6));

        result = accumulateRange(2, max, 0);

        auto middle = std::chrono::high_resolution_clock::now();
        std::cout << "result: " << result << " after "
                  << std::chrono::duration_cast<std::chrono::microseconds>(middle - start).count() << std::endl;

        result = tbb::parallel_reduce(
                tbb::blocked_range<MyType>(2, max + 1),
                0,
                [&tasks](const tbb::blocked_range<MyType> &range, MyType last) -> MyType {
                    tasks++;
                    MyType to = range.end() - 1;
                    MyType from = range.begin();
                    auto res = accumulateRange(from, to, last);

                    return res;
                },
                [](const MyType l, const MyType r) -> MyType {
                    assert(l < halfMax || r < (l - halfMax));
                    assert(r < halfMax || l < (r - halfMax));
                    return l + r;
                });

        middle = std::chrono::high_resolution_clock::now();
        std::cout << "result: " << result << " after "
                  << std::chrono::duration_cast<std::chrono::microseconds>(middle - start).count() << std::endl;
        std::cout << "tasks: " << tasks.load() << "\n";

        result = 0;
        for (unsigned long int i = 2; i <= max; ++i) {
            const unsigned long long int number = i * i;
            if (hasSplittingTo<unsigned long long int>(number, i)) {
                result += number;
            }
        }

        auto end = std::chrono::high_resolution_clock::now();
        std::cout << "result: " << result << " after "
                  << std::chrono::duration_cast<std::chrono::microseconds>(end - middle).count() << std::endl;

    }
}
