#ifndef DSA_IMPLEMENTATION_SIMPLEDOUBLYLINKEDLIST_HPP
#define DSA_IMPLEMENTATION_SIMPLEDOUBLYLINKEDLIST_HPP

#include <stdexcept>

template<typename T>
class SimpleDoublyLinkedList {
    struct Node {
        T value;
        Node* next = nullptr;
        Node* prev = nullptr;

        Node(const T& _value) : value(_value), next(nullptr), prev(nullptr) {}

        ~Node() = default;
    };

    Node* front = nullptr;
    int size = 0;

    void clear() {
        Node* current = front;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }

        front = nullptr;
        size = 0;
    }

    Node* getItem(int pos) {
        Node* current = front;
        for (int i = 0; i < pos; i++) {
            current = current->next;
        }
        return current;
    }

public:
    SimpleDoublyLinkedList() : front(nullptr), size(0) {};

    ~SimpleDoublyLinkedList() {
        clear();
    }

    void insertAt(int pos, const T& value) {
        if (pos < 0 || pos > size) {
            throw std::runtime_error("Invalid position!");
        }

        if (size == 0) {
            front = new Node(value);
            front->next = nullptr;
            front->prev = nullptr;
        }
        else {
            Node* next = getItem(pos);
            Node* prev = next ? next->prev : getItem(pos - 1);
            Node* current = new Node(value);

            current->prev = prev;
            current->next = next;
            if (next) {
                next->prev = current;
            }
            if (prev) {
                prev->next = current;
            }

            if (pos == 0) {
                front = current;
            }
        }

        size++;
    }

    void deleteAt(int pos) {
        if (pos < 0 || pos > size - 1) {
            throw std::runtime_error("Invalid position!");
        }

        Node* current = getItem(pos);
        Node* prev = current->prev;
        Node* next = current->next;

        if (prev) {
            prev->next = next;
        }
        if (next) {
            next->prev = prev;
        }
        delete current;

        if (pos == 0) {
            front = next;
        }

        size--;
    }

    T getAt(int pos) const {
        if (pos < 0 || pos > size - 1) {
            throw std::runtime_error("Invalid position!");
        }

        return getItem(pos)->value;
    }

    int find(const T& value) const {
        int pos = 0;

        Node* current = front;
        while (current) {
            if (current->value == value) {
                break;
            }
            pos++;
            current = current->next;
        }

        return pos == size ? -1 : pos;
    }

    bool empty() const {
        return size == 0;
    }

    int getSize() const {
        return size;
    }

    void print() const {
        Node* current = front;
        while(current) {
            std::cout << current->value << " ";
            current = current->next;
        }
    }
};

#endif //DSA_IMPLEMENTATION_SIMPLEDOUBLYLINKEDLIST_HPP
