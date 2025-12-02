// Write a program to perform Binary Search Tree (BST) operations
// (Count the total number of nodes, Compute the height of the BST, Mirror Image ).
// | Case                            | Time Complexity | Space Complexity |
// | ------------------------------- | --------------- | ---------------- |
// | **Best Case (Balanced BST)**    | **O(n)**        | **O(log n)**     |
// | **Worst Case (Unbalanced BST)** | **O(n)**        | **O(n)**         |

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
        left = NULL;
        right = NULL;
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

        if (key < node->data) {
            node->left = insertRec(node->left, key);
        } else if (key > node->data) {
            node->right = insertRec(node->right, key);
        } else {
            cout << "Duplicate key " << key << " not inserted.\n";
        }
        return node;
    }

    // Helper to count nodes
    int countNodesRec(Node* node) {
        if (node == NULL) {
            return 0;
        }
        int leftCount = countNodesRec(node->left);
        int rightCount = countNodesRec(node->right);
        return leftCount + rightCount + 1;
    }

    // Helper to compute height
    int heightRec(Node* node) {
        if (node == NULL) {
            return 0;
        }
        int leftHeight = heightRec(node->left);
        int rightHeight = heightRec(node->right);

        if (leftHeight > rightHeight) {
            return leftHeight + 1;
        } else {
            return rightHeight + 1;
        }
    }

    // Helper to mirror the tree
    void mirrorRec(Node* node) {
        if (node == NULL) {
            return;
        }

        // Mirror subtrees
        mirrorRec(node->left);
        mirrorRec(node->right);

        // Swap left and right
        Node* temp = node->left;
        node->left = node->right;
        node->right = temp;
    }

    // Helper for inorder traversal
    void inorderRec(Node* node) {
        if (node == NULL) {
            return;
        }

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

    int countNodes() {
        return countNodesRec(root);
    }

    int height() {
        return heightRec(root);
    }

    void mirror() {
        mirrorRec(root);
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

// ----------------- MAIN FUNCTION -----------------
int main() {
    BST tree;
    int choice, value, n;

    while (true) {
        cout << "\n--- Binary Search Tree Operations ---\n";
        cout << "1. Create/Insert nodes\n";
        cout << "2. Count total number of nodes\n";
        cout << "3. Compute height of BST\n";
        cout << "4. Mirror the BST\n";
        cout << "5. Inorder display\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "How many nodes do you want to insert? ";
            cin >> n;
            cout << "Enter " << n << " values:\n";
            for (int i = 0; i < n; i++) {
                cin >> value;
                tree.insert(value);
            }
        } else if (choice == 2) {
            int total = tree.countNodes();
            cout << "Total number of nodes: " << total << endl;
        } else if (choice == 3) {
            int h = tree.height();
            cout << "Height of BST: " << h << endl;
        } else if (choice == 4) {
            tree.mirror();
            cout << "BST has been converted to its mirror image.\n";
        } else if (choice == 5) {
            tree.inorderDisplay();
        } else if (choice == 6) {
            cout << "Exiting...\n";
            return 0;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
