// Write a program to implement multiple queues 
// i.e. two queues using array and perform following operations on it.
// A. Add Queue, B. Delete from Queue, C. Display Queue
// | Operation        | Time | Space |
// | ---------------- | ---- | ----- |
// | Add (Enqueue)    | O(1) | O(n)  |
// | Delete (Dequeue) | O(1) | O(n)  |
// | Display Queue    | O(n) | O(n)  |

#include <iostream>
using namespace std;

class MultipleQueue {
private:
    int arr[50];   // common array for both queues
    int front1, rear1;
    int front2, rear2;
    int mid;       // dividing point

public:
    MultipleQueue() {
        mid = 25;  // half for Q1, half for Q2
        front1 = rear1 = 0;
        front2 = rear2 = mid;
    }

    // Add element in selected queue
    void add(int queueNumber, int value) {
        if (queueNumber == 1) {
            if (rear1 == mid) {
                cout << "Queue 1 Overflow!\n";
                return;
            }
            arr[rear1++] = value;
        } else if (queueNumber == 2) {
            if (rear2 == 50) {
                cout << "Queue 2 Overflow!\n";
                return;
            }
            arr[rear2++] = value;
        } else {
            cout << "Invalid Queue Number!\n";
        }
    }

    // Delete from selected queue
    void remove(int queueNumber) {
        if (queueNumber == 1) {
            if (front1 == rear1) {
                cout << "Queue 1 is Empty!\n";
                return;
            }
            cout << "Deleted from Queue 1: " << arr[front1++] << endl;
        } 
        else if (queueNumber == 2) {
            if (front2 == rear2) {
                cout << "Queue 2 is Empty!\n";
                return;
            }
            cout << "Deleted from Queue 2: " << arr[front2++] << endl;
        } 
        else {
            cout << "Invalid Queue Number!\n";
        }
    }

    // Display selected queue
    void display(int queueNumber) {
        if (queueNumber == 1) {
            if (front1 == rear1) {
                cout << "Queue 1 is Empty!\n";
                return;
            }
            cout << "Queue 1 Elements: ";
            for (int i = front1; i < rear1; i++)
                cout << arr[i] << " ";
            cout << endl;
        } 
        else if (queueNumber == 2) {
            if (front2 == rear2) {
                cout << "Queue 2 is Empty!\n";
                return;
            }
            cout << "Queue 2 Elements: ";
            for (int i = front2; i < rear2; i++)
                cout << arr[i] << " ";
            cout << endl;
        } 
        else {
            cout << "Invalid Queue Number!\n";
        }
    }
};

// ---------------- MAIN FUNCTION ----------------
int main() {
    MultipleQueue mq;
    int choice, qNo, value;

    while (true) {
        cout << "\n--- Multiple Queue Operations ---\n";
        cout << "1. Add to Queue\n";
        cout << "2. Delete from Queue\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Queue Number (1 or 2): ";
            cin >> qNo;
            cout << "Enter value: ";
            cin >> value;
            mq.add(qNo, value);
        } 
        else if (choice == 2) {
            cout << "Enter Queue Number (1 or 2): ";
            cin >> qNo;
            mq.remove(qNo);
        } 
        else if (choice == 3) {
            cout << "Enter Queue Number (1 or 2): ";
            cin >> qNo;
            mq.display(qNo);
        } 
        else if (choice == 4) {
            cout << "Exiting...\n";
            break;
        } 
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
