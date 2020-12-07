#ifndef EULERPLAYGROUND_TRUTH_TABLE_HPP
#define EULERPLAYGROUND_TRUTH_TABLE_HPP

#include <array>
#include <vector>

template <typename Basis, unsigned int NumberOfValues>
class TruthValueAssigment {
    static_assert(NumberOfValues > 2, "positive integer > 2 required");
    static_assert(
        NumberOfValues < sizeof(Basis) * 4,
        "type must contains at least one bit more than we have values");

    Basis value_;
    constexpr static Basis typeMask = (0b1u << NumberOfValues) - 1;
    constexpr static Basis FirstValueMask = 0b1u << (NumberOfValues - 1);
    constexpr static Basis SecondValueMask = 0b1u << (NumberOfValues - 2);
    constexpr static Basis ThirdValueMask = 0b1u << (NumberOfValues - 3);

  public:
    explicit constexpr TruthValueAssigment(Basis value) : value_{value} {};
    auto operator<=>(const TruthValueAssigment &other) const = default;
    static constexpr Basis max() {
        return (1u << NumberOfValues)-1;
    };
    operator Basis() const {
        return value_;
    };
    TruthValueAssigment &operator++() {
        const bool a = value_ & FirstValueMask;
        const bool b = value_ & SecondValueMask;
        const bool c = value_ & ThirdValueMask;

        value_ = (value_ << 1u) & typeMask;

        if (a != (b && c)) {
            value_++;
        }

        return *this;
    }
};

template <typename Basis, unsigned int NumberOfValues> class TruthTableChain {
    using Assignment = TruthValueAssigment<Basis, NumberOfValues>;
    std::vector<std::vector<Assignment>>
        matrix_;

  public:
    TruthTableChain() : matrix_{} {
        std::array<bool, 1u << NumberOfValues> done{false};

        for (Basis start{0}; start <= Assignment::max(); ++start) {
            Assignment current{start};
            if (done.at(current)) {
                continue;
            }

            auto iterator{current};
            std::vector<Assignment> circle{};
            do {
                circle.push_back(iterator);
                done.at(iterator) = true;
                ++iterator;
            } while (iterator != current);

            matrix_.push_back(circle);
        }
    }

    const std::vector<std::vector<Assignment>>& matrix() const {
        return matrix_;
    }
};

template <typename Basis, unsigned int positions>
bool areNeighbours(const Basis& left, const Basis& right)
{
    const bool mostLeft = left & (1 << (positions-1));
}

#endif // EULERPLAYGROUND_TRUTH_TABLE_HPP
