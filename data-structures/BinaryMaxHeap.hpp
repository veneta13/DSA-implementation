#ifndef DSA_IMPLEMENTATION_BINARYMAXHEAP_HPP
#define DSA_IMPLEMENTATION_BINARYMAXHEAP_HPP

#include <vector>
#include <algorithm> /// for merge

using std::vector;

template<typename T>
class BinaryMaxHeap {

    /// Elements stored in the heap
    vector<T> elements;

    /// Get index of parent node
    /// Time complexity: O(1)
    int parent(int n) {
        if (n == 0) {
            throw std::invalid_argument("Root node has no parent");
        }

        return (n - 1) / 2;
    }

    /// Get index of left child
    /// Time complexity: O(1)
    int leftChild(int n) {
        return (2 * n) + 1;
    }

    /// Get index of right child
    /// Time complexity: O(1)
    int rightChild(int n) {
        return (2 * n) + 2;
    }

    /// Empty heap
    /// Time complexity: O(n)
    void clear() {
        elements.clear();
    }

public:

    /// Default constructor
    /// Time complexity: O(1)
    BinaryMaxHeap() = default;

    /// Copy constructor
    /// Time complexity: O(n)
    BinaryMaxHeap(BinaryMaxHeap const& other) {
        this->elements = other.elements;
    }

    /// Copy assignment operator
    /// Time complexity: O(n)
    BinaryMaxHeap& operator=(BinaryMaxHeap const& other) {
        if (this != &other) {
            this->elements = other.elements;
        }
        return *this;
    }

    /// Destructor
    /// Time complexity: O(n)
    ~BinaryMaxHeap() {
        clear();
    }

    /// Insert element in heap
    /// Time complexity: O(log n)
    void insert(const T& element) {
        elements.push_back(element);

        int current = elements.size() - 1;

        while (current > 0 && elements[parent(current)] < elements[current]) {
            std::swap(element[parent(current)], elements[current]);
            current = parent(current);
        }
    }


    /// Extract the value of the top of the heap
    /// Time complexity: O(log n)
    void extractMax() {
        T result = max();

        elements[0] = elements.back();
        elements.pop_back();

        int current = 0;
        int lChild = leftChild(current);
        int rChild = rightChild(current);

        int compared = (rChild < elements.size() && elements[rChild] > elements[lChild]) ? rChild : lChild;

        while (compared < elements.size())
        {
            if (elements[current] > elements[compared]) {
                break;
            }

            std::swap(elements[current], elements[compared]);
            current = compared;
            lChild = leftChild(current);
            rChild = rightChild(current);

            compared = (rChild < elements.size() && elements[rChild] > elements[lChild]) ? rChild : lChild;
        }

        return result;
    }

    /// Get max element / top of the heap
    /// Time complexity: O(1)
    T max() {
        if (elements.empty()) {
            throw std::underflow_error("Heap is empty");
        }
        return elements[0];
    }

    /// Join with another heap
    /// Time complexity: O(n)
    void join(BinaryMaxHeap const& other) {
        vector<T> result;
        std::merge(elements.begin(), elements.end(),
              other.elements.begin(), other.elements.end(),
              result.begin());
        elements = result;
    }
};

#endif //DSA_IMPLEMENTATION_BINARYMAXHEAP_HPP
