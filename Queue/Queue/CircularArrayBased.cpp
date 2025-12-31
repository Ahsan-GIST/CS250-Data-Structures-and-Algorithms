#include <iostream>
using namespace std;

class CircularQueue {
private:
    int arr[5];
    int front, rear;
    int count;
    int capacity;

public:
    CircularQueue() {
        front = 0;
        rear = -1;
        count = 0;
        capacity = 5;
    }

    bool isFull() {
        return count == capacity;
    }

    bool isEmpty() {
        return count == 0;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        count++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        front = (front + 1) % capacity;
        count--;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        for (int i = 0; i < count; i++)
            cout << arr[(front + i) % capacity] << " ";
        cout << endl;
    }
};

/*int main() {
    CircularQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();

    q.dequeue();
    q.enqueue(60);
    q.display();

    return 0;
}*/
