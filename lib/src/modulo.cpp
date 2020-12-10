#include "modulo.hpp"

uint64_t findSmallestMultiple(uint64_t base, uint64_t modulo)
{
    assert(base <= modulo);
    while (base != modulo) {
        assert(base != 0);
        uint64_t times = (modulo / base) + 1;
        uint64_t next = (base*times) % modulo;
        assert(next <= base);
        modulo = base;
        base = next;
    }

    return base;
}
