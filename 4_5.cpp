// FrontBackSplit for Singly Linked List
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) { data = d; next = NULL; }
};

void push(Node*& head, int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

// Function to split the linked list into two halves
void FrontBackSplit(Node* source, Node*& frontRef, Node*& backRef) {
    if (source == NULL || source->next == NULL) {
        // Length < 2 cases
        frontRef = source;
        backRef = NULL;
        return;
    }

    Node *slow = source, *fast = source->next;

    // Move fast by two nodes and slow by one node
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // Split at slow
    frontRef = source;
    backRef = slow->next;
    slow->next = NULL;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    Node *front = NULL, *back = NULL;

    // Example list: {2, 3, 5, 7, 11} (insert in reverse order)
    push(head, 11);
    push(head, 7);
    push(head, 5);
    push(head, 3);
    push(head, 2);

    cout << "Original List: ";
    printList(head);

    FrontBackSplit(head, front, back);

    cout << "\nFront List: ";
    printList(front);

    cout << "Back List: ";
    printList(back);

    return 0;
}
