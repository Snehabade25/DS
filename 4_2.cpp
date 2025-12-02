// Implement Bubble sort using Doubly Linked List
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

    // Insert at end
    void insert(int x) {
        Node* n = new Node();
        n->data = x;
        n->prev = n->next = NULL;

        if (!head) {
            head = n;
            return;
        }

        Node* temp = head;
        while (temp->next)
            temp = temp->next;

        temp->next = n;
        n->prev = temp;
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

    // Bubble sort by swapping data
    void bubbleSort() {
        if (!head) return;

        bool swapped;
        Node* ptr;
        Node* last = NULL;

        do {
            swapped = false;
            ptr = head;

            while (ptr->next != last) {
                if (ptr->data > ptr->next->data) {
                    // swap the data
                    int temp = ptr->data;
                    ptr->data = ptr->next->data;
                    ptr->next->data = temp;
                    swapped = true;
                }
                ptr = ptr->next;
            }
            last = ptr;
        } while (swapped);
    }
};

int main() {
    DoublyList dl;
    int n, x;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> x;
        dl.insert(x);
    }

    cout << "\nOriginal List: ";
    dl.display();

    dl.bubbleSort();

    cout << "Sorted List:   ";
    dl.display();

    return 0;
}
