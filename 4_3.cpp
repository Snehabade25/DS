// WAP to create a doubly linked list and perform following operations on it.
// A) Insert (all cases) 2. Delete (all cases).
// | Operation             | Time Complexity | Space Complexity |
// | --------------------- | --------------- | ---------------- |
// | Insert at beginning   | O(1)            | O(1)             |
// | Insert at end         | O(n)            | O(1)             |
// | Insert at position    | O(n)            | O(1)             |
// | Delete from beginning | O(1)            | O(1)             |
// | Delete from end       | O(n)            | O(1)             |
// | Delete from position  | O(n)            | O(1)             |
// | Entire DLL storage    | —               | **O(n)**         |

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyList {
public:
    Node* head;

    DoublyList() {
        head = NULL;
    }

    // ---------------- INSERTION ----------------

    // 1. Insert at beginning
    void insertBegin(int x) {
        Node* n = new Node();
        n->data = x;
        n->prev = NULL;
        n->next = head;

        if (head != NULL)
            head->prev = n;

        head = n;
    }

    // 2. Insert at end
    void insertEnd(int x) {
        Node* n = new Node();
        n->data = x;
        n->next = NULL;

        if (head == NULL) {
            n->prev = NULL;
            head = n;
            return;
        }

        Node* temp = head;
        while (temp->next)
            temp = temp->next;

        temp->next = n;
        n->prev = temp;
    }

    // 3. Insert at position (1-based)
    void insertAtPos(int x, int pos) {
        if (pos == 1) {
            insertBegin(x);
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++)
            temp = temp->next;

        if (!temp) {
            cout << "Position out of range\n";
            return;
        }

        Node* n = new Node();
        n->data = x;
        n->next = temp->next;
        n->prev = temp;

        if (temp->next != NULL)
            temp->next->prev = n;

        temp->next = n;
    }

    // ---------------- DELETION ----------------

    // 1. Delete from beginning
    void deleteBegin() {
        if (!head) {
            cout << "List Empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head)
            head->prev = NULL;

        delete temp;
    }

    // 2. Delete from end
    void deleteEnd() {
        if (!head) {
            cout << "List Empty\n";
            return;
        }

        if (head->next == NULL) { // only one node
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next)
            temp = temp->next;

        temp->prev->next = NULL;
        delete temp;
    }

    // 3. Delete at position
    void deleteAtPos(int pos) {
        if (!head) {
            cout << "List Empty\n";
            return;
        }

        if (pos == 1) {
            deleteBegin();
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos && temp != NULL; i++)
            temp = temp->next;

        if (!temp) {
            cout << "Position out of range\n";
            return;
        }

        if (temp->next)
            temp->next->prev = temp->prev;

        if (temp->prev)
            temp->prev->next = temp->next;

        delete temp;
    }

    // Display list
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyList dl;
    int choice, value, pos;

    while (true) {
        cout << "\n----- MENU -----\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete at Position\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            dl.insertBegin(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            dl.insertEnd(value);
            break;

        case 3:
            cout << "Enter value: ";
            cin >> value;
            cout << "Enter position: ";
            cin >> pos;
            dl.insertAtPos(value, pos);
            break;

        case 4:
            dl.deleteBegin();
            break;

        case 5:
            dl.deleteEnd();
            break;

        case 6:
            cout << "Enter position: ";
            cin >> pos;
            dl.deleteAtPos(pos);
            break;

        case 7:
            dl.display();
            break;

        case 8:
            return 0;

        default:
            cout << "Invalid choice!";
        }
    }
}
