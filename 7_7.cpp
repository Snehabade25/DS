// BST Operations Menu – Insert, Delete, Find, Show
#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node *left, *right;
    Node(int k){ key=k; left=right=NULL; }
};

Node* insert(Node* root, int k){
    if(!root) return new Node(k);
    if(k < root->key) root->left = insert(root->left, k);
    else root->right = insert(root->right, k);
    return root;
}

Node* findMin(Node* root){
    while(root->left) root=root->left;
    return root;
}

Node* deleteNode(Node* root, int k){
    if(!root) return root;
    if(k < root->key) root->left = deleteNode(root->left, k);
    else if(k > root->key) root->right = deleteNode(root->right, k);
    else {
        if(!root->left) return root->right;
        if(!root->right) return root->left;
        Node* t = findMin(root->right);
        root->key = t->key;
        root->right = deleteNode(root->right, t->key);
    }
    return root;
}

bool search(Node* root, int k){
    if(!root) return false;
    if(root->key == k) return true;
    if(k < root->key) return search(root->left, k);
    return search(root->right, k);
}

void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

int main(){
    Node* root=NULL;
    int ch, k;
    do{
        cout << "\n1.Insert 2.Delete 3.Find 4.Show 5.Exit\nEnter choice: ";
        cin >> ch;
        switch(ch){
            case 1: cout<<"Enter key: "; cin>>k; root=insert(root,k); break;
            case 2: cout<<"Delete key: "; cin>>k; root=deleteNode(root,k); break;
            case 3: cout<<"Find key: "; cin>>k;
                    cout<< (search(root,k) ? "Found" : "Not Found") << endl;
                    break;
            case 4: inorder(root); cout<<endl; break;
        }
    } while(ch != 5);
}
