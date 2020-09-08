
#ifndef EULERPLAYGROUND_NUMBER_SPLITTING_H
#define EULERPLAYGROUND_NUMBER_SPLITTING_H

#include <algorithm>
#include <cassert>
#include <vector>
#include <string>
#include <iostream>
#include <numeric>

template<class T>
std::vector<T> calculateSums(const std::string& input) {
    uint length = input.length();

    std::vector<T> result(uint16_t{1} << (length - 1), 0);
    auto pos = result.begin();
    *(pos++) = std::stoull(input);

    while (--length) {
        const auto remaining = std::stoull(input.substr(0, length));
        const auto additional = calculateSums<T>(input.substr(length));

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
bool hasCheckSum(const std::string& input, T value) {
    const std::string cmp = std::to_string(value);
    const auto result = std::accumulate(input.begin(), input.end(), 0, [](T given, auto next) -> T {
        return given + (next - '0');
    });
    const auto compare = std::accumulate(cmp.begin(), cmp.end(), 0, [](T given, auto next) -> T {
        return given + (next - '0');
    });

    return result == compare;
}

template<class T>
bool hasSum(const std::string& input, T value) {
    uint length = input.length();
    if (length == 0) {
        return value == 0;
    }

    while (length) {
        T firstPartValue = std::stoull(input.substr(0, length));

        if (hasSum(input.substr(length), value-firstPartValue)) {
            return true;
        }

        length--;
    }

    return false;
}

template<class T>
bool hasSplittingTo(T source, T target) {
    const std::string representation = std::to_string(source);
    const auto splitSums = calculateSums<T>(representation);

    return std::find(splitSums.begin(), splitSums.end(), target) != splitSums.end();
}

#endif //EULERPLAYGROUND_NUMBER_SPLITTING_H
