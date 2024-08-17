#ifndef DSA_IMPLEMENTATION_SIMPLECIRCULARDOUBLYLINKEDLIST_HPP
#define DSA_IMPLEMENTATION_SIMPLECIRCULARDOUBLYLINKEDLIST_HPP

template<typename T>
class SimpleCircularDoublyLinkedList {
    struct Node {
        T value;
        Node* next = nullptr;
        Node* prev = nullptr;

        Node(const T& _value) : value(_value), next(nullptr), prev(nullptr) {}

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

    SimpleCircularDoublyLinkedList() : start(nullptr), size(0) {}

    ~SimpleCircularDoublyLinkedList() {
        clear();
    }

    void insertAt(int pos, const T& value) {
        if (pos < 0 || pos > size) {
            throw std::runtime_error("Invalid position!");
        }

        if (size == 0) {
            start = new Node(value);
            start->prev = start;
            start->next = start;
        }
        else {
            Node* current = new Node(value);
            Node* before = (pos == 0) ? start->prev : getItem(pos - 1);
            Node* after = before->next;

            current->prev = before;
            current->next = after;
            after->prev = current;
            before->next = current;

            if (pos == 0) {
                start = current;
            }
        }

        size++;
    }

    void deleteAt(int pos) {
        if (pos < 0 || pos > size - 1) {
            throw std::runtime_error("Invalid position!");
        }

        if (pos == 0) {
            Node* newStart = start->next;
            start->prev->next = newStart;
            newStart->prev = start->prev;
            delete start;
            start = newStart;
        }
        else {
            Node* before = getItem(pos - 1);
            Node* after = before->next->next;
            delete before->next;
            before->next = after;
            after->prev = before;
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
        int pos = size;

        Node* current = start;
        for (int i = 0; i < size; i++) {
            if (current->value) {
                pos = i;
                break;
            }
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
        Node* current = start;
        for (int i = 0; i < size; i++) {
            std::cout << current->value << " ";
            current = current->next;
        }
    }
};

#endif //DSA_IMPLEMENTATION_SIMPLECIRCULARDOUBLYLINKEDLIST_HPP
