// implementation of Singly Linked List to Manage ‘Vertex Club’ Membership Records.
// The Department of Computer Engineering has a student club named ‘Vertex Club’ for second, third, and final year students. The first member is the President and the last member is the Secretary. 
// Write a C++ program to:
// Add/delete members (including President/Secretary) Count members Display members Concatenate two division lists
// Also implement: reverse, search by PRN, and sort by PRN operations.

#include <iostream>
#include <string>
using namespace std;

struct Node {
    int prn;
    string name;
    Node* next;

    Node(int p, const string& n) {
        prn = p;
        name = n;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    bool isEmpty() {
        return head == NULL;
    }

    // Add president (at beginning)
    void addPresident(int prn, const string& name) {
        Node* newNode = new Node(prn, name);
        newNode->next = head;
        head = newNode;
    }

    // Add secretary (at end)
    void addSecretary(int prn, const string& name) {
        Node* newNode = new Node(prn, name);
        if (head == NULL) {
            head = newNode; // becomes president too if single member
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    // Add member after a given PRN
    void addMemberAfter(int afterPrn, int prn, const string& name) {
        if (head == NULL) {
            cout << "List empty. Adding as President.\n";
            addPresident(prn, name);
            return;
        }
        Node* temp = head;
        while (temp != NULL && temp->prn != afterPrn)
            temp = temp->next;

        if (temp == NULL) {
            cout << "PRN " << afterPrn << " not found. Adding at end as Secretary.\n";
            addSecretary(prn, name);
        } else {
            Node* newNode = new Node(prn, name);
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Delete member by PRN (includes President/Secretary)
    void deleteByPRN(int prn) {
        if (head == NULL) {
            cout << "List is empty. Cannot delete.\n";
            return;
        }

        // If head is to be deleted
        if (head->prn == prn) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Member with PRN " << prn << " deleted.\n";
            return;
        }

        Node* prev = head;
        Node* curr = head->next;
        while (curr != NULL && curr->prn != prn) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == NULL) {
            cout << "Member with PRN " << prn << " not found.\n";
        } else {
            prev->next = curr->next;
            delete curr;
            cout << "Member with PRN " << prn << " deleted.\n";
        }
    }

    // Count members
    int count() {
        int c = 0;
        Node* temp = head;
        while (temp != NULL) {
            c++;
            temp = temp->next;
        }
        return c;
    }

    // Display members (mark President and Secretary)
    void display() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        int total = count();
        int idx = 1;

        cout << "PRN\tName\tRole\n";
        while (temp != NULL) {
            if (idx == 1 && total == 1)
                cout << temp->prn << "\t" << temp->name << "\tPresident & Secretary\n";
            else if (idx == 1)
                cout << temp->prn << "\t" << temp->name << "\tPresident\n";
            else if (idx == total)
                cout << temp->prn << "\t" << temp->name << "\tSecretary\n";
            else
                cout << temp->prn << "\t" << temp->name << "\tMember\n";

            temp = temp->next;
            idx++;
        }
    }

    // Search by PRN
    Node* search(int prn) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->prn == prn)
                return temp;
            temp = temp->next;
        }
        return NULL;
    }

    // Reverse list
    void reverse() {
        Node* prev = NULL;
        Node* curr = head;
        Node* nextNode = NULL;

        while (curr != NULL) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        head = prev;
        cout << "List reversed.\n";
    }

    // Sort by PRN (simple bubble sort by swapping data)
    void sortByPRN() {
        if (head == NULL || head->next == NULL) {
            cout << "List too small to sort.\n";
            return;
        }

        bool swapped;
        do {
            swapped = false;
            Node* curr = head;
            while (curr->next != NULL) {
                if (curr->prn > curr->next->prn) {
                    // swap data
                    int tprn = curr->prn;
                    string tname = curr->name;

                    curr->prn = curr->next->prn;
                    curr->name = curr->next->name;

                    curr->next->prn = tprn;
                    curr->next->name = tname;

                    swapped = true;
                }
                curr = curr->next;
            }
        } while (swapped);

        cout << "List sorted by PRN.\n";
    }

    // Concatenate another list (append other's members at end)
    void concatenate(LinkedList &other) {
        if (other.head == NULL) {
            cout << "Other list is empty. Nothing to concatenate.\n";
            return;
        }
        if (head == NULL) {
            head = other.head;
        } else {
            Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = other.head;
        }
        other.head = NULL; // optional: clear other list
        cout << "Lists concatenated.\n";
    }
};

// ------------------ MAIN PROGRAM ------------------

int main() {
    LinkedList divA, divB;
    int choice, divChoice;

    while (true) {
        cout << "\n--- Vertex Club Management ---\n";
        cout << "1. Add Member\n";
        cout << "2. Delete Member\n";
        cout << "3. Display Members\n";
        cout << "4. Count Members\n";
        cout << "5. Concatenate Division A and B\n";
        cout << "6. Reverse a Division List\n";
        cout << "7. Search Member by PRN\n";
        cout << "8. Sort Members by PRN\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 9) {
            cout << "Exiting...\n";
            break;
        }

        if (choice >= 1 && choice <= 4 || choice == 6 || choice == 7 || choice == 8) {
            cout << "Select Division: 1. Div A  2. Div B : ";
            cin >> divChoice;
        }

        LinkedList *list = NULL;
        if (choice >= 1 && choice <= 4 || choice == 6 || choice == 7 || choice == 8) {
            if (divChoice == 1) list = &divA;
            else if (divChoice == 2) list = &divB;
            else {
                cout << "Invalid division.\n";
                continue;
            }
        }

        switch (choice) {
        case 1: { // Add Member
            int type;
            cout << "1. Add President\n";
            cout << "2. Add Secretary\n";
            cout << "3. Add Member after given PRN\n";
            cout << "Enter choice: ";
            cin >> type;

            int prn;
            string name;
            cout << "Enter PRN: ";
            cin >> prn;
            cout << "Enter Name: ";
            cin >> name;

            if (type == 1) {
                list->addPresident(prn, name);
            } else if (type == 2) {
                list->addSecretary(prn, name);
            } else if (type == 3) {
                int afterPrn;
                cout << "Enter PRN after which to add: ";
                cin >> afterPrn;
                list->addMemberAfter(afterPrn, prn, name);
            } else {
                cout << "Invalid type.\n";
            }
            break;
        }

        case 2: { // Delete Member
            int prn;
            cout << "Enter PRN to delete: ";
            cin >> prn;
            list->deleteByPRN(prn);
            break;
        }

        case 3: { // Display Members
            cout << "\nDivision " << (divChoice == 1 ? "A" : "B") << " Members:\n";
            list->display();
            break;
        }

        case 4: { // Count Members
            cout << "Total members in Division " << (divChoice == 1 ? "A" : "B")
                 << ": " << list->count() << endl;
            break;
        }

        case 5: { // Concatenate A and B
            cout << "Concatenating Division B to Division A...\n";
            divA.concatenate(divB);
            cout << "Division A after concatenation:\n";
            divA.display();
            break;
        }

        case 6: { // Reverse list
            list->reverse();
            break;
        }

        case 7: { // Search by PRN
            int prn;
            cout << "Enter PRN to search: ";
            cin >> prn;
            Node* res = list->search(prn);
            if (res) {
                cout << "Member found: PRN = " << res->prn << ", Name = " << res->name << endl;
            } else {
                cout << "Member with PRN " << prn << " not found.\n";
            }
            break;
        }

        case 8: { // Sort by PRN
            list->sortByPRN();
            break;
        }

        default:
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
