#ifndef DSA_IMPLEMENTATION_SIMPLEARRAYQUEUE_HPP
#define DSA_IMPLEMENTATION_SIMPLEARRAYQUEUE_HPP

#include <stdexcept>
#include <iostream>

template<typename T>
class SimpleArrayQueue {
    T* elements = nullptr;
    int front = 0;
    int back = 0;
    int occupied = 0;
    int capacity = 0;

    void clear() {
        delete[] elements;
        elements = nullptr;
        front = 0;
        back = 0;
        occupied = 0;
        capacity = 0;
    }

    void doubleCapacity() {
        capacity *= 2;
        T* newElements = new T[capacity];

        for (int i = 0; i < occupied; i++) {
            newElements[i] = elements[(i + front) % occupied];
        }

        front = 0;
        back = occupied;

        delete[] elements;
        elements = newElements;
    }

public:
    SimpleArrayQueue() : front(0), back(0), occupied(0), capacity(10) {
        elements = new T[capacity];
    }

    ~SimpleArrayQueue() {
        clear();
    }

    void enqueue(const T& value) {
        if (occupied == capacity) {
            doubleCapacity();
        }

        elements[back] = value;
        back = (back + 1) % capacity;
        occupied++;
    }

    T dequeue() {
        if (occupied == 0) {
            throw std::runtime_error("Empty queue!");
        }

        T result = elements[front];
        front = (front + 1) % capacity;
        occupied--;
        return result;
    }

    T head() const {
        if (occupied == 0) {
            throw std::runtime_error("Empty queue!");
        }

        return elements[back];
    }

    bool empty() const {
        return occupied == 0;
    }

    int getSize() const {
        return occupied;
    }
};

#endif //DSA_IMPLEMENTATION_SIMPLEARRAYQUEUE_HPP
