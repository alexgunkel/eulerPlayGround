
#include "names.hpp"

#include <cassert>
#include <cinttypes>
#include <fstream>
#include <numeric>
#include <vector>

Names::Names(const path& file) {
    std::ifstream istream{file.string().c_str()};
    nameList.reserve(std::filesystem::file_size(file) / 10);
    nameList.emplace_back();
    auto cursor{nameList.back().begin()};
    char c{};
    while (istream >> c) {
        if (c == ',') {
            nameList.emplace_back();
            cursor = nameList.back().begin();
        } else if (c >= 'A' && c <= 'Z') {
            assert(cursor != nameList.back().end());
            *(cursor++) = (c - 'A' + 1);
        } else if (c != '"') {
            std::string errorMsg{"found illegal character: "};
            errorMsg += c;
            throw std::runtime_error(errorMsg);
        }
    }

    std::sort(nameList.begin(), nameList.end());
}

uint64_t Names::sum() const {
    uint64_t total{0};
    for (int i = 0; i < nameList.size(); ++i) {
        const auto& name{nameList.at(i)};
        const uint64_t sum{std::accumulate(name.begin(), name.end(), 0ul)};
        total += sum*(i+1);
    }

    return total;
}
