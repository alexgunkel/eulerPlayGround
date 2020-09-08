#include "number_splitting.h"
#include <cmath>
#include <chrono>

int main() {
    for (int max = 10; max <= pow(10, 6); max *= 10) {
        std::cout << max << std::endl;
        auto start = std::chrono::high_resolution_clock::now();
        unsigned long long int result = 0;
        assert(std::sqrt(std::numeric_limits<unsigned long long int >::max()) > pow(10, 6));
        for (unsigned long int i = 2; i <= max; ++i) {
            const unsigned long long int number = i*i;
            const auto toString = std::to_string(number);
            if (hasSum<unsigned long long int >(toString, i)) {
                result += number;
            }
        }

        auto middle = std::chrono::high_resolution_clock::now();
        std::cout << "result: " << result << " after " << std::chrono::duration_cast<std::chrono::microseconds>(middle-start).count() << std::endl;

        result = 0;
        for (unsigned long int i = 2; i <= max; ++i) {
            const unsigned long long int number = i*i;
            if (hasSplittingTo<unsigned long long int >(number, i)) {
                result += number;
            }
        }

        auto end = std::chrono::high_resolution_clock::now();
        std::cout << "result: " << result << " after " << std::chrono::duration_cast<std::chrono::microseconds>(end-middle).count() << std::endl;

    }
}
