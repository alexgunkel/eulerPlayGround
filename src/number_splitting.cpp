#include "number_splitting.h"
#include <cmath>

int main() {
    unsigned long long int result = 0;
    assert(std::sqrt(std::numeric_limits<unsigned long long int >::max()) > pow(10, 6));
    for (unsigned long int i = 2; i <= pow(10,6); ++i) {
        unsigned long long int number = i*i;
        if (hasSplittingTo<unsigned long long int >(number, i)) {
            std::cout << number << " is split by " << i << "\n";
            result += number;
        }
    }

    std::cout << "result: " << result << std::endl;
}
