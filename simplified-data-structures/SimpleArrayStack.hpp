#ifndef DSA_IMPLEMENTATION_SIMPLEARRAYSTACK_HPP
#define DSA_IMPLEMENTATION_SIMPLEARRAYSTACK_HPP

#include <stdexcept>

template<typename T>
class SimpleArrayStack {
    T* elements = nullptr;
    int occupied = 0;
    int capacity = 0;

    void clear() {
        delete[] elements;
        elements = nullptr;
        occupied = 0;
        capacity = 0;
    }

    void doubleCapacity() {
        capacity *= 2;
        T* newElements = new T[capacity];

        for (int i = 0; i < occupied; i++) {
            newElements[i] = elements[i];
        }

        delete[] elements;
        elements = newElements;
    }

public:
    SimpleArrayStack() : occupied(0), capacity(10) {
        elements = new T[10];
    }

    ~SimpleArrayStack() {
        clear();
    }

    void push(const T& value) {
        if (occupied == capacity) {
            doubleCapacity();
        }

        elements[occupied] = value;
        occupied++;
    }

    T pop() {
        if (occupied == 0) {
            throw std::runtime_error("Empty stack!");
        }

        occupied--;
        return elements[occupied];
    }

    T peek() const {
        if (occupied == 0) {
            throw std::runtime_error("Empty stack!");
        }
        return elements[occupied - 1];
    }

    bool empty() const {
        return occupied == 0;
    }

    int getSize() const {
        return occupied;
    }
};

#endif //DSA_IMPLEMENTATION_SIMPLEARRAYSTACK_HPP
