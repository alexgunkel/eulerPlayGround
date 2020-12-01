#include "multiples_sum.hpp"

#include <iostream>

int main()
{
    eu1::MultiplesSum sum(3u, 5u);

    std::cout << sum.sumTill(999) << "\n";
}
