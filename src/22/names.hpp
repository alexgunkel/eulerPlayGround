
#ifndef EULERPLAYGROUND_NAMES_HPP
#define EULERPLAYGROUND_NAMES_HPP

#include <array>
#include <cinttypes>
#include <filesystem>
#include <vector>

using std::filesystem::path;

class Names {
  public:
    explicit Names(const path& file);

    [[nodiscard]] uint64_t sum() const;

  private:
    std::vector<std::array<uint8_t , 20>> nameList;
};

#endif // EULERPLAYGROUND_NAMES_HPP
