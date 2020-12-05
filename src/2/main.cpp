#include "fibonacci.hpp"
#include <iostream>

int main() {
    eu::fibonacci::Generator generator{100};

    std::cout << generator.greatest(4'000'000) << "\n";
};
