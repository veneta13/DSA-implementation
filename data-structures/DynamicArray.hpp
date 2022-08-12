#ifndef DSA_IMPLEMENTATION_DYNAMICARRAY_HPP
#define DSA_IMPLEMENTATION_DYNAMICARRAY_HPP

#include <stdexcept>

template<typename T>
class DynamicArray {
    /// Currently allocated capacity
    int capacity;

    /// Number of elements currently in the array
    int count;

    /// Pointer to dynamic memory for array elements
    T* array;

    /// Clear all elements of the array
    /// Time complexity: O(n)
    void clear() {
        delete[] array;
        array = nullptr;
        capacity = 0;
        count = 0;
    }

    /// Double the allocated size of the array
    /// Time complexity: O(n)
    void resize() {
        T* temp = new T[capacity*2];
        try {
            for (int i = 0; i < count; i++) {
                temp[i] = array[i];
            }
        }
        catch (...) {
            delete[] temp;
            throw;
        }

        delete[] array;
        array = temp;
        temp = nullptr;
        capacity *= 2;
    }

public:

    /// Constructor with size parameter
    /// Time complexity: O(n)
    DynamicArray(int _capacity = 8) : capacity(_capacity), count(0) {
        if (_capacity < 1) {
            throw std::invalid_argument("Illegal initial size");
        }

        array = new T[capacity];
    }

    /// Copy constructor
    /// Time complexity: O(n)
    DynamicArray(DynamicArray const& other) {
        clear();

        capacity = other.capacity;
        count = other.count;
        array = new T[capacity];

        try {
            for (int i = 0; i < count; i++) {
                array[i] = other.array[i];
            }
        }
        catch (...) {
            delete[] array;
            throw;
        }
    }


    /// Copy assignment operator
    /// Time complexity: O(n)
    DynamicArray& operator=(DynamicArray const& other) {
        if (this != &other) {
            clear();
            capacity = other.capacity;
            count = other.count;
            array = new T[capacity];

            try {
                for (int i = 0; i < count; i++) {
                    array[i] = other.array[i];
                }
            }
            catch (...) {
                delete[] array;
                throw;
            }
        }

        return *this;
    }


    /// Destructor
    /// Time complexity: O(n)
    ~DynamicArray() {
        clear();
    }


    /// Get element at index
    /// Time complexity: O(1)
    T* operator[](int index) const {
        if (index > count - 1 || index < 0) {
            throw std::invalid_argument("Index out of bound");
        }
        return array[index];
    }

    /// Add element at index
    /// Time complexity: O(n)
    void insertAt(int index, const T& element) {
        if (index > count - 1 || index < 0) {
            throw std::invalid_argument("Index out of bound");
        }

        if (count == capacity) {
            resize();
        }

        for (int i = count-1; i >= index; i--) {
            array[i+1] = array[i];
        }
        array[index] = element;

        count++;
    }

    /// Remove element at index
    /// Time complexity: O(n)
    void removeAt(int index) {
        if (index > count - 1 || index < 0) {
            throw std::invalid_argument("Index out of bound");
        }

        count--;

        for (int i = index; i < count; i++) {
            array[i] = array[i+1];
        }
    }

    /// Add element at the back of the array
    /// Time complexity: O(n)
    void pushBack(const T& element) {
        insertAt(count);
    }

    /// Remove last element from array
    /// Time complexity: O(n)
    void popBack(const T& element) {
        removeAt(count-1);
    }

    /// Find index of element in the array
    /// \param element element to search for
    /// \return index of the element | -1 if such element does not exist|
    /// Time complexity: O(n)
    int find(const T& element) const {
        for (int i = 0; i < count; i++) {
            if (array[i] == element) {
                return i;
            }
        }

        return -1;
    }

    /// Get number of elements in dynamic array
    /// Time complexity: O(1)
    int getCount() const {
        return count;
    }

    /// Get allocated capacity of the array
    /// Time complexity: O(1)
    int getCapacity() const {
        return capacity;
    }

    /// Check if the array is empty
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

#endif //DSA_IMPLEMENTATION_DYNAMICARRAY_HPP
