// Pizza parlour accepting maximum n orders. Orders are served on an FCFS basis. Order once placed can’t be cancelled. 
// Write C++ program to simulate the system using circular QUEUE.
// | Case                                     | Time Complexity | Space Complexity |
// | ---------------------------------------- | --------------- | ---------------- |
// | **Best/Average/Worst (enqueue/dequeue)** | **O(1)**        | **O(n)**         |
// | **Display Queue**                        | **O(n)**        | **O(n)**         |

#include <iostream>
using namespace std;

class CircularQueue {
private:
    int front, rear, size;
    int* arr;

public:
    CircularQueue(int n) {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    bool isEmpty() {
        return front == -1;
    }

    void placeOrder(int orderID) {
        if (isFull()) {
            cout << "Order Queue Full! Cannot accept more orders.\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }

        arr[rear] = orderID;
        cout << "Order Placed: Order Number " << orderID << endl;
    }

    void serveOrder() {
        if (isEmpty()) {
            cout << "No orders to serve.\n";
            return;
        }

        cout << "Serving Order Number: " << arr[front] << endl;

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    void displayOrders() {
        if (isEmpty()) {
            cout << "No pending orders.\n";
            return;
        }

        cout << "Pending Orders: ";
        int i = front;

        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    int n, choice, orderID = 1;

    cout << "Enter maximum number of pizza orders: ";
    cin >> n;

    CircularQueue q(n);

    while (true) {
        cout << "\n--- Pizza Parlour Order System ---\n";
        cout << "1. Place Order\n";
        cout << "2. Serve Order\n";
        cout << "3. Display Pending Orders\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            q.placeOrder(orderID++);
        }
        else if (choice == 2) {
            q.serveOrder();
        }
        else if (choice == 3) {
            q.displayOrders();
        }
        else if (choice == 4) {
            cout << "Thank you! Closing ordering system.\n";
            break;
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;

}
