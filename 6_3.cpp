// Write a program that maintains a queue of passengers waiting to see a ticket agent. 
// The program user should be able to insert a new passenger at the rear of the queue, 
// Display the passenger at the front of the Queue, or remove the passenger at the front of the queue. 
// The program will display the number of passengers left in the queue just before it terminates
// | Factor                               | Complexity |
// | ------------------------------------ | ---------- |
// | **Time complexity (all operations)** | **O(1)**   |
// | **Space complexity**                 | **O(n)**   |


#include <iostream>
using namespace std;

class PassengerQueue {
private:
    string arr[50];    // fixed queue size
    int front, rear, count;

public:
    PassengerQueue() {
        front = 0;
        rear = 0;
        count = 0;
    }

    bool isFull() {
        return count == 50;
    }

    bool isEmpty() {
        return count == 0;
    }

    void addPassenger(string name) {
        if (isFull()) {
            cout << "Queue is full. Cannot add more passengers.\n";
            return;
        }
        arr[rear] = name;
        rear = (rear + 1) % 50;
        count++;
        cout << "Passenger added: " << name << endl;
    }

    void showFront() {
        if (isEmpty()) {
            cout << "No passengers waiting.\n";
            return;
        }
        cout << "Passenger at front: " << arr[front] << endl;
    }

    void removePassenger() {
        if (isEmpty()) {
            cout << "No passengers to remove.\n";
            return;
        }
        cout << "Passenger leaving: " << arr[front] << endl;
        front = (front + 1) % 50;
        count--;
    }

    void remainingPassengers() {
        cout << "\nTotal passengers left in queue: " << count << endl;
    }
};

// ---------------- MAIN FUNCTION ----------------

int main() {
    PassengerQueue q;
    int choice;
    string name;

    while (true) {
        cout << "\n--- Ticket Counter Queue System ---\n";
        cout << "1. Add Passenger\n";
        cout << "2. Show Front Passenger\n";
        cout << "3. Serve (Remove) Front Passenger\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter passenger name: ";
            cin >> name;
            q.addPassenger(name);
        }
        else if (choice == 2) {
            q.showFront();
        }
        else if (choice == 3) {
            q.removePassenger();
        }
        else if (choice == 4) {
            q.remainingPassengers();
            cout << "System closing... Goodbye!\n";
            break;
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
