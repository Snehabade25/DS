// In the Second Year Computer Engineering class, there are two groups of students based on their favorite sports:
// Set A includes students who like Cricket. Set B includes students who like Football.
// Write a C++ program to represent these two sets using linked lists and perform the following operations:
// a) Find and display the set of students who like both Cricket and Football.
// b) Find and display the set of students who like either Cricket or Football, but not both.
// c) Display the number of students who like neither Cricket nor Football.
#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    int roll;
    Node* next;
};

// Linked list class for set operations
class SetList {
public:
    Node* head;

    SetList() {
        head = NULL;
    }

    // Insert element in the list
    void insert(int r) {
        Node* n = new Node();
        n->roll = r;
        n->next = head;
        head = n;
    }

    // Check if element exists
    bool exists(int r) {
        Node* temp = head;
        while (temp) {
            if (temp->roll == r)
                return true;
            temp = temp->next;
        }
        return false;
    }

    // Display list
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->roll << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    SetList cricket;   // Set A
    SetList football;  // Set B

    int nA, nB, total;

    cout << "Enter total number of students in class: ";
    cin >> total;

    cout << "Enter number of students who like Cricket: ";
    cin >> nA;
    cout << "Enter roll numbers:\n";
    for (int i = 0; i < nA; i++) {
        int r;
        cin >> r;
        cricket.insert(r);
    }

    cout << "Enter number of students who like Football: ";
    cin >> nB;
    cout << "Enter roll numbers:\n";
    for (int i = 0; i < nB; i++) {
        int r;
        cin >> r;
        football.insert(r);
    }

    // (a) Students who like BOTH sports (Intersection)
    cout << "\nStudents who like BOTH Cricket and Football:\n";
    Node* tempA = cricket.head;
    int bothCount = 0;

    while (tempA) {
        if (football.exists(tempA->roll)) {
            cout << tempA->roll << " ";
            bothCount++;
        }
        tempA = tempA->next;
    }
    if (bothCount == 0) cout << "None";
    cout << endl;

    // (b) Students who like EITHER Cricket OR Football but NOT BOTH (Symmetric Difference)
    cout << "\nStudents who like EITHER Cricket OR Football but NOT BOTH:\n";
    Node* temp;

    // Elements in A but not B
    temp = cricket.head;
    while (temp) {
        if (!football.exists(temp->roll))
            cout << temp->roll << " ";
        temp = temp->next;
    }

    // Elements in B but not A
    temp = football.head;
    while (temp) {
        if (!cricket.exists(temp->roll))
            cout << temp->roll << " ";
        temp = temp->next;
    }
    cout << endl;

    // (c) Students who like NEITHER Cricket nor Football
    int neither = 0;

    for (int r = 1; r <= total; r++) {
        if (!cricket.exists(r) && !football.exists(r))
            neither++;
    }

    cout << "\nNumber of students who like NEITHER Cricket nor Football: "
         << neither << endl;

    return 0;
}
