#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* arr;       // pointer to the array
    int capacity;   // maximum size
    int size;       // current number of elements

    // function to resize array when full
    void resize() {
        int newCapacity = capacity * 2;
        int* newArr = new int[newCapacity];
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
    }

public:
    // constructor
    DynamicArray(int cap = 4) {
        capacity = cap;
        size = 0;
        arr = new int[capacity];
    }

    // copy constructor (deep copy)
    DynamicArray(const DynamicArray& other) {
        capacity = other.capacity;
        size = other.size;
        arr = new int[capacity];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }

    // assignment operator (deep copy)
    DynamicArray& operator=(const DynamicArray& other) {
        if (this == &other) return *this; // self-assignment check

        delete[] arr; // free old memory

        capacity = other.capacity;
        size = other.size;
        arr = new int[capacity];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
        return *this;
    }

    // destructor
    ~DynamicArray() {
        delete[] arr;
    }

    // insert element at the end
    void insert(int value) {
        if (size == capacity) {
            resize();
        }
        arr[size++] = value;
    }

    // insert element at specific index
    void insertAt(int index, int value) {
        if (index < 0 || index > size) {
            cout << "Index out of bounds\n";
            return;
        }
        if (size == capacity) {
            resize();
        }
        for (int i = size; i > index; i--) {
            arr[i] = arr[i - 1]; // shift right
        }
        arr[index] = value;
        size++;
    }

    // delete element at given index
    void remove(int index) {
        if (index < 0 || index >= size) {
            cout << "Index out of bounds\n";
            return;
        }
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    // modify element at given index
    void modify(int index, int value) {
        if (index < 0 || index >= size) {
            cout << "Index out of bounds\n";
            return;
        }
        arr[index] = value;
    }

    // display all elements
    void display() {
        cout << "[ ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << "]\n";
    }

    // get element at index
    int get(int index) {
        if (index < 0 || index >= size) {
            cout << "Index out of bounds\n";
            return -1;
        }
        return arr[index];
    }

    // return current size
    int getSize() {
        return size;
    }
};

// --------- Demo ----------
int main() {
    DynamicArray da;

    da.insert(10);
    da.insert(20);
    da.insert(30);
    da.insert(40);
    da.display();   // [ 10 20 30 40 ]

    da.insertAt(2, 99);
    da.display();   // [ 10 20 99 30 40 ]

    da.remove(1);
    da.display();   // [ 10 99 30 40 ]

    da.modify(0, 77);
    da.display();   // [ 77 99 30 40 ]

    // Copy constructor test
    DynamicArray copyArr = da;
    copyArr.insert(500);
    cout << "Original: "; da.display();
    cout << "Copy: "; copyArr.display();

    return 0;
}
