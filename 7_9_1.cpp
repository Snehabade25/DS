// Product Inventory System Using BST (Insert, Display, List Expired)
#include <iostream>
using namespace std;

class Product {
public:
    int code;
    string name, dateRec, dateExp;
    int qty;
    float price;
    Product *left, *right;

    Product(int c,string n,float p,int q,string r,string e){
        code=c; name=n; price=p; qty=q; dateRec=r; dateExp=e;
        left=right=NULL;
    }
};

Product* insert(Product* root, Product* p){
    if (!root) return p;
    if (p->name < root->name) root->left = insert(root->left, p);
    else root->right = insert(root->right, p);
    return root;
}

void inorder(Product* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->name<<" ("<<root->code<<")"<<endl;
    inorder(root->right);
}

void listExpired(Product* root){
    if(!root) return;
    cout<<root->name<<" Expired on: "<<root->dateExp<<endl;
    listExpired(root->left);
    listExpired(root->right);
}

int main(){
    Product* root=NULL;

    root = insert(root,new Product(101,"Milk",50,20,"10/02/25","18/02/25"));
    root = insert(root,new Product(102,"Bread",25,10,"14/02/25","15/02/25"));
    root = insert(root,new Product(103,"Butter",120,5,"11/02/25","19/02/25"));

    cout<<"\nInventory (Inorder Sorted):\n";
    inorder(root);

    cout<<"\nExpired Items (Preorder):\n";
    listExpired(root);
}
