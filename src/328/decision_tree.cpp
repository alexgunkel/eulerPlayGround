#include "decision_tree.hpp"
#include "design_by_contract.hpp"

#include <cassert>
#include <iostream>

DecisionTree::DecisionTree(uint64_t value)
    : DecisionTree{value, nullptr, nullptr} {}

DecisionTree::DecisionTree(uint64_t value, std::unique_ptr<DecisionTree> lower,
                           std::unique_ptr<DecisionTree> upper)
    : value_{value}, upper_{std::move(upper)}, lower_{std::move(lower)} {
    assert(!lower_ || lower_->value_ < value_);
    assert(!upper_ || upper_->value_ > value_);
}

DecisionTree::DecisionTree(uint64_t value, std::unique_ptr<DecisionTree> lower)
    : DecisionTree{value, std::move(lower), nullptr} {}

uint64_t DecisionTree::max() const {
    uint64_t result{value_};

    result +=
        std::max(lower_ ? lower_->max() : 0ul, upper_ ? upper_->max() : 0ul);

    return result;
}

uint64_t DecisionTree::value() const { return value_; }
const DecisionTree *DecisionTree::lower() const { return lower_.get(); }
const DecisionTree *DecisionTree::upper() const { return upper_.get(); }
void DecisionTree::setUpper(std::unique_ptr<DecisionTree> upper) {
    assert(upper && upper->lowerBoundary() == value_ + 1);
    upper_ = std::move(upper);
}
void DecisionTree::setLower(std::unique_ptr<DecisionTree> lower) {
    assert(lower && lower->upperBoundary() == value_ - 1);
    lower_ = std::move(lower);
}
DecisionTree::DecisionTree(uint64_t value, DecisionTree &&lower,
                           DecisionTree &&upper)
    : DecisionTree{value, std::make_unique<DecisionTree>(std::move(lower)),
                   std::make_unique<DecisionTree>(std::move(upper))} {}

DecisionTree DecisionTree::build(uint64_t upperBoundary) {
    assert(upperBoundary > 1);
    DecisionTree firstLevel{upperBoundary - 1};
    uint64_t lowerBoundary{firstLevel.lowerBoundary()};

    while (lowerBoundary >= 4) {
        lowerBoundary -= 4;
        firstLevel.extend(lowerBoundary);
    }

    firstLevel.extend(1);

    return firstLevel;
}

DecisionTree DecisionTree::build(uint64_t upperBoundary, uint64_t max) {
    return DecisionTree(0);
}
void DecisionTree::extend(uint64_t till) {
    assert(till <= value_);
    assert((lowerBoundary() - till) < 5); //< only one group

    if (lower()) {
        lower_->extend(till);
    } else if (value_ - till <= 1) {
        return;
    } else if (value_ - till <= 3) {
        assert(value_ > 2);
        DecisionTree nextLowestGroup{value_ - 2};
        setLower(std::make_unique<DecisionTree>(std::move(nextLowestGroup)));
    } else if (value_ - till <= 5) {
        assert(value_ > 4);
        setLower(std::make_unique<DecisionTree>(
            value_ - 2, std::make_unique<DecisionTree>(value_ - 4)));
    } else {
        throw std::logic_error{"not implemented for " +
                               std::to_string(value_ - till)};
    }

    const auto upperMax{upper_ ? upper_->max() : 0};
    if (lower_ && lower_->max() + value() > (upperMax + value()) + lower()->value()) {
        DecisionTree node{value_, std::move(lower_->upper_), std::move(upper_)};

        upper_ = std::make_unique<DecisionTree>(std::move(node));
        value_ = lower_->value_;
        setLower(std::move(lower_->lower_));
    }

    assert(lowerBoundary() >= till);
}
uint64_t DecisionTree::upperBoundary() const {
    if (upper_) {
        return upper_->upperBoundary();
    }

    return value_ + 1;
}
uint64_t DecisionTree::lowerBoundary() const {
    if (lower_) {
        return lower_->lowerBoundary();
    }

    return std::max(1ul, value_ - 1);
}
uint64_t DecisionTree::extend() {
    uint64_t nextLowerBoundary{0};
    if (uint64_t low = lowerBoundary(); low > 1) {
        nextLowerBoundary = std::max(low, 5ul) - 4;
        extend(nextLowerBoundary);
    }

    return nextLowerBoundary;
}

void DecisionTree::print(const std::string &indent, size_t depth) const {
    if (upper()) {
        upper()->print(indent, depth + 1);
    }

    size_t levelCp{depth};
    while (levelCp--) {
        std::cout << indent;
    }
    std::cout << indent << value_ << " (" << max() << ", level " << depth
              << ")\n";

    if (lower()) {
        lower()->print(indent, depth + 1);
    }
}
