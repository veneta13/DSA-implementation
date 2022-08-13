#ifndef DSA_IMPLEMENTATION_QUEUE_HPP
#define DSA_IMPLEMENTATION_QUEUE_HPP

template<typename T>
class Queue {
    /// Node of the queue
    struct Node {

        /// Next element in queue
        Node* next;

        /// Value of the current element
        T value;

        /// Constructor with value parameter
        Node(const T& _value) : next(nullptr) {
            value = _value;
        }

        /// Destructor
        ~Node() = default;
    };

    /// Current fist element in queue
    Node* first;

    /// Current last element in queue
    Node* last;

    /// Copy another queue
    /// Time complexity: O(n)
    void copy(Node* other) {
        if (first) {
            throw std::runtime_error("Queue not empty");
        }

        if (other) {
            first = new Node(other->next);
            Node* iter = first;
            other = other->next;

            while (other) {
                iter->next = new Node(other->value);
                iter = iter->next;
                other = other->next;
            }

            last = iter;
        }
    }

    /// Empty queue
    /// Time complexity: O(n)
    void clear() {
        while (!empty()) {
            dequeue();
        }
    }

public:

    /// Default constructor
    /// Time complexity: O(1)
    Queue() : first(nullptr), last(nullptr) {}

    /// Copy constructor
    /// Time complexity: O(n)
    Queue(Queue const& other) {
        try {
            copy(other.first);
        }
        catch (...) {
            clear();
            throw;
        }
    }

    /// Copy assignment operator
    /// Time complexity: O(n)
    Queue& operator=(Queue const& other) {
        if (this != &other) {
            clear();
            copy(other.first);
        }
        return *this;
    }

    /// Destructor
    /// Time complexity: O(n)
    ~Queue() {
        clear();
    }

    /// Enqueue element
    /// Time complexity: O(1)
    void enqueue(const T& element) {
        Node* newLast = new Node(element);

        if (!first && !last) {
            first = newLast;
            last = newLast;
            return;
        }

        last->next = newLast;
        last = newLast;
    }

    /// Dequeue element
    /// Time complexity: O(1)
    T dequeue() {
        if (!first) {
            throw std::underflow_error("Queue already empty");
        }

        T result = first->value;

        if (first == last) {
            delete first;
            first = nullptr;
            last = nullptr;
        }
        else {
            Node* removed = first;
            first = first->next;
            delete removed;
        }

        return result;
    }

    /// Peek the value of first element in queue
    /// Time complexity: O(1)
    T peek() const {
        if (!first) {
            throw std::underflow_error("Queue empty");
        }

        return first->value;
    }

    /// Check if queue is empty
    /// Time complexity: O(1)
    bool empty() const {
        return first == nullptr;
    }
};

#endif //DSA_IMPLEMENTATION_QUEUE_HPP
