#ifndef DSA_IMPLEMENTATION_SIMPLECIRCULARSINGLYLINKEDLIST_HPP
#define DSA_IMPLEMENTATION_SIMPLECIRCULARSINGLYLINKEDLIST_HPP

#include <stdexcept>

template<typename T>
class SimpleCircularSinglyLinkedList {
    struct Node {
        T value;
        Node* next;

        Node(const T& _value) : value(_value), next(nullptr) {}

       ~Node() = default;
    };

    Node* start = nullptr;
    int size = 0;

    void clear() {
        Node* current = start;
        for (int i = 0; i < size; i++) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }

        start = nullptr;
        size = 0;
    }

    Node* getItem(int pos) {
        Node* current = start;
        for (int i = 0; i < pos; i++) {
            current = current->next;
        }
        return current;
    }

public:
    SimpleCircularSinglyLinkedList() : start(nullptr), size(0) {}

    ~SimpleCircularSinglyLinkedList() {
        clear();
    }

    void insertAt(int pos, const T& value) {
        if (pos < 0 || pos < size - 1) {
            throw std::runtime_error("Invalid position!");
        }

        if (size == 0) {
            start = new Node(value);
            start->next = start;
        }
        else {
            Node* current = getItem(pos - 1);
            Node* nextNode = current->next;
            current->next = new Node(value);
            current->next->next = nextNode;
        }

        size++;
    }

    void deleteAt(int pos) {
        if (pos < 0 || pos > size - 1) {
            throw std::runtime_error("Invalid position!");
        }

        if (pos == 0) {
            Node* before = getItem(size - 1);
            Node* after = before->next->next;
            delete start;
            before->next = start;
            start = after;
        }
        else {
            Node* before = getItem(pos - 1);
            Node* after = before->next->next;
            delete before->next;
            before->next = after;
        }

        size--;
    }

    T getAt(int pos) {
        if (pos < 0 || pos > size - 1) {
            throw std::runtime_error("Invalid position!");
        }

        return getItem(pos)->value;
    }

    int find(const T& value) {
        int pos = size;

        Node* current = start;
        for (int i = 0; i < size; i++) {
            if (current->value == value) {
                pos = i;
                break;
            }
            current = current->next;
        }

        return pos == size ? -1 : pos;
    }

    bool empty() {
        return size == 0;
    }

    int getSize() {
        return size;
    }

    void print() {
        Node* current = start;
        for (int i = 0; i < size; i++) {
            std::cout << current->value << " ";
            current = current->next;
        }
    }
};

#endif //DSA_IMPLEMENTATION_SIMPLECIRCULARSINGLYLINKEDLIST_HPP
