#ifndef DSA_IMPLEMENTATION_BINARYSEARCHTREE_HPP
#define DSA_IMPLEMENTATION_BINARYSEARCHTREE_HPP

template<typename T>
class BinarySearchTree {
    /// Tree node
    struct Node {

        /// Left child node
        Node* left;

        /// Right child node
        Node* right;

        /// Value of the current node
        T value;

        /// Constructor with value parameter
        Node(const T& _value) : left(nullptr), right(nullptr), value(_value) {}

        /// Destructor
        ~Node() = default;
    };

    /// Root of the binary tree
    Node* root;

    void clearSubtree(Node* myRoot) {
        if (!myRoot) {
            return;
        }

        clearSubtree(myRoot->left);
        clearSubtree(myRoot->right);
        delete myRoot;
        myRoot = nullptr;
    }

    /// Copy subtree method
    /// Time complexity: O(n)
    Node* copySubtree(Node* otherRoot) {
        if (!otherRoot) {
            return nullptr;
        }

        Node* myRoot = new Node(otherRoot->value);
        myRoot->left = copySubtree(otherRoot->left);
        myRoot->right = copySubtree(otherRoot->right);
        return myRoot;
    }

    /// Find element in subtree
    /// Time complexity: O(h)
    Node* findInSubtree(Node* myRoot, const T& element) {
        if (!myRoot) {
            return nullptr;
        }

        if (myRoot->value == element) {
            return myRoot;
        }

        if (myRoot->value > element) {
            return findInSubtree(myRoot->left, element);
        }

        return findInSubtree(myRoot->right, element);
    }

    /// Add element in subtree
    /// Time complexity: O(h)
    void addInSubtree(Node*& myRoot, const T& element) {
        if (!root) {
            root = new Node(element);
            return;
        }

        if (myRoot->value == element) {
            throw std::invalid_argument("Such element already exists");
        }

        if (myRoot->value > element) {
            addInSubtree(myRoot->left, element);
        }
        else {
            addInSubtree(myRoot->right, element);
        }
    }

    /// Count number of nodes in subtree
    /// Time complexity: O(n)
    int count(Node* myRoot) {
        if (!myRoot) {
            return 0;
        }

        return 1 + count(myRoot->left) + count(myRoot->right);
    }

    /// Remove max element in subtree
    /// Time complexity: O(h)
    Node* removeMax(Node* myRoot) {
        if (!myRoot) {
            return nullptr;
        }

        Node* current = myRoot;

        while(current->right) {
            current = current->right;
        }

        Node* max = current;
        current = current->left;
        max->left = nullptr;

        return max;
    }

public:

    /// Default constructor
    /// Time complexity: O(1)
    BinarySearchTree() : root(nullptr) {}

    /// Constructor with root value parameter
    /// Time complexity: O(1)
    BinarySearchTree(const T& element) {
        root = new Node(element);
    }

    /// Copy constructor
    /// Time complexity: O(n)
    BinarySearchTree(BinarySearchTree const& other) {
        root = copySubtree(other.root);
    }

    /// Copy assignment operator
    /// Time complexity: O(n)
    BinarySearchTree& operator=(BinarySearchTree const& other) {
        if (this != &other) {
            clearSubtree(root);
            root = copySubtree(other.root);
        }
        return *this;
    }

    /// Destructor
    /// Time complexity: O(n)
    ~BinarySearchTree() {
        clearSubtree(root);
    }

    /// Find node with specific value
    /// Time complexity: O(h)
    Node* find(const T& element) {
        findInSubtree(root, element);
    }

    /// Check if tree contains an element
    /// Time complexity: O(h)
    bool contains(const T& element) {
        return find(element);
    }

    /// Add element
    /// Time complexity: O(h)
    void add(const T& element) {
        addInSubtree(root, element);
    }

    /// Remove element from tree
    /// Time complexity: O(h)
    void remove(const T& element) {
        Node* toRemove = findInSubtree(root, element);
        Node* temp = toRemove;

        Node* newNode = removeMax(toRemove->left);
        newNode->left = toRemove->left;
        newNode->right = toRemove->right;

        toRemove = newNode;
        delete temp;
    }

    /// Clear tree
    /// Time complexity: O(n)
    void clearAll() {
        clearSubtree(root);
        root = nullptr;
    }

    /// Check if the tree is empty
    /// Time complexity: O(1)
    bool empty() {
        return !root;
    }

    /// Get the number of nodes in the tree
    /// Time complexity: O(n)
    int size() {
        return count(root);
    };
};

#endif //DSA_IMPLEMENTATION_BINARYSEARCHTREE_HPP
