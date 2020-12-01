#include "fibonacci.hpp"
#include <iostream>

int main() {
    eu2::Fibonacci fib{4'000'000};

    std::cout << fib.get() << "\n";
};
