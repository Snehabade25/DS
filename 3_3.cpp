// Develop a C++ program to store and manage an appointment schedule for a single day. Appointments should be scheduled 
// randomly using a linked list. The system must define the start time, end time, and specify the minimum and 
// maximum duration allowed for each appointment slot.
// The program should include the following operations:
// a) Display the list of currently available time slots.
// b) Book a new appointment within the defined time limits.
// c) Cancel an existing appointment after validating its time, availability, and correctness.
// d) Sort the appointment list in order of appointment times.
// e) Sort the list based on appointment times using pointer manipulation (without swapping data values).
#include <iostream>
using namespace std;

struct Node {
    int start;      // start time in minutes (e.g., 9:30 → 570)
    int end;        // end time in minutes
    Node* next;
};

class AppointmentList {
private:
    Node* head;
    int dayStart, dayEnd;
    int minDur, maxDur;

public:
    AppointmentList(int ds, int de, int minD, int maxD) {
        head = NULL;
        dayStart = ds;
        dayEnd = de;
        minDur = minD;
        maxDur = maxD;
    }

    // Utility: convert minutes to HH:MM format
    void printTime(int t) {
        int h = t / 60;
        int m = t % 60;
        cout << (h < 10 ? "0" : "") << h << ":"
             << (m < 10 ? "0" : "") << m;
    }

    // (a) Display appointments
    void display() {
        if (!head) {
            cout << "No appointments booked.\n";
            return;
        }
        Node* temp = head;
        cout << "Appointments:\n";
        while (temp) {
            printTime(temp->start);
            cout << " - ";
            printTime(temp->end);
            cout << endl;
            temp = temp->next;
        }
    }

    // Check if a time slot is free
    bool isFree(int s, int e) {
        Node* temp = head;
        while (temp) {
            if (!(e <= temp->start || s >= temp->end)) {
                return false; // clash
            }
            temp = temp->next;
        }
        return true;
    }

    // (b) Book appointment
    void book(int s, int e) {
        if (s < dayStart || e > dayEnd || (e - s) < minDur || (e - s) > maxDur) {
            cout << "Invalid time or duration range.\n";
            return;
        }

        if (!isFree(s, e)) {
            cout << "Time slot not available.\n";
            return;
        }

        Node* n = new Node();
        n->start = s;
        n->end = e;
        n->next = NULL;

        // Insert sorted by time
        if (!head || s < head->start) {
            n->next = head;
            head = n;
            cout << "Appointment booked.\n";
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->start < s)
            temp = temp->next;

        n->next = temp->next;
        temp->next = n;
        cout << "Appointment booked.\n";
    }

    // (c) Cancel appointment
    void cancel(int s, int e) {
        if (!head) {
            cout << "No appointments.\n";
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        while (temp) {
            if (temp->start == s && temp->end == e) {
                if (prev == NULL)
                    head = temp->next;
                else
                    prev->next = temp->next;
                delete temp;
                cout << "Appointment cancelled.\n";
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "Appointment not found.\n";
    }

    // (d) Sort by swapping data values
    void sortByData() {
        if (!head || !head->next) return;
        Node* i = head;
        while (i) {
            Node* j = i->next;
            while (j) {
                if (i->start > j->start) {
                    // swap start
                    int ts = i->start;
                    i->start = j->start;
                    j->start = ts;
                    // swap end
                    int te = i->end;
                    i->end = j->end;
                    j->end = te;
                }
                j = j->next;
            }
            i = i->next;
        }
        cout << "Sorted (data swapping).\n";
    }

    // (e) Sort by pointer manipulation (no data swap)
    void sortByPointers() {
        if (!head || !head->next) return;

        Node* sorted = NULL;

        while (head) {
            Node* curr = head;
            head = head->next;
            curr->next = NULL;

            // Insert into new sorted list
            if (!sorted || curr->start < sorted->start) {
                curr->next = sorted;
                sorted = curr;
            } else {
                Node* temp = sorted;
                while (temp->next && temp->next->start < curr->start)
                    temp = temp->next;
                curr->next = temp->next;
                temp->next = curr;
            }
        }

        head = sorted;
        cout << "Sorted (pointer manipulation).\n";
    }
};

int main() {
    int dayStart = 9 * 60;    // 09:00
    int dayEnd   = 17 * 60;   // 17:00
    int minD = 30;            // 30 min min
    int maxD = 120;           // 2 hours max

    AppointmentList ap(dayStart, dayEnd, minD, maxD);

    int choice, s, e;

    while (1) {
        cout << "\n--- Appointment Menu ---\n";
        cout << "1. Display appointments\n";
        cout << "2. Book appointment\n";
        cout << "3. Cancel appointment\n";
        cout << "4. Sort by data\n";
        cout << "5. Sort by pointer manipulation\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            ap.display();
            break;
        case 2:
            cout << "Enter start time (minutes from 0): ";
            cin >> s;
            cout << "Enter end time: ";
            cin >> e;
            ap.book(s, e);
            break;
        case 3:
            cout << "Enter start time of appointment to cancel: ";
            cin >> s;
            cout << "Enter end time: ";
            cin >> e;
            ap.cancel(s, e);
            break;
        case 4:
            ap.sortByData();
            break;
        case 5:
            ap.sortByPointers();
            break;
        case 6:
            return 0;
        default:
            cout << "Invalid option.\n";
        }
    }

    return 0;
}
