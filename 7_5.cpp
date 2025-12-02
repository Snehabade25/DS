// Write a Program to create a Binary Tree and perform following Non recursive operations on it
// . a. Inorder Traversal b. Preorder Traversal c. Display Number of Leaf Nodes d. Mirror Image
// | Factor                       | Complexity                                                |
// | ---------------------------- | --------------------------------------------------------- |
// | **Overall Time Complexity**  | **O(n)**                                                  |
// | **Overall Space Complexity** | **O(h)** → **O(log n)** (best/balanced), **O(n)** (worst) |

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

// ----------- Simple Stack Class (No STL) -------------
class Stack {
public:
    Node* arr[50];
    int top;

    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(Node* x) {
        top++;
        arr[top] = x;
    }

    Node* pop() {
        Node* temp = arr[top];
        top--;
        return temp;
    }

    Node* peek() {
        return arr[top];
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

public:
    BinaryTree() {
        root = NULL;
    }

    void insert(int value) {
        root = insertRec(root, value);
    }

    // ---------- Non-Recursive Inorder ----------
    void inorder() {
        cout << "Inorder Traversal: ";
        Stack s;
        Node* current = root;

        while (current != NULL || !s.isEmpty()) {
            while (current != NULL) {
                s.push(current);
                current = current->left;
            }

            current = s.pop();
            cout << current->data << " ";
            current = current->right;
        }
        cout << endl;
    }

    // ---------- Non-Recursive Preorder ----------
    void preorder() {
        cout << "Preorder Traversal: ";
        if (root == NULL) return;

        Stack s;
        s.push(root);

        while (!s.isEmpty()) {
            Node* node = s.pop();
            cout << node->data << " ";

            if (node->left != NULL)
                s.push(node->left);

            if (node->right != NULL)
                s.push(node->right);

            
        }
        cout << endl;
    }

    // ---------- Non-Recursive Leaf Count ----------
    void leafCount() {
        if (root == NULL) {
            cout << "Number of Leaf Nodes: 0\n";
            return;
        }

        Stack s;
        s.push(root);
        int count = 0;

        while (!s.isEmpty()) {
            Node* node = s.pop();

            if (node->left == NULL && node->right == NULL)
                count++;

            if (node->right != NULL)
                s.push(node->right);

            if (node->left != NULL)
                s.push(node->left);
        }

        cout << "Number of Leaf Nodes: " << count << endl;
    }

    // ---------- Non-Recursive Mirror Image ----------
    void mirror() {
        if (root == NULL) return;

        Stack s;
        s.push(root);

        while (!s.isEmpty()) {
            Node* node = s.pop();

            Node* temp = node->left;
            node->left = node->right;
            node->right = temp;

            if (node->left != NULL)
                s.push(node->left);

            if (node->right != NULL)
                s.push(node->right);
        }

        cout << "Tree converted to mirror image.\n";
    }
};

// ------------------ MAIN ------------------
int main() {
    BinaryTree tree;
    int choice, value;

    while (true) {
        cout << "\n--- Binary Tree Operations ---\n";
        cout << "1. Insert Node\n";
        cout << "2. Inorder Traversal (Non-Recursive)\n";
        cout << "3. Preorder Traversal (Non-Recursive)\n";
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
