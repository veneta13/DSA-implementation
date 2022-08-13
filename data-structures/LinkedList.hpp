#ifndef DSA_IMPLEMENTATION_LINKEDLIST_HPP
#define DSA_IMPLEMENTATION_LINKEDLIST_HPP

template<typename T>
class LinkedList {
    /// List node
    struct Node {

        /// Next element
        Node* next;

        /// Value of the node
        T value;

        /// Constructor with value parameters
        Node(const T& _value) {
            value = _value;
            next = nullptr;
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
    void clear() {
        Node* current = first;

        while(current) {
            Node* temp = current;
            current = temp->next;
            delete temp;
        }

        first = nullptr;
        last = nullptr;
        count = 0;
    };

public:
    /// Default constructor
    /// Time complexity: O(1)
    LinkedList() : count(0), first(nullptr), last(nullptr) {}

    /// Copy constructor
    /// Time complexity: O(n)
    LinkedList(LinkedList const& other) {
        Node dummy;
        Node* currentOther = other.first;
        Node* currentThis = dummy;

        while (currentOther) {
            currentThis->next = new Node(currentOther->value);
            currentThis = currentThis->next;
            currentOther = currentOther;
        }

        first = dummy.next;
        last = first ? currentThis : nullptr; // if the list is empty it should not be dummy
        count = other.count;
    }

    /// Copy assignment operator
    /// Time complexity: O(n)
    LinkedList& operator=(LinkedList const& other) {
        if (this != &other) {
            clear();

            Node dummy;
            Node* currentOther = other.first;
            Node* currentThis = dummy;

            while (currentOther) {
                currentThis->next = new Node(currentOther->value);
                currentThis = currentThis->next;
                currentOther = currentOther;
            }

            first = dummy.next;
            last = first ? currentThis : nullptr; // if the list is empty it should not be dummy
            count = other.count;
        }
        return *this;
    }

    /// Destructor
    /// Time complexity: O(n)
    ~LinkedList() {
        clear();
    }

    /// Add element at the back of the list
    /// Time complexity: O(1)
    void pushBack(const T& element) {
        if (!last) {
            first = new Node(element);
            last = first;
        }
        else {
            last->next = new Node(element);
            last = last->next;
        }
        count++;
    }

    /// Remove the last element of the list
    /// Time complexity: O(n)
    T popBack() {
        if (!first) {
            throw std::runtime_error("List is empty");
        }

        if (first == last) {
            T value = first->value;
            clear();
            return value;
        }

        Node* current = first;

        while (current->next != last) {
            current = current->next;
        }

        T value = current->next->value;
        delete current->next;

        last = current;
        count--;
    }

    /// Add element at the beginning of the list
    /// Time complexity: O(1)
    void pushFront(const T& element) {
        Node* current = new Node(element);

        current->next = first;
        first = current;
        count++;

        if (!last) {
            last = first;
        }
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

        T value = first->value;
        Node* current = first;
        first = first->next;
        delete current;
        count--;
        return value;
    }

    /// Check if list contains an element
    /// Time complexity: O(n)
    bool find(const T& element) const {
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
    int getCount() const {
        return count;
    }

    /// Check if list is empty
    /// Time complexity: O(1)
    bool empty() const {
        return count == 0;
    }

    /// Clear all elements
    /// Time complexity: O(n)
    void clearAll() {
        clear();
    }
};

#endif //DSA_IMPLEMENTATION_LINKEDLIST_HPP
