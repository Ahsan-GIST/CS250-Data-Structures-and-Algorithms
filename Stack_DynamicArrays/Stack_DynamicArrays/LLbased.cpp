#include <iostream>
using namespace std;

// Node structure for linked list
struct node {
    int data;
    node* next;
};

class Stack {
private:
    node* top;  // Pointer to top node

public:
    // Default constructor
    Stack() {
        top = nullptr;
    }

    // Copy constructor (deep copy)
    Stack(const Stack& s) {
        if (s.top == nullptr) {
            top = nullptr;
        }
        else {
            // Copy all nodes
            node* srcPtr = s.top;
            node* destPrev = nullptr;
            node* newNode = nullptr;

            // Copy first node
            top = new node;
            top->data = srcPtr->data;
            top->next = nullptr;
            destPrev = top;
            srcPtr = srcPtr->next;

            // Copy remaining nodes
            while (srcPtr != nullptr) {
                newNode = new node;
                newNode->data = srcPtr->data;
                newNode->next = nullptr;
                destPrev->next = newNode;
                destPrev = newNode;
                srcPtr = srcPtr->next;
            }
        }
        cout << "Copy constructor called.\n";
    }

    // Destructor
    ~Stack() {
        while (!IsEmpty()) {
            pop(); //deleting remaining nodes in the stack
        }
    }

    // Check if stack is empty
    bool IsEmpty() {
        return (top == nullptr);
    }

    // Push new item onto stack
    void push(int newItem) {
        node* newNode = new node;
        newNode->data = newItem;
        newNode->next = top;
        top = newNode;
    }

    // Pop top item from stack
    void pop() {
        if (IsEmpty()) {
            cout << "Stack Underflow! Cannot pop.\n";
            return;
        }
        node* temp = top; // int tempdata = top->data;
        top = top->next; 
        delete temp;
        //return tempdata;
    }

    // Get top item
    int getTop() {
        if (IsEmpty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return top->data;
    }

    // Display stack elements (optional helper)
    void display() {
        if (IsEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        node* temp = top;
        cout << "Stack elements (top to bottom): ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Example usage
int main() {
    Stack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);

    cout << "Original Stack (s1): ";
    s1.display();

    // Using copy constructor
    Stack s2 = s1;
    cout << "Copied Stack (s2): ";
    s2.display();

    s2.push(40); // s2.pop();
    cout << "\nAfter popping one element from s2:\n";
    cout << "s1: "; s1.display();
    cout << "s2: "; s2.display();

    cout << "\nTop of s1: " << s1.getTop() << endl;
    return 0;
}
