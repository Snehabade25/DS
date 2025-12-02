// Write a C++ program to store a binary number using a doubly linked list. Implement the following functions:
// a) Calculate and display the 1’s complement and 2’s complement of the stored binary number.
// b) Perform addition of two binary numbers represented using doubly linked lists and display the result.
#include <iostream>
using namespace std;

struct Node {
    int bit;
    Node* prev;
    Node* next;
};

class BinaryDLL {
public:
    Node* head;
    Node* tail;

    BinaryDLL() {
        head = tail = NULL;
    }

    // Insert a bit (0 or 1) at the end
    void insert(int b) {
        Node* n = new Node();
        n->bit = b;
        n->prev = n->next = NULL;

        if (!head) {
            head = tail = n;
        } else {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }

    // Display binary number
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->bit;
            temp = temp->next;
        }
        cout << endl;
    }

    // Create a copy of the current list
    BinaryDLL copyList() {
        BinaryDLL c;
        Node* temp = head;
        while (temp) {
            c.insert(temp->bit);
            temp = temp->next;
        }
        return c;
    }

    // (a) 1's Complement
    BinaryDLL onesComplement() {
        BinaryDLL c = copyList();
        Node* temp = c.head;
        while (temp) {
            temp->bit = (temp->bit == 0) ? 1 : 0;
            temp = temp->next;
        }
        return c;
    }

    // (a) 2's Complement = 1's complement + 1
    BinaryDLL twosComplement() {
        BinaryDLL c = onesComplement();

        Node* temp = c.tail;
        int carry = 1;

        while (temp && carry) {
            int sum = temp->bit + carry;
            temp->bit = sum % 2;
            carry = sum / 2;
            temp = temp->prev;
        }

        if (carry == 1) {
            c.insertAtFront(1);
        }
        return c;
    }

    // Insert a bit at the front (used for carry extension)
    void insertAtFront(int b) {
        Node* n = new Node();
        n->bit = b;
        n->prev = NULL;
        n->next = head;

        if (head)
            head->prev = n;
        else
            tail = n;

        head = n;
    }

    // (b) Addition of two binary numbers
    static BinaryDLL add(BinaryDLL A, BinaryDLL B) {
        BinaryDLL result;
        Node* a = A.tail;
        Node* b = B.tail;
        int carry = 0;

        while (a || b || carry) {
            int x = (a ? a->bit : 0);
            int y = (b ? b->bit : 0);

            int sum = x + y + carry;
            result.insertAtFront(sum % 2);
            carry = sum / 2;

            if (a) a = a->prev;
            if (b) b = b->prev;
        }

        return result;
    }
};

int main() {
    BinaryDLL bin1, bin2;

    int n, bit;

    cout << "Enter number of bits for binary number 1: ";
    cin >> n;
    cout << "Enter bits:\n";
    for (int i = 0; i < n; i++) {
        cin >> bit;
        bin1.insert(bit);
    }

    cout << "\nEnter number of bits for binary number 2: ";
    cin >> n;
    cout << "Enter bits:\n";
    for (int i = 0; i < n; i++) {
        cin >> bit;
        bin2.insert(bit);
    }

    cout << "\nBinary 1: ";
    bin1.display();

    cout << "1's Complement of Binary 1: ";
    bin1.onesComplement().display();

    cout << "2's Complement of Binary 1: ";
    bin1.twosComplement().display();

    cout << "\nBinary 2: ";
    bin2.display();

    cout << "\nAddition Result: ";
    BinaryDLL::add(bin1, bin2).display();

    return 0;
}
