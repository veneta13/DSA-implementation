#ifndef DSA_IMPLEMENTATION_BINARYTREE_HPP
#define DSA_IMPLEMENTATION_BINARYTREE_HPP

template<class T>
class BinaryTree {
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

    /// Clear all nodes in a subtree
    /// Time complexity: O(n)
    void clearSubtree(Node* myRoot) {
        if (!myRoot) {
            return;
        }

        clearSubtree(myRoot->right);
        clearSubtree(myRoot->left);
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
    /// Time complexity: O(n)
    Node* findInSubtree(Node* myRoot, const T& element) {
        if (!myRoot) {
            return nullptr;
        }

        if (myRoot->value == element) {
            return myRoot;
        }

        Node* result;
        result = findInSubtree(myRoot->left, element);
        if (result) return result;
        result = findInSubtree(myRoot->right, element);
        return result;
    }

    /// Count nodes
    /// Time complexity: O(n)
    int count(Node* myRoot) {
        if (!myRoot) {
            return 0;
        }

        return 1 + count(myRoot->left) + count(myRoot->right);
    }

public:

    /// Default constructor
    /// Time complexity: O(1)
    BinaryTree() : root(nullptr) {}

    /// Constructor with root value parameter
    /// Time complexity: O(1)
    BinaryTree(const T& element) {
        root = new Node(element);
    }

    /// Copy constructor
    /// Time complexity: O(n)
    BinaryTree(BinaryTree const& other) {
        root = copySubtree(other.root);
    }

    /// Copy assignment operator
    /// Time complexity: O(n)
    BinaryTree& operator=(BinaryTree const& other) {
        if (this != &other) {
            clearSubtree(root);
            root = copySubtree(other.root);
        }
        return *this;
    }

    /// Destructor
    /// Time complexity: O(n)
    ~BinaryTree() {
        clearSubtree(root);
    }

    /// Find node with specific value
    /// Time complexity: O(n)
    Node* find(const T& element) {
        return findInSubtree(root, element);
    }

    /// Check if tree contains an element
    /// Time complexity: O(n)
    bool contains(const T& element) {
        return findInSubtree(root, element);
    }

    /// Add tree under parent
    /// This method uses preorder traversal to find parent
    /// and tries to append to first found instance
    /// Time complexity: O(n)
    void add(const T& parent, const T& element) {
        Node* parentNode = find(parent);
        if (!parent) {
            throw std::invalid_argument("Parent node not found");
        }

        if (!parentNode->left) {
            parentNode->left = new Node(element);
            return;
        }

        if (!parentNode->right) {
            parentNode->right = new Node(element);
            return;
        }

        throw std::invalid_argument("Parent node already has left and right child");
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
        return root == nullptr;
    }

    /// Get the number of nodes in the tree
    /// Time complexity: O(n)
    int size() {
        return count(root);
    };
};

#endif //DSA_IMPLEMENTATION_BINARYTREE_HPP
