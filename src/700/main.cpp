#include "euler_coin.hpp"
#include <iostream>

int main()
{
    EulerCoin coin{1'504'170'715'041'707, 4'503'599'627'370'517};
    //EulerCoin coin{997, 3167};

    auto result = coin.first();
    uint64_t sum{0};
    while (result) {
        std::cout << result.factor << ": " << result.value << "\n";
        sum += result.value;
        result = coin.next(result);
    }

    std::cout << sum << "\n";
    return 0;
}
