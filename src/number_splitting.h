
#ifndef EULERPLAYGROUND_NUMBER_SPLITTING_H
#define EULERPLAYGROUND_NUMBER_SPLITTING_H

#include <algorithm>
#include <cassert>
#include <vector>
#include <string>
#include <iostream>

template<class T>
std::vector<T> calculateSums(const std::string& input) {
    uint length = input.length();

    std::vector<T> result(uint16_t{1} << (length - 1), 0);
    auto pos = result.begin();
    *(pos++) = std::stoull(input);

    while (--length) {
        auto remaining = std::stoull(input.substr(0, length));
        auto additional = calculateSums<T>(input.substr(length));

        pos = std::transform(
                additional.begin(),
                additional.end(),
                pos,
                [remaining](T i) {
                    return i + remaining;
                }
            );
    }

    return result;
}

template<class T>
bool hasSplittingTo(T source, T target) {
    std::string representation = std::to_string(source);

    auto splitSums = calculateSums<T>(representation);

    return std::find(splitSums.begin(), splitSums.end(), target) != splitSums.end();
}

#endif //EULERPLAYGROUND_NUMBER_SPLITTING_H
