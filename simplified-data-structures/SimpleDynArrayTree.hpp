#ifndef DSA_IMPLEMENTATION_SIMPLEDYNARRAYTREE_HPP
#define DSA_IMPLEMENTATION_SIMPLEDYNARRAYTREE_HPP

#include <vector>

template<typename T>
class SimpleDynArrayTree{
    T value;
    std::vector<SimpleDynArrayTree> children;

    void clear() {
        for (auto child : children) {
            child.clear();
        }
        children.empty();
    }

public:
    SimpleDynArrayTree(const T& _value) : value(_value) {}

    ~SimpleDynArrayTree() {
        clear();
    }

    T root() const {
        return value;
    }

    std::vector<SimpleDynArrayTree> const& subtrees() const {
        return children;
    }

    void addChild(const T& value) {
        children.push_back(SimpleDynArrayTree<T>(value));
    }

    void addSubtree(SimpleDynArrayTree tree) {
        children.push_back(tree);
    }

    int depth() {
        int maxDepth = 0;
        for (auto child : children) {
            maxDepth = std::max(maxDepth, child.depth());
        }
        return maxDepth + 1;
    }

    int breadth() {
        int maxBreadth = children.size();
        for (auto child : children) {
            maxBreadth = std::max(maxBreadth, child.breadth());
        }
        return maxBreadth;
    }
};

#endif //DSA_IMPLEMENTATION_SIMPLEDYNARRAYTREE_HPP
