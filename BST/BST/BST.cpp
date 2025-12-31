#include <iostream>
using namespace std;

// =========================
//   Node Structure
// =========================
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// =========================
//   Binary Search Tree Class
// =========================
class BST {
private:
    Node* root;

   // Node* getroot() { return root; }
    // Helper function for insertion
    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);
        else
            cout << "Duplicate value ignored: " << value << endl;

        return node;
    }

    // Helper for inorder traversal
    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    // Helper for preorder traversal
    void preorder(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    // Helper for postorder traversal
    void postorder(Node* node) {
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }


    
    // Find minimum node (used in delete)
    Node* findMin(Node* node) {
        while (node && node->left != nullptr)
            node = node->left;
        return node;
    }

    // Helper function for deletion
    Node* deleteNode(Node* node, int value) {
        if (node == nullptr)
            return nullptr;

        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        }
        else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        }
        else {
            // Node found – now handle 3 cases

            // Case 1: No child
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }

            // Case 2: One child
            else if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Case 3: Two children
            Node* temp = findMin(node->right);    // inorder successor
            node->data = temp->data;              // replace data
            node->right = deleteNode(node->right, temp->data);
        }

        return node;
    }

public:
    // Constructor
    BST() {
        root = nullptr;
    }

    // Non-recursive search function for BST
    Node* searchnode(int key) {
        Node* current = root;        // Start from the root

        while (current != nullptr) {
            if (key == current->data) {
                return current;      // Key found
            }
            else if (key < current->data) {
                current = current->left;   // Move left
            }
            else {
                current = current->right;  // Move right
            }
        }

        return nullptr;  // Key not found in the BST
    }

    // Public insert function
    void insert(int value) {
        root = insert(root, value);
    }

    // Public delete function
    void remove(int value) {
        root = deleteNode(root, value);
    }

    // Traversals
    void inorder() {
        inorder(root);
        cout << endl;
    }

    void preorder() {
        preorder(root);
        cout << endl;
    }

    void postorder() {
        postorder(root);
        cout << endl;
    }
    //Node* getroot() { return root; }
};

// =========================
//              MAIN
// =========================
int main() {

    BST tree;
    int values[] = { 14, 15, 4, 9, 7, 18, 3, 5, 16, 4, 20, 17, 9, 14, 5 };
    int n = sizeof(values) / sizeof(values[0]);

    cout << "Inserting values into BST..." << endl;
    for (int i = 0; i < n; i++) {
        tree.insert(values[i]);
    }

    cout << "\nInorder Traversal (sorted): ";
    tree.inorder();

    cout << "Preorder Traversal: ";
    tree.preorder();

    cout << "Postorder Traversal: ";
    tree.postorder();

    // Demonstrate Search
    cout << "\nSearch and return address of Node/key: 3" << tree.searchnode(3) << endl;

    // Demonstrate deletion
    cout << "\nDeleting 14..." << endl;
    tree.remove(14);

    cout << "Inorder after deletion: ";
    tree.inorder();

    return 0;
}
