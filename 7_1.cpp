// Write a program to perform Binary Search Tree (BST) operations (Create, Insert, Delete, Levelwise display )
// Time Complexity
// Insert: O(h) → avg O(log n), worst O(n)
// Delete: O(h) → avg O(log n), worst O(n)
// Level-wise display: O(n)

// Space Complexity
// Tree storage: O(n)
// Recursion (insert/delete): O(h) → O(log n) avg, O(n) worst
// Queue (your fixed array): O(1) extra

#include <iostream>
using namespace std;

// ----------------- Node Definition -----------------
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// ----------------- Simple Queue for Level Order -----------------
class Queue {
private:
    Node* arr[100];
    int front, rear;

public:
    Queue() {
        front = 0;
        rear = 0;
    }

    bool isEmpty() {
        return front == rear;
    }

    bool isFull() {
        return rear == 100;
    }

    void enqueue(Node* x) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue.\n";
            return;
        }

        // Expanded form of arr[rear++] = x;
        arr[rear] = x;
        rear = rear + 1;
    }

    Node* dequeue() {
        if (isEmpty()) {
            return NULL;
        }

        // Expanded form of return arr[front++];
        Node* value = arr[front];
        front = front + 1;
        return value;
    }
};

// ----------------- BST Class -----------------
class BST {
private:
    Node* root;

    // Helper for insertion
    Node* insertRec(Node* node, int key) {
        if (node == NULL) {
            node = new Node(key);
            return node;
        }
        if (key < node->data)
            node->left = insertRec(node->left, key);
        else if (key > node->data)
            node->right = insertRec(node->right, key);
        else
            cout << "Duplicate key " << key << " not inserted.\n";
        return node;
    }

    // Find minimum node in a subtree (used in delete)
    Node* findMin(Node* node) {
        while (node != NULL && node->left != NULL)
            node = node->left;
        return node;
    }

    // Helper for deletion
    Node* deleteRec(Node* node, int key) {
        if (node == NULL) {
            cout << "Key " << key << " not found in tree.\n";
            return node;
        }

        if (key < node->data) {
            node->left = deleteRec(node->left, key);
        } 
        else if (key > node->data) {
            node->right = deleteRec(node->right, key);
        } 
        else { 
            // Node found

            // Case 1: No child
            if (node->left == NULL && node->right == NULL) {
                delete node;
                return NULL;
            }
            // Case 2: One child (right only)
            else if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            // Case 2: One child (left only)
            else if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            // Case 3: Two children
            else {
                Node* succ = findMin(node->right);
                node->data = succ->data;
                node->right = deleteRec(node->right, succ->data);
            }
        }
        return node;
    }

public:
    BST() {
        root = NULL;
    }

    void insert(int key) {
        root = insertRec(root, key);
    }

    void deleteKey(int key) {
        root = deleteRec(root, key);
    }

    // Level-wise display (Level Order Traversal)
    void levelOrderDisplay() {
        if (root == NULL) {
            cout << "Tree is empty.\n";
            return;
        }

        Queue q;
        q.enqueue(root);

        cout << "Level-wise (Level Order) Traversal: ";

        while (!q.isEmpty()) {
            Node* current = q.dequeue();
            cout << current->data << " ";

            if (current->left != NULL)
                q.enqueue(current->left);
            if (current->right != NULL)
                q.enqueue(current->right);
        }
        cout << endl;
    }
};

// ----------------- MAIN FUNCTION -----------------
int main() {
    BST tree;
    int choice, value, n, key;

    while (true) {
        cout << "\n--- Binary Search Tree Operations ---\n";
        cout << "1. Create BST (Insert multiple nodes)\n";
        cout << "2. Insert a node\n";
        cout << "3. Delete a node\n";
        cout << "4. Level-wise display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "How many nodes do you want to insert? ";
            cin >> n;
            cout << "Enter " << n << " values:\n";
            for (int i = 0; i < n; i++) {
                cin >> value;
                tree.insert(value);
            }
            break;

        case 2:
            cout << "Enter value to insert: ";
            cin >> value;
            tree.insert(value);
            break;

        case 3:
            cout << "Enter value to delete: ";
            cin >> key;
            tree.deleteKey(key);
            break;

        case 4:
            tree.levelOrderDisplay();
            break;

        case 5:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
