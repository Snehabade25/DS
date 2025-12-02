// Write a C++ program to implement a Set using a Generalized Linked List (GLL).     For example:
 // Let S = { p, q, {r, s, t, {}, {u, v}, w, x, {y, z}, a1, b1} }
// Store this structure using a Generalized Linked List and display the elements in correct set notation format.C++ code 

#include <iostream>
using namespace std;

class GLL {
public:
    string data;      // Data for atomic element
    GLL* down;        // Pointer to sublist (child)
    GLL* next;        // Next element in list

    GLL(string d="") { 
        data = d;
        down = NULL;
        next = NULL;
    }
};

// Recursive function to print GLL as a set
void display(GLL* head) {
    if (!head) return;
    cout << "{";

    GLL* temp = head;
    while (temp) {
        if (temp->down) {
            display(temp->down);
        } else {
            cout << temp->data;
        }

        if (temp->next)
            cout << ", ";
        temp = temp->next;
    }
    cout << "}";
}

int main() {
    // Example Set: S = { p, q, {r, s, t, {}, {u, v}, w, x, {y, z}, a1, b1} }

    GLL *p = new GLL("p");
    GLL *q = new GLL("q");

    // Subset creation
    GLL *r = new GLL("r");
    GLL *s = new GLL("s");
    GLL *t = new GLL("t");
    GLL *emptySet = new GLL();          // {}
    emptySet->down = NULL;

    GLL *u = new GLL("u");
    GLL *v = new GLL("v");
    GLL *uvSet = new GLL();
    uvSet->down = u;
    u->next = v;

    GLL *w = new GLL("w");
    GLL *x = new GLL("x");

    GLL *y = new GLL("y");
    GLL *z = new GLL("z");
    GLL *yzSet = new GLL();
    yzSet->down = y;
    y->next = z;

    GLL *a1 = new GLL("a1");
    GLL *b1 = new GLL("b1");

    // Linking subset elements
    r->next = s;
    s->next = t;
    t->next = emptySet;
    emptySet->next = uvSet;
    uvSet->next = w;
    w->next = x;
    x->next = yzSet;
    yzSet->next = a1;
    a1->next = b1;

    // Main set creation
    GLL* mainSet = p;
    p->next = q;
    q->next = new GLL();
    q->next->down = r;   // attach sublist

    cout << "Generalized Linked List Representation of Set:\n";
    display(mainSet);

    return 0;
}



