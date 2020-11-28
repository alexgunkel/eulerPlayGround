
#ifndef EULERPLAYGROUND_NUMBER_SPLITTING_H
#define EULERPLAYGROUND_NUMBER_SPLITTING_H

#include "number_string.h"
#include <algorithm>
#include <cassert>
#include <vector>
#include <string>
#include <iostream>
#include <numeric>

template<class IntegralType, uint8_t positions>
bool stringHasSum(NumberString<IntegralType, positions> in, uint8_t from, uint8_t to, IntegralType value) {
    auto pos = to;
    while (pos > from) {
        IntegralType interim = in.toInt(from, pos-from);

        if (stringHasSum<IntegralType, positions>(in, pos, to, value - interim)) {
            return true;
        }
        pos--;
    }

    return value == IntegralType{};
}

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

template<class  T>
T fromString(const char* in, size_t length) {
    T res{};
    while (*in && length--) {
        res = 10*res + (*in - '0');
        in++;
    }

    return res;
}

template<class T>
bool hasSum(const char* in, size_t length, T value) {
    assert(length >= 0);
    assert(in);
    if (length == 0) {
        return value == 0;
    }

    size_t pos = length;
    while (length) {
        T firstPartValue = fromString<T>(in, length);

        if (hasSum<T>(in+length, pos-length, value-firstPartValue)) {
            return true;
        }

        length--;
    }

    return false;
}

template<class T>
bool hasSum(const std::string& input, T value) {
    uint length_ = input.length();
    if (length_ == 0) {
        return value == 0;
    }

    while (length_) {
        T firstPartValue = std::stoull(input.substr(0, length_));

        if (hasSum(input.substr(length_), value-firstPartValue)) {
            return true;
        }

        length_--;
    }

    return false;
}

template<class T>
bool hasSplittingTo(T source, T target) {
    const std::string representation = std::to_string(source);
    const auto splitSums = calculateSums<T>(representation);

    return std::find(splitSums.begin(), splitSums.end(), target) != splitSums.end();
}

template<class T, int l>
size_t toString(T i, char* t) {
    while (i) {

    }
}

#endif //EULERPLAYGROUND_NUMBER_SPLITTING_H
