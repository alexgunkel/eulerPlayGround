
#ifndef EULERPLAYGROUND_DECISION_TREE_HPP
#define EULERPLAYGROUND_DECISION_TREE_HPP

#include <cinttypes>
#include <memory>

class DecisionTree {
  public:
    explicit DecisionTree(uint64_t value);
    DecisionTree(uint64_t value, std::unique_ptr<DecisionTree> lower, std::unique_ptr<DecisionTree> upper);
    DecisionTree(uint64_t value, DecisionTree&& lower, DecisionTree&& upper);
    DecisionTree(uint64_t value, std::unique_ptr<DecisionTree> lower);
    [[nodiscard]] uint64_t max() const;

    void extend(uint64_t till);

    [[nodiscard]] uint64_t value() const;
    void setUpper(std::unique_ptr<DecisionTree>);
    void setLower(std::unique_ptr<DecisionTree>);
    [[nodiscard]] const DecisionTree* upper() const;
    [[nodiscard]] const DecisionTree* lower() const;
    [[nodiscard]] uint64_t upperBoundary() const;
    uint64_t lowerBoundary() const;

    static DecisionTree build(uint64_t upperBoundary);
    static DecisionTree build(uint64_t upperBoundary, uint64_t max);

  private:
    uint64_t value_;
    std::unique_ptr<DecisionTree> upper_;
    std::unique_ptr<DecisionTree> lower_;
};

#endif // EULERPLAYGROUND_DECISION_TREE_HPP
