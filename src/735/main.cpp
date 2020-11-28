#include "solver.hpp"
#include <string>
#include <iostream>

int main(int argc, char** argv) {
    eu_735::Integer i{1000};
    if (argc > 1) {
        i = std::stoll(std::string{argv[1]});
    }

    std::cout << eu_735::Solver::solveParallel(i) << "\n";

    return 0;
}
