#ifndef DSA_IMPLEMENTATION_DOUBLYLINKEDLIST_HPP
#define DSA_IMPLEMENTATION_DOUBLYLINKEDLIST_HPP

template<typename T>
class DoublyLinkedList {
    /// List node
    struct Node {

        /// Next element
        Node* next;

        /// Previous element
        Node* prev;

        /// Value of the node
        T value;

        /// Constructor with value parameters
        Node(const T& _value) : next(nullptr), prev(nullptr) {
            value = _value;
        }

        /// Destructor
        ~Node() = default;
    };

    /// Element at the front of the list
    Node* first;

    /// Last element at the back of the list
    Node* last;

    /// Number of elements in the list
    int count;

    /// Delete all elements in the linked list
    /// Time complexity: O(n)
    void clear () {
        Node* current = first;

        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }

        first = nullptr;
        last = nullptr;
        count = 0;
    }

public:
    /// Default constructor
    /// Time complexity: O(1)
    DoublyLinkedList() : first(nullptr), last(nullptr), count(0) {}

    /// Copy constructor
    /// Time complexity: O(n)
    DoublyLinkedList(DoublyLinkedList const& other) {
        Node dummy;
        Node* currentOther = other.first;
        Node* currentThis = dummy;

        while (currentOther) {
            currentThis->next = new Node(currentOther->value);
            currentThis->next->prev = currentThis;
            currentThis = currentThis->next;
            currentOther = currentOther->next;
        }

        first = dummy.next;
        last = first ? currentThis : nullptr;  // if the list is empty it should not be dummy
        count = other.count;
    }

    /// Copy assignment operator
    /// Time complexity: O(n)
    DoublyLinkedList& operator=(DoublyLinkedList const& other) {
        if (this != &other) {
            clear();

            Node dummy;
            Node* currentOther = other.first;
            Node* currentThis = dummy;

            while (currentOther) {
                currentThis->next = new Node(currentOther->value);
                currentThis->next->prev = currentThis;
                currentThis = currentThis->next;
                currentOther = currentOther->next;
            }

            first = dummy.next;
            last = first ? currentThis : nullptr;  // if the list is empty it should not be dummy
            count = other.count;
        }
        return *this;
    }

    /// Destructor
    /// Time complexity: O(n)
    ~DoublyLinkedList() {
        clear();
    }

    /// Add element at the back of the list
    /// Time complexity: O(1)
    void pushBack(const T& element) {
        if (!last) {
            last = new Node(element);
            first = last;
        }
        else {
            last->next = new Node(element);
            last->next->prev = last;
            last = last->next;
        }
        count++;
    }

    /// Remove the last element of the list
    /// Time complexity: O(1)
    T popBack() {
        if (!last) {
            throw std::runtime_error("List is empty");
        }

        if (first == last) {
            T value = first->value;
            clear();
            return value;
        }

        T value = last->value;
        last = last->prev;
        delete last->next;
        last->next = nullptr;
        count--;
        return value;
    }

    /// Add element at the beginning of the list
    /// Time complexity: O(1)
    void pushFront(const T& element) {
        if (!first) {
            throw std::runtime_error("List is empty");
        }

        Node* current = new Node(element);
        current->next = first;
        first->prev = current;
        first = current;
        count++;
    }

    /// Remove the first element of the list
    /// Time complexity: O(1)
    T popFront(const T& element) {
        if (!first) {
            throw std::runtime_error("List is empty");
        }

        if (first == last) {
            return popBack();
        }

        Node* current = first;
        first = first->next;
        first->prev = nullptr;
        delete current;
        count--;
    }

    /// Check if list contains an element
    /// Time complexity: O(n)
    bool find(const T& element) {
        Node* current = first;

        while (current) {
            if (current->value == element) {
                return true;
            }
            current = current->next;
        }

        return false;
    }

    /// Get number of elements in list
    /// Time complexity: O(1)
    int getCount() {
        return count;
    }

    /// Check if list is empty
    /// Time complexity: O(1)
    bool empty() {
        return count == 0;
    }

    /// Clear all elements
    /// Time complexity: O(n)
    void clearAll() {
        clear();
    }
};

#endif //DSA_IMPLEMENTATION_DOUBLYLINKEDLIST_HPP
