// WAP to build a simple stock price tracker that keeps a history of daily stock prices entered by the user. 
// To allow users to go back and view or remove the most recent price, 
// implement a stack using a linked list to store these integer prices.
// Implement the following operations:
// record(price) – Add a new stock price (an integer) to the stack.
// remove () – Remove and return the most recent price (top of the stack).
// latest () – Return the most recent stock price without removing it.
// isEmpty() – Check if there are no prices recorded
// | Operation     | Time     | Space                |
// | ------------- | -------- | -------------------- |
// | record (push) | **O(1)** | **O(n)** total nodes |
// | remove (pop)  | **O(1)** | **O(n)**             |
// | latest (peek) | **O(1)** | **O(n)**             |
// | isEmpty       | **O(1)** | **O(n)**             |

#include <iostream>
using namespace std;

// -------- Node Definition --------
class Node {
public:
    int price;
    Node* next;

    Node(int value) {
        price = value;
        next = NULL;
    }
};

// -------- Stack Implementation --------
class StockStack {
private:
    Node* top;   // top of stack

public:
    StockStack() {
        top = NULL;
    }

    // Record a new stock price (Push operation)
    void record(int price) {
        Node* newNode = new Node(price);
        newNode->next = top;
        top = newNode;
        cout << "Price recorded: " << price << endl;
    }

    // Remove the latest price (Pop operation)
    void removePrice() {
        if (isEmpty()) {
            cout << "No prices to remove.\n";
            return;
        }
        cout << "Removed latest price: " << top->price << endl;

        Node* temp = top;
        top = top->next;
        delete temp;
    }

    // Return the latest price without removing it (Peek)
    void latest() {
        if (isEmpty()) {
            cout << "No prices recorded.\n";
            return;
        }
        cout << "Latest recorded price: " << top->price << endl;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == NULL;
    }

    // Display full history (optional extra feature)
    void displayHistory() {
        if (isEmpty()) {
            cout << "No price history available.\n";
            return;
        }
        cout << "Price History (Latest → Oldest): ";
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->price << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// ---------- MAIN PROGRAM ----------
int main() {
    StockStack tracker;
    int choice, price;

    while (true) {
        cout << "\n--- Stock Price Tracker ---\n";
        cout << "1. Record New Price\n";
        cout << "2. Remove Latest Price\n";
        cout << "3. View Latest Price\n";
        cout << "4. Check if Empty\n";
        cout << "5. Show Full Price History\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter stock price: ";
            cin >> price;
            tracker.record(price);
            break;

        case 2:
            tracker.removePrice();
            break;

        case 3:
            tracker.latest();
            break;

        case 4:
            if (tracker.isEmpty())
                cout << "No prices recorded.\n";
            else
                cout << "Prices are recorded.\n";
            break;

        case 5:
            tracker.displayHistory();
            break;

        case 6:
            cout << "Exiting Stock Tracker...\n";
            return 0;

        default:
            cout << "Invalid choice.\n";
        }
    }
}
