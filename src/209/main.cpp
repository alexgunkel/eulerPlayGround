#include <iostream>
#include <cinttypes>
#include <array>
#include <cassert>

int main()
{
    using Integer = uint_fast64_t;

    std::array<bool, 64> done{ false};
    const Integer sixPosMask = 0b00111111;
    const Integer aMask      = 0b00100000;
    const Integer bcMask     = 0b00011000;

    Integer given{0}, tmp{given};

    for (; given < 64; ++given) {
        if (done.at(given)) {
            continue;
        }

        tmp = given;

        std::cout << "result for " << given << ": ";
        size_t count{0};
        do {
            assert(tmp < 64);
            std::cout << tmp << " ";
            const bool a = tmp & aMask;
            const bool bAndC = (tmp & bcMask) == bcMask;
            tmp = tmp << 1u;
            if (a != bAndC) {
                tmp |= 0b1u;
            }

            tmp = tmp & sixPosMask;
            assert(!done.at(tmp));
            done.at(tmp) = true;
            count++;
        } while (tmp != given);

        std::cout << " --- total: " << count << std::endl;
    }

    return 0;
}
