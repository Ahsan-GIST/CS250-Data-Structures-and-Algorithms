#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node *next;
    //Node* prev; // for DLL

    Node(int val) {
        data = val;
        next = nullptr;
     //   next = NULL;
    }
};

/* Node* = CreateNode(int val = 0) {
Node* temp;
temp = new node;
temp->data = val; temp->next = nullptr;
return temp;
}*/

// Singly Linked List class
class SinglyLinkedList {
private:
    Node* head; //*start

public:
    // Constructor
    SinglyLinkedList() {
        head = nullptr;
    }

    // Insert at head
    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert at tail
    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head; //*traverse
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Delete node by value
    void deleteValue(int value) {
        if (head == nullptr) return;

        // If head needs to be deleted
        if (head->data == value) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Value " << value << " not found!\n";
            return;
        }

        Node* toDelete = temp->next;
        temp->next = temp->next->next; // toDelete->next;
        delete toDelete;
    }

    // Modify a value (first occurrence)
    void modify(int oldValue, int newValue) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == oldValue) {
                temp->data = newValue;
                return;
            }
            temp = temp->next;
        }
        cout << "Value " << oldValue << " not found!\n";
    }

    // Display the list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Destructor (free memory)
    ~SinglyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

// ----------------- Example Usage -----------------
int main() {
    SinglyLinkedList list;

    list.insertAtHead(10);
    list.insertAtHead(5);
    list.insertAtTail(20);
    list.insertAtTail(25);

    cout << "Initial List: ";
    list.display();

    list.deleteValue(10);
    cout << "After deleting 10: ";
    list.display();

    list.modify(25, 30);
    cout << "After modifying 25 -> 30: ";
    list.display();

    return 0;
}
