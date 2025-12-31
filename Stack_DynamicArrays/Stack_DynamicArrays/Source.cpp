#include <iostream>
using namespace std;
//Dynamic Array based implementation
class Stack {
private:
    int* arr;        // Pointer to dynamic array
    int top;         // Index of top element
    int capacity;    // Maximum capacity of stack

public:
    // Constructor
    Stack(int size = 5) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    // Copy Constructor (Deep Copy)
    Stack(const Stack& other) {
        capacity = other.capacity;
        top = other.top;
        arr = new int[capacity];          // allocate new memory
        for (int i = 0; i <= top; i++) {
            arr[i] = other.arr[i];         // copy elements
        }
        cout << "Copy constructor called.\n";
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }

    // Push element onto stack
    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Resizing stack...\n";
            resize();
        }
        arr[++top] = value;
    }

    // Pop element from stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
            return -1;
        }
        return arr[top--];
    }

    // Peek top element
    int peek() const {
        if (isEmpty()) {
            cout << "Stack is Empty!\n";
            return -1;
        }
        return arr[top];
    }

    // Check if stack is empty
    bool isEmpty() const {
        return top == -1;
    }

    // Check if stack is full
    bool isFull() const {
        return top == capacity - 1;
    }

    // Display elements
    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack elements (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

private:
    // Resize stack when full (double the size)
    void resize() {
        int newCapacity = capacity * 2;
        int* newArr = new int[newCapacity];
        for (int i = 0; i <= top; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr; //release old array
        arr = newArr;
        capacity = newCapacity;
        cout << "Stack resized to capacity " << capacity << endl;
    }
};

// Example usage
/*int main() {
    Stack s1(3);
    s1.push(10);
    s1.push(20);
    s1.push(30);

    cout << "Original stack (s1): ";
    s1.display();

    // Using copy constructor
    Stack s2 = s1; // Stack s2(s1);
    cout << "Copied stack (s2): ";
    s2.display();

    s2.push(40);
    cout << "\nAfter pushing 40 into s2:\n";
    cout << "s1: "; s1.display();
    cout << "s2: "; s2.display();

    return 0;
}*/
