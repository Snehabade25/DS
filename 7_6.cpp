// Assign Roll Numbers Using a Binary Search Tree (Topper gets Roll No. 1)

#include <iostream>
using namespace std;

class Node {
public:
    int marks;
    Node* left;
    Node* right;
    Node(int m) { marks = m; left = right = NULL; }
};

Node* insertBST(Node* root, int m) {
    if (!root) return new Node(m);
    if (m > root->marks) root->right = insertBST(root->right, m);
    else root->left = insertBST(root->left, m);
    return root;
}

void assignRollNos(Node* root, int &roll) {
    if (!root) return;
    assignRollNos(root->right, roll);   // Highest marks first
    cout << "Roll No. " << roll++ << " -> Marks: " << root->marks << endl;
    assignRollNos(root->left, roll);
}

int main() {
    Node* root = NULL;
    int n, m;
    cout << "Enter number of students: ";
    cin >> n;

    cout << "Enter marks:\n";
    for (int i = 0; i < n; i++) {
        cin >> m;
        root = insertBST(root, m);
    }

    int roll = 1;
    cout << "\nAssigned Roll Numbers (Topper = Roll 1):\n";
    assignRollNos(root, roll);
}
