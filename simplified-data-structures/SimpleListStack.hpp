#ifndef DSA_IMPLEMENTATION_SIMPLELISTSTACK_HPP
#define DSA_IMPLEMENTATION_SIMPLELISTSTACK_HPP

#include <stdexcept>

template<typename T>
class SimpleListStack {
    struct Node {
        T value;
        Node* next = nullptr;

        Node(const T& _value) : value(_value), next(nullptr) {}

        ~Node() = default;
    };

    Node* top = nullptr;
    int size = 0;

    void clear() {
        Node* current = top;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }

        top = nullptr;
        size = 0;
    }

public:
    SimpleListStack() : top(nullptr), size(0) {}

    ~SimpleListStack() {
        clear();
    }

    void push(const T& value) {
        Node* current = new Node(value);
        current->next = top;
        top = current;
        size++;
    }

    T pop() {
        if (!top) {
            throw std::runtime_error("Empty stack!");
        }

        Node* current = top;
        T result = current->value;
        top = top->next;
        size--;
        delete current;
        return result;
    }

    T peek() {
        if (!top) {
            throw std::runtime_error("Empty stack!");
        }

        return top->value;
    }

    bool empty() {
        return size == 0;
    }

    int getSize() {
        return size;
    }
};

#endif //DSA_IMPLEMENTATION_SIMPLELISTSTACK_HPP
