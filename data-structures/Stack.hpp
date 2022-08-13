#ifndef DSA_IMPLEMENTATION_STACK_HPP
#define DSA_IMPLEMENTATION_STACK_HPP

template<typename T>
class Stack {
    /// Node of the stack
    struct Node {

        /// Node under the current node in stack
        Node* under;

        /// Value of the node
        T value;

        /// Constructor with value parameter
        Node(const T& _value) : under(nullptr) {
            value = _value;
        }

        /// Destructor
        ~Node() = default;
    };

    /// Current top of the stack
    Node* currentTop;


    /// Copy other stack
    /// Time complexity: O(n)
    void copy(Node* other) {
        if (currentTop) {
            throw std::invalid_argument("Current stack is not empty");
        }

        if (other) {
            currentTop = new Node(other->data);
            other = other->next;

            Node* iter = currentTop;
            while (other) {
                iter->next = new Node(other->data);
                iter = iter->next;
                other = other->next;
            }
        }
    }


    /// Empty stack
    /// Time complexity: O(n)
    void clear() {
        while (!empty()) {
            pop();
        }
    }

public:

    /// Default constructor
    /// Time complexity: O(1)
    Stack() : currentTop(nullptr) {}

    /// Copy constructor
    /// Time complexity: O(n)
    Stack(Stack const& other) {
        copy(other);
    }

    /// Copy assignment operator
    /// Time complexity: O(n)
    Stack& operator=(Stack const& other) {
        if (this != &other) {
            clear();
            copy(other);
        }
        return *this;
    }

    /// Destructor
    /// Time complexity: O(n)
    ~Stack() {
        clear();
    }

    /// Remove top of the stack
    /// Time complexity: O(1)
    T pop() {
        T result = currentTop->value;
        Node* temp = currentTop;
        currentTop = currentTop->under;
        delete temp;
        return result;
    }

    /// Add element to top of the stack
    /// Time complexity: O(1)
    void push(const T& element) {
        Node* newElement = new Node(element);
        newElement->under = currentTop;
        currentTop = newElement;
    }

    /// Get top value
    /// Time complexity: O(1)
    T peek() const {
        return currentTop->value;
    }

    /// Check if the stack is empty
    /// Time complexity: O(1)
    bool empty() const {
        return currentTop == nullptr;
    }

    /// Clear all stack elements
    /// Time complexity: O(n)
    void clearAll() {
        clear();
    }
};

#endif //DSA_IMPLEMENTATION_STACK_HPP
