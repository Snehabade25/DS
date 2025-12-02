// Write a Program to create a Binary Tree and perform the following Recursive operations on it. 
// a. Inorder Traversal b. Preorder Traversal c. Display Number of Leaf Nodes d. Mirror Image
// | Factor           | Best Case    | Worst Case |
// | ---------------- | ------------ | ---------- |
// | Time Complexity  | **O(n)**     | **O(n)**   |
// | Space Complexity | **O(log n)** | **O(n)**   |

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

class BinaryTree {
private:
    Node* root;

    Node* insertRec(Node* node, int value) {
        if (node == NULL)
            return new Node(value);

        char choice;
        cout << "Insert " << value << " to left (L) or right (R) of " << node->data << "? ";
        cin >> choice;

        if (choice == 'L' || choice == 'l')
            node->left = insertRec(node->left, value);
        else
            node->right = insertRec(node->right, value);

        return node;
    }

    void inorderRec(Node* node) {
        if (node == NULL)
            return;

        inorderRec(node->left);
        cout << node->data << " ";
        inorderRec(node->right);
    }

    void preorderRec(Node* node) {
        if (node == NULL)
            return;

        cout << node->data << " ";
        preorderRec(node->left);
        preorderRec(node->right);
    }

    int leafCountRec(Node* node) {
        if (node == NULL)
            return 0;

        if (node->left == NULL && node->right == NULL)
            return 1;

        return leafCountRec(node->left) + leafCountRec(node->right);
    }

    void mirrorRec(Node* node) {
        if (node == NULL)
            return;

        mirrorRec(node->left);
        mirrorRec(node->right);

        Node* temp = node->left;
        node->left = node->right;
        node->right = temp;
    }

public:
    BinaryTree() {
        root = NULL;
    }

    void insert(int value) {
        root = insertRec(root, value);
    }

    void inorder() {
        cout << "Inorder Traversal: ";
        inorderRec(root);
        cout << endl;
    }

    void preorder() {
        cout << "Preorder Traversal: ";
        preorderRec(root);
        cout << endl;
    }

    void leafCount() {
        cout << "Number of Leaf Nodes: " << leafCountRec(root) << endl;
    }

    void mirror() {
        mirrorRec(root);
        cout << "Tree converted to mirror image.\n";
    }
};

int main() {
    BinaryTree tree;
    int choice, value;

    while (true) {
        cout << "\n--- Binary Tree Operations ---\n";
        cout << "1. Insert Node\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Display Number of Leaf Nodes\n";
        cout << "5. Mirror Image\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            tree.insert(value);
        }
        else if (choice == 2) {
            tree.inorder();
        }
        else if (choice == 3) {
            tree.preorder();
        }
        else if (choice == 4) {
            tree.leafCount();
        }
        else if (choice == 5) {
            tree.mirror();
        }
        else if (choice == 6) {
            cout << "Exiting...\n";
            break;
        }
        else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
