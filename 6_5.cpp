// In a call center, customer calls are handled on a first-come, first-served basis. 
// Implement a queue system using Linked list where:
// Each customer call is enqueued as it arrives. Customer service agents dequeue calls to assist customers. 
// If there are no calls, the system waits.
// | Operation     | Time Complexity | Space Complexity     |
// | ------------- | --------------- | -------------------- |
// | Enqueue       | **O(1)**        | **O(n)** total nodes |
// | Dequeue       | **O(1)**        | **O(n)**             |
// | Display Queue | **O(n)**        | **O(n)**             |

#include <iostream>
using namespace std;

// -------- Node Definition --------
class Node {
public:
    int callID;
    Node* next;

    Node(int id) {
        callID = id;
        next = NULL;
    }
};

// -------- Queue Using Linked List --------
class CallQueue {
private:
    Node* front;
    Node* rear;

public:
    CallQueue() {
        front = rear = NULL;
    }

    // Enqueue new call
    void receiveCall(int id) {
        Node* newNode = new Node(id);

        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Call received and added to queue. Call ID: " << id << endl;
    }

    // Dequeue call to agent
    void assistCustomer() {
        if (front == NULL) {
            cout << "No calls waiting. Agents are idle.\n";
            return;
        }

        cout << "Serving Call ID: " << front->callID << endl;

        Node* temp = front;
        front = front->next;

        if (front == NULL)   // If queue becomes empty
            rear = NULL;

        delete temp;
    }

    // Display waiting calls
    void showWaitingCalls() {
        if (front == NULL) {
            cout << "No calls in queue.\n";
            return;
        }

        cout << "Calls waiting in queue: ";
        Node* temp = front;

        while (temp != NULL) {
            cout << temp->callID << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// ----------- MAIN FUNCTION ------------
int main() {
    CallQueue q;
    int choice, callID = 1;

    while (true) {
        cout << "\n--- Call Center System ---\n";
        cout << "1. Receive New Call\n";
        cout << "2. Assist Next Customer\n";
        cout << "3. Display Waiting Calls\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            q.receiveCall(callID++);
            break;

        case 2:
            q.assistCustomer();
            break;

        case 3:
            q.showWaitingCalls();
            break;

        case 4:
            cout << "System shutting down...\n";
            return 0;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
}
