#include <iostream>
using namespace std;

// Node structure for priority queue
struct Node {
    int data;
    int priority;  //new thing as compared to Queue
    Node* next;

    Node(int d, int p) {
        data = d;
        priority = p;
        next = nullptr;
    }
};

// Priority Queue Class (Max-Priority Queue)
class PriorityQueue {
private:
    Node* front;  // highest priority node is always at front
    // we don't need rear pointer as enqueue/insert location will depend on priority

public:
    PriorityQueue() {
        front = nullptr;
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == nullptr);
    }

    // Insert a new node based on its priority
    void enqueue(int value, int priority) {
        Node* newNode = new Node(value, priority);

        // Case 1: Queue is empty OR new node has higher priority than front
        if (isEmpty() || priority > front->priority) {
            newNode->next = front;
            front = newNode;
        }
        else {
            // Traverse and find proper position
            Node* temp = front;
            while (temp->next != nullptr && temp->next->priority >= priority)
                temp = temp->next;

            // Insert new node in middle or end
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Remove the node with highest priority
    void dequeue() {
        if (isEmpty()) {
            cout << "Priority Queue Underflow!" << endl;
            return;
        }

        Node* temp = front;
        front = front->next;
        cout << "Removed: " << temp->data << " (priority " << temp->priority << ")" << endl;
        delete temp;
    }

    // Return the highest-priority element
    int peek() {
        if (isEmpty()) {
            cout << "Priority Queue is empty!" << endl;
            return -1;
        }
        return front->data;
    }

    // Display full priority queue
    void display() {
        if (isEmpty()) {
            cout << "Priority Queue is empty!" << endl;
            return;
        }

        Node* temp = front;
        cout << "Priority Queue (value:priority) ? ";
        while (temp != nullptr) {
            cout << temp->data << ":" << temp->priority << "  ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// ========================= MAIN FUNCTION ==========================
int main() {
    PriorityQueue pq;

    cout << "Inserting elements...\n";
    pq.enqueue(10, 2);
    pq.enqueue(50, 5);
    pq.enqueue(30, 3);
    pq.enqueue(70, 1);
    pq.enqueue(90, 4);

    pq.display();

    cout << "\nPeek highest priority: " << pq.peek() << endl;

    cout << "\nDequeuing elements:\n";
    pq.dequeue();
    pq.display();

    pq.dequeue();
    pq.display();

    return 0;
}
