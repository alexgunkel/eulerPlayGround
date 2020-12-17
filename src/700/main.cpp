#include "euler_coin.hpp"
#include <iostream>

int main()
{
    EulerCoin coin{1'504'170'715'041'707, 4'503'599'627'370'517};
    //EulerCoin coin{997, 3167};

    const auto result = coin.print(500);

    std::cout << result << "\n";
    return 0;
}
