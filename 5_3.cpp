// Write a program to implement multiple stack i.e more than two stack using array and perform following operations on it. 
// A. Push B. Pop C. Stack Overflow D. Stack Underflow E. Display
// | Component      | Complexity   |
// | -------------- | ------------ |
// | Time (Push)    | **O(1)**     |
// | Time (Pop)     | **O(1)**     |
// | Time (Display) | **O(n)**     |
// | Space          | **O(n + k)** |

#include <iostream>
using namespace std;

class MultiStack {
    int *arr;       // array to store stack elements
    int *top;       // array of top indexes of stacks
    int *next;      // array to maintain free list
    int n, k;       // n = size of array, k = number of stacks
    int freeTop;    // beginning index of free list

public:
    MultiStack(int k, int n) {
        this->k = k;
        this->n = n;

        arr = new int[n];
        top = new int[k];
        next = new int[n];

        // initialize all stacks as empty
        for(int i = 0; i < k; i++)
            top[i] = -1;

        // initialize free list
        freeTop = 0;
        for(int i = 0; i < n-1; i++)
            next[i] = i + 1;

        next[n-1] = -1; // end of free list
    }

    // check if array is full
    bool isFull() {
        return (freeTop == -1);
    }

    // check if stack is empty
    bool isEmpty(int sn) {
        return (top[sn] == -1);
    }

    // push operation
    void push(int sn, int x) {
        if (isFull()) {
            cout << "Stack Overflow!\n";
            return;
        }

        int i = freeTop;         // take free index
        freeTop = next[i];       // update freeTop

        next[i] = top[sn];       // link with previous top
        top[sn] = i;             // new top
        arr[i] = x;              // store element
    }

    // pop operation
    int pop(int sn) {
        if (isEmpty(sn)) {
            cout << "Stack Underflow!\n";
            return -1;
        }

        int i = top[sn];       // index of top element
        top[sn] = next[i];     // make next element as top
        next[i] = freeTop;     // add index to free list
        freeTop = i;

        return arr[i];
    }

    // display a particular stack
    void display(int sn) {
        if (isEmpty(sn)) {
            cout << "Stack " << sn << " is empty.\n";
            return;
        }

        cout << "Stack " << sn << ": ";
        int i = top[sn];
        while(i != -1) {
            cout << arr[i] << " ";
            i = next[i];
        }
        cout << endl;
    }
};

int main() {
    int k, n;
    cout << "Enter number of stacks: ";
    cin >> k;
    cout << "Enter size of array: ";
    cin >> n;

    MultiStack ms(k, n);

    int choice, sn, value;

    do {
        cout << "\n1. Push\n2. Pop\n3. Display\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
        case 1:
            cout << "Enter stack number (0 to " << k-1 << "): ";
            cin >> sn;
            cout << "Enter value: ";
            cin >> value;
            ms.push(sn, value);
            break;

        case 2:
            cout << "Enter stack number (0 to " << k-1 << "): ";
            cin >> sn;
            value = ms.pop(sn);
            if (value != -1)
                cout << "Popped: " << value << endl;
            break;

        case 3:
            cout << "Enter stack number (0 to " << k-1 << "): ";
            cin >> sn;
            ms.display(sn);
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while(choice != 4);

    return 0;
}
