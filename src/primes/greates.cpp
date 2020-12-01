#include "generator.h"
#include <iostream>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "give exactly one number as arg\n";

        return -1;
    }

    char n = 0;
    std::string arg{argv[1]};
    uint_fast64_t threshold = std::stoull(arg);

    primes::Generator generator{threshold};;

    std::cout << "total: " << generator.size() << "\n";
    std::cout << "greatest: " << generator.last() << "\n";

    return 0;
}