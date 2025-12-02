// WAP to perform addition of two polynomials using singly linked list.
#include <iostream>
using namespace std;

struct Node {
    int coeff;
    int pow;
    Node* next;
};

// Insert term in decreasing order of power
Node* insert(Node* head, int c, int p) {
    Node* temp = new Node();
    temp->coeff = c;
    temp->pow = p;
    temp->next = NULL;

    // If list is empty or term should be first
    if (!head || p > head->pow) {
        temp->next = head;
        return temp;
    }

    Node* curr = head;
    while (curr->next && curr->next->pow >= p)
        curr = curr->next;

    temp->next = curr->next;
    curr->next = temp;

    return head;
}

// Display polynomial
void display(Node* head) {
    if (!head) {
        cout << "0";
        return;
    }
    Node* t = head;
    while (t) {
        cout << t->coeff << "x^" << t->pow;
        if (t->next) cout << " + ";
        t = t->next;
    }
    cout << endl;
}

// Add two polynomials
Node* addPoly(Node* poly1, Node* poly2) {
    Node* result = NULL;

    while (poly1 && poly2) {
        if (poly1->pow == poly2->pow) {
            int sum = poly1->coeff + poly2->coeff;
            if (sum != 0) 
                result = insert(result, sum, poly1->pow);

            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if (poly1->pow > poly2->pow) {
            result = insert(result, poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        }
        else {
            result = insert(result, poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        }
    }

    // Add remaining terms
    while (poly1) {
        result = insert(result, poly1->coeff, poly1->pow);
        poly1 = poly1->next;
    }
    while (poly2) {
        result = insert(result, poly2->coeff, poly2->pow);
        poly2 = poly2->next;
    }

    return result;
}

int main() {
    Node *poly1 = NULL, *poly2 = NULL;

    int n, c, p;

    // Polynomial 1 input
    cout << "Enter number of terms in Polynomial 1: ";
    cin >> n;
    cout << "Enter coefficient and power:\n";
    for (int i = 0; i < n; i++) {
        cin >> c >> p;
        poly1 = insert(poly1, c, p);
    }

    // Polynomial 2 input
    cout << "\nEnter number of terms in Polynomial 2: ";
    cin >> n;
    cout << "Enter coefficient and power:\n";
    for (int i = 0; i < n; i++) {
        cin >> c >> p;
        poly2 = insert(poly2, c, p);
    }

    cout << "\nPolynomial 1: ";
    display(poly1);

    cout << "Polynomial 2: ";
    display(poly2);

    Node* result = addPoly(poly1, poly2);

    cout << "\nResult (Polynomial 1 + Polynomial 2): ";
    display(result);

    return 0;
}
