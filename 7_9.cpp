// Complete Product Inventory BST Program with Delete by Code
#include <iostream>
#include <string>
using namespace std;

class Product {
public:
    int code;
    string name;
    float price;
    int qty;
    string dateRec;
    string dateExp;
    Product* left;
    Product* right;

    Product(int c, string n, float p, int q, string r, string e) {
        code = c;
        name = n;
        price = p;
        qty = q;
        dateRec = r;
        dateExp = e;
        left = right = NULL;
    }
};

// Insert product into BST organized by code
Product* insert(Product* root, Product* p) {
    if (!root) return p;
    if (p->code < root->code) root->left = insert(root->left, p);
    else root->right = insert(root->right, p);
    return root;
}

// Find minimum node (used in delete)
Product* findMin(Product* root) {
    while (root->left) root = root->left;
    return root;
}

// Delete product by code
Product* deleteByCode(Product* root, int c) {
    if (!root) return root;
    if (c < root->code) root->left = deleteByCode(root->left, c);
    else if (c > root->code) root->right = deleteByCode(root->right, c);
    else {
        // Node with 0 or 1 child
        if (!root->left) return root->right;
        if (!root->right) return root->left;
        // Node with 2 children
        Product* t = findMin(root->right);
        root->code = t->code;
        root->name = t->name;
        root->price = t->price;
        root->qty = t->qty;
        root->dateRec = t->dateRec;
        root->dateExp = t->dateExp;
        root->right = deleteByCode(root->right, t->code);
    }
    return root;
}

// Inorder display of BST (sorted by code)
void inorder(Product* root) {
    if (!root) return;
    inorder(root->left);
    cout << "Code: " << root->code << ", Name: " << root->name << ", Price: " << root->price
         << ", Qty: " << root->qty << ", Received: " << root->dateRec
         << ", Exp: " << root->dateExp << endl;
    inorder(root->right);
}

int main() {
    Product* root = NULL;

    // Sample products
    root = insert(root, new Product(101, "Milk", 50, 20, "10/02/25", "18/02/25"));
    root = insert(root, new Product(102, "Bread", 25, 10, "14/02/25", "15/02/25"));
    root = insert(root, new Product(103, "Butter", 120, 5, "11/02/25", "19/02/25"));
    root = insert(root, new Product(104, "Cheese", 200, 8, "12/02/25", "25/02/25"));

    cout << "Inventory (Inorder by code):\n";
    inorder(root);

    cout << "\nDeleting product with code 102 (Bread)...\n";
    root = deleteByCode(root, 102);

    cout << "\nInventory after deletion:\n";
    inorder(root);

    return 0;
}

