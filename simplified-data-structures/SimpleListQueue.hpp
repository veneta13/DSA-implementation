#ifndef DSA_IMPLEMENTATION_SIMPLELISTQUEUE_HPP
#define DSA_IMPLEMENTATION_SIMPLELISTQUEUE_HPP

#include <stdexcept>

template<typename T>
class SimpleListQueue {
    struct Node {
        T value;
        Node* next;

        Node(const T& _value) : value(_value), next(nullptr) {}

        ~Node() = default;
    };

    Node* front = nullptr;
    Node* back = nullptr;
    int size = 0;

    void clear() {
        Node* current = front;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }

        front = nullptr;
        back = nullptr;
        size = 0;
    }

public:
    SimpleListQueue() : front(nullptr), back(nullptr), size(0) {}

    ~SimpleListQueue() {
        clear();
    }

    void enqueue(const T& value) {
        if (size == 0) {
            front = back = new Node(value);
        }
        else {
            back->next = new Node(value);
            back = back->next;
        }
        size++;
    }

    T dequeue() {
        if (size == 0) {
            throw std::runtime_error("Empty queue!");
        }

        T result = front->value;
        Node* temp = front;
        front = front->next;
        size--;
        delete temp;
        return result;
    }

    T head() const {
        return front->value;
    }

    bool empty() const {
        return size == 0;
    }

    int getSize() const {
        return size;
    }
};

#endif //DSA_IMPLEMENTATION_SIMPLELISTQUEUE_HPP
