// The ticket reservation system for Galaxy Multiplex is to be implemented using a C++ program. 
// The multiplex has 8 rows, with 8 seats in each row. A doubly circular linked list will be used to track 
// the availability of seats in each row. Initially, assume that some seats are randomly booked. 
// An array will store head pointers for each row’s linked list. The system should support the following operations:
// a) Display the current list of available seats.
// b) Book one or more seats as per customer request.
// c) Cancel an existing booking when requested.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int ROWS = 8;
const int SEATS = 8;

struct Node {
    int seatNo;
    bool booked;      // false = available, true = booked
    Node* next;
    Node* prev;
};

// Create a doubly circular linked list for one row
Node* createRow() {
    Node* head = NULL;
    Node* last = NULL;

    for (int i = 1; i <= SEATS; i++) {
        Node* newNode = new Node;
        newNode->seatNo = i;
        newNode->booked = false;
        newNode->next = newNode->prev = NULL;

        if (head == NULL) {
            head = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            newNode->prev = last;
            last = newNode;
        }
    }

    // make it circular
    head->prev = last;
    last->next = head;

    return head;
}

// Randomly book some seats in a row
void randomlyBookSeats(Node* head) {
    int toBook = rand() % 4; // randomly 0 to 3 seats
    while (toBook > 0) {
        int seat = (rand() % SEATS) + 1; // 1..SEATS
        Node* temp = head;
        do {
            if (temp->seatNo == seat) {
                if (!temp->booked) {
                    temp->booked = true;
                    toBook--;
                }
                break;
            }
            temp = temp->next;
        } while (temp != head);
    }
}

// Initialize all rows
void initTheatre(Node* rows[]) {
    for (int i = 0; i < ROWS; i++) {
        rows[i] = createRow();
        randomlyBookSeats(rows[i]);
    }
}

// Display current seat status
void displaySeats(Node* rows[]) {
    cout << "\nSeat Layout (A = Available, B = Booked)\n";
    for (int r = 0; r < ROWS; r++) {
        cout << "Row " << (r + 1) << ": ";
        Node* head = rows[r];
        Node* temp = head;
        if (!head) continue;

        do {
            cout << temp->seatNo << "(" << (temp->booked ? 'B' : 'A') << ") ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
}

// Find seat node in a row by seat number
Node* findSeat(Node* head, int seatNo) {
    if (!head) return NULL;
    Node* temp = head;
    do {
        if (temp->seatNo == seatNo)
            return temp;
        temp = temp->next;
    } while (temp != head);
    return NULL;
}

// Book seats
void bookSeats(Node* rows[]) {
    int count;
    cout << "How many seats do you want to book? ";
    cin >> count;

    for (int i = 0; i < count; i++) {
        int row, seat;
        cout << "\nEnter row number (1-" << ROWS << "): ";
        cin >> row;
        cout << "Enter seat number (1-" << SEATS << "): ";
        cin >> seat;

        if (row < 1 || row > ROWS || seat < 1 || seat > SEATS) {
            cout << "Invalid row or seat number.\n";
            i--; // don't count this as a valid attempt
            continue;
        }

        Node* seatNode = findSeat(rows[row - 1], seat);
        if (seatNode->booked) {
            cout << "Seat already booked! Choose another.\n";
            i--; // try again for this seat
        } else {
            seatNode->booked = true;
            cout << "Seat Row " << row << " Seat " << seat << " booked successfully.\n";
        }
    }
}

// Cancel booking
void cancelSeat(Node* rows[]) {
    int row, seat;
    cout << "Enter row number to cancel (1-" << ROWS << "): ";
    cin >> row;
    cout << "Enter seat number to cancel (1-" << SEATS << "): ";
    cin >> seat;

    if (row < 1 || row > ROWS || seat < 1 || seat > SEATS) {
        cout << "Invalid row or seat number.\n";
        return;
    }

    Node* seatNode = findSeat(rows[row - 1], seat);
    if (!seatNode->booked) {
        cout << "Seat is not booked.\n";
    } else {
        seatNode->booked = false;
        cout << "Booking cancelled for Row " << row << ", Seat " << seat << ".\n";
    }
}

int main() {
    srand(time(0)); // seed for random booking
    Node* rows[ROWS];

    initTheatre(rows);

    int choice;
    while (true) {
        cout << "\n--- Galaxy Multiplex Ticket Reservation ---\n";
        cout << "1. Display available seats\n";
        cout << "2. Book seats\n";
        cout << "3. Cancel booking\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            displaySeats(rows);
            break;
        case 2:
            bookSeats(rows);
            break;
        case 3:
            cancelSeat(rows);
            break;
        case 4:
            cout << "Exiting system...\n";
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
