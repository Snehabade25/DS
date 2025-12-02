// Write a Program to create a Binary Search Tree and Find Minimum/Maximum in BST
// | Case                    | Time Complexity | Space Complexity |
// | ----------------------- | --------------- | ---------------- |
// | **Best (balanced BST)** | **O(n)**        | **O(log n)**     |
// | **Worst (skewed BST)**  | **O(n)**        | **O(n)**         |

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BST {
private:
    Node* root;

    Node* insertRec(Node* node, int key) {
        if (node == NULL) {
            return new Node(key);
        }

        if (key < node->data)
            node->left = insertRec(node->left, key);
        else if (key > node->data)
            node->right = insertRec(node->right, key);
        else
            cout << "Duplicate value, not inserted.\n";

        return node;
    }

    void inorderRec(Node* node) {
        if (node == NULL)
            return;

        inorderRec(node->left);
        cout << node->data << " ";
        inorderRec(node->right);
    }

public:
    BST() {
        root = NULL;
    }

    void insert(int key) {
        root = insertRec(root, key);
    }

    int findMin() {
        if (root == NULL) {
            cout << "Tree is empty.\n";
            return -1;
        }

        Node* temp = root;
        while (temp->left != NULL)
            temp = temp->left;

        return temp->data;
    }

    int findMax() {
        if (root == NULL) {
            cout << "Tree is empty.\n";
            return -1;
        }

        Node* temp = root;
        while (temp->right != NULL)
            temp = temp->right;

        return temp->data;
    }

    void inorderDisplay() {
        if (root == NULL) {
            cout << "Tree is empty.\n";
            return;
        }
        cout << "Inorder Traversal: ";
        inorderRec(root);
        cout << endl;
    }
};

int main() {
    BST tree;
    int choice, value, n;

    while (true) {
        cout << "\n--- Binary Search Tree Operations ---\n";
        cout << "1. Insert nodes\n";
        cout << "2. Find Minimum\n";
        cout << "3. Find Maximum\n";
        cout << "4. Inorder Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "How many nodes? ";
            cin >> n;
            cout << "Enter values:\n";
            for (int i = 0; i < n; i++) {
                cin >> value;
                tree.insert(value);
            }
        }
        else if (choice == 2) {
            cout << "Minimum value in BST: " << tree.findMin() << endl;
        }
        else if (choice == 3) {
            cout << "Maximum value in BST: " << tree.findMax() << endl;
        }
        else if (choice == 4) {
            tree.inorderDisplay();
        }
        else if (choice == 5) {
            cout << "Exiting...\n";
            break;
        }
        else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
