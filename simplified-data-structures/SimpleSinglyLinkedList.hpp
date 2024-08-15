#ifndef DSA_IMPLEMENTATION_SIMPLESINGLYLINKEDLIST_HPP
#define DSA_IMPLEMENTATION_SIMPLESINGLYLINKEDLIST_HPP

#include <stdexcept>
#include <iostream>

template<typename T>
class SimpleSinglyLinkedList {
    struct Node {
        T value;
        Node* next = nullptr;

        Node(const T& _value) : value(_value), next(nullptr) {}

        ~Node() = default;
    };

    Node* front = nullptr;
    int size = 0;

    void clear() {
        Node* current = front;

        while (current) {
            Node* temp = current;
            current = temp->next;
            delete temp;
        }

        size = 0;
        front = nullptr;
    }

    Node* getItem(int pos) {
        Node* current = front;
        for (int i = 0; i < pos; i++) {
            current = current->next;
        }
        return current;
    }

public:
    SimpleSinglyLinkedList() : front(nullptr), size(0) {}

    ~SimpleSinglyLinkedList() {
        clear();
    }

    void insertAt(int pos, const T& _value) {
        if (pos < 0 || pos > size) {
            throw std::runtime_error("Invalid position!");
        }

        // !! Edge case !!
        if (size == 0) {
            front = new Node(_value);
        }
        else {
            Node* current = getItem(pos - 1);
            Node* newNext = current->next;
            current->next = new Node(_value);
            current->next->next = newNext;
        }

        size++;
    }

    void deleteAt(int pos) {
        if (pos < 0 || pos > size - 1) {
            throw std::runtime_error("Invalid position!");
        }

        if (pos == 0) {
            Node* current = front->next;
            delete front;
            front = current;
        }
        else {
            Node* current = getItem(pos - 1);
            Node* temp = current->next->next;
            delete current->next;
            current->next = temp;
        }

        size--;
    }

    T getAt(int pos) {
        if (pos < 0 || pos > size - 1) {
            throw std::runtime_error("Invalid position!");
        }

        return getItem(pos)->value;
    }

    bool empty() {
        return size == 0;
    }

    int getSize() {
        return size;
    }

    void print() {
        Node* current = front;
        while(current) {
            std::cout << current->value << " ";
            current = current->next;
        }
    }
};

#endif //DSA_IMPLEMENTATION_SIMPLESINGLYLINKEDLIST_HPP
