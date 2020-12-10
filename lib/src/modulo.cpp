#include "modulo.hpp"

uint64_t findSmallestMultiple(uint64_t base, uint64_t modulo)
{
    assert(base <= modulo);
    uint64_t next{0};
    uint64_t times{0};
    while (base != modulo) {
        assert(base != 0);
        times = (modulo / base) + 1;
        next = (base*times) % modulo;
        assert(next <= base);
        modulo = base;
        base = next;
    }

    return base;
}

uint64_t findSmallestMultipleFast(uint64_t base, uint64_t modulo)
{
    assert(base <= modulo);
    uint64_t next{0};
    uint64_t times{0};
    while (base != modulo) {
        assert(base != 0);
        times = (modulo / base) + 1;
        next = (base*times) % modulo;
        assert(next <= base);
        modulo = base;
        base = next;
    }

    return base;
}
