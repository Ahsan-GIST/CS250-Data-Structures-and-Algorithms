#include <iostream>
using namespace std;

// A simple implementation using a fixed-size array and front and rear pointers.
const int Max_Queue = 5;

class Queue {
private:
    int arr[Max_Queue];
    int rear, front;  // front may get memory just after arr (will see in logical erro)
    int size; // optional - same as count variable in next implementation.

public:
    Queue() {
        front = 0;
        rear = -1;
        size = 0;
    }

    bool isFull() {
        return size == Max_Queue; // OR return rear == Max_Queue-1; 
        
    }

    bool isEmpty() {
        return size == 0; // return rear == -1;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        rear++;
        arr[rear] = value;
        size++;
    }
   
    // Limitation: Once elements are dequeued, space at the start is wasted.
    // Queue will be used Once. As no change in rear index.
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        front++; // Option: Don't change this, instead run a loop to shift all elements.
        size--;
    }
//-----------------------------------------------------------------------
    // Another Version of Dequeue - Limitation: costly data shift operation
   /* void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        // Loop to shift all elements forward.
        for (int i = 0; i < rear; i++) {
            arr[i] = arr[i + 1];
        }
        size--; rear--;
    }*/

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }
//-------------------------------------------------------------
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(10); q.enqueue(20);
    q.enqueue(30);  q.enqueue(40);
    q.enqueue(50);
    q.display();

    q.dequeue();  q.dequeue();
   // q.dequeue(); //q.dequeue();  q.dequeue();
    q.display();
    
    q.enqueue(6);
    q.display();
    
    return 0;
}
