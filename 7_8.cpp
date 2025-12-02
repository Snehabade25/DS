// Employee Record Search & Sort by emp-id using BST
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int id;
    string name;
    Node *left, *right;

    Node(int i, string n){ id=i; name=n; left=right=NULL; }
};

Node* insert(Node* root, int id, string name){
    if(!root) return new Node(id, name);
    if(id < root->id) root->left = insert(root->left, id, name);
    else root->right = insert(root->right, id, name);
    return root;
}

void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout << root->id << " - " << root->name << endl;
    inorder(root->right);
}

bool search(Node* root, int id){
    if(!root) return false;
    if(root->id==id) return true;
    if(id < root->id) return search(root->left, id);
    return search(root->right, id);
}

int main(){
    Node* root=NULL;
    int n, id;
    string name;
    
    cout<<"Enter number of employees: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter ID and Name: ";
        cin>>id>>name;
        root = insert(root,id,name);
    }
    
    cout<<"\nSorted Employees (Inorder):\n";
    inorder(root);
    
    cout<<"\nSearch employee by ID: ";
    cin>>id;
    cout<<(search(root,id)?"Found":"Not Found")<<endl;
}
