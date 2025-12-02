// Program to keep track of patients in a clinic and
// assign them to doctors on a first-come, first-served basis.

#include <iostream>
using namespace std;

const int MAX_PATIENTS = 100;
const int MAX_DOCTORS = 10;

class Patient {
public:
    int id;
    char name[50];
};

class Queue {
private:
    Patient arr[MAX_PATIENTS];
    int front, rear;

public:
    Queue() {
        front = 0;
        rear = 0;
    }

    bool isEmpty() {
        return front == rear;
    }

    bool isFull() {
        return rear == MAX_PATIENTS;
    }

    void enqueue(Patient p) {
        if (isFull()) {
            cout << "Waiting room is full. Cannot add more patients.\n";
            return;
        }
        arr[rear] = p;
        rear = rear + 1;
    }

    Patient dequeue() {
        Patient dummy;
        dummy.id = -1;

        if (isEmpty()) {
            cout << "No patients in the waiting queue.\n";
            return dummy;
        }
        Patient value = arr[front];
        front = front + 1;
        return value;
    }

    void display() {
        if (isEmpty()) {
            cout << "No patients in the waiting queue.\n";
            return;
        }
        cout << "Patients in waiting queue:\n";
        for (int i = front; i < rear; i++) {
            cout << "ID: " << arr[i].id << ", Name: " << arr[i].name << endl;
        }
    }
};

int main() {
    Queue q;
    char doctors[MAX_DOCTORS][50];
    int doctorCount;

    cout << "Enter number of doctors (max " << MAX_DOCTORS << "): ";
    cin >> doctorCount;

    if (doctorCount > MAX_DOCTORS)
        doctorCount = MAX_DOCTORS;

    cout << "Enter doctor names:\n";
    for (int i = 0; i < doctorCount; i++) {
        cout << "Doctor " << (i + 1) << ": ";
        cin >> doctors[i];
    }

    int choice;
    int nextPatientId = 1;

    while (true) {
        cout << "\n--- Clinic Patient Management ---\n";
        cout << "1. Check-in new patient\n";
        cout << "2. Assign next patient to a doctor\n";
        cout << "3. Display waiting patients\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Patient p;
            p.id = nextPatientId++;
            cout << "Enter patient name: ";
            cin >> p.name;
            q.enqueue(p);
            cout << "Patient checked in with ID: " << p.id << endl;
        }
        else if (choice == 2) {
            if (doctorCount == 0) {
                cout << "No doctors available.\n";
                continue;
            }

            cout << "Available doctors:\n";
            for (int i = 0; i < doctorCount; i++) {
                cout << (i + 1) << ". Dr. " << doctors[i] << endl;
            }

            int docChoice;
            cout << "Select doctor number: ";
            cin >> docChoice;

            if (docChoice < 1 || docChoice > doctorCount) {
                cout << "Invalid doctor selection.\n";
                continue;
            }

            Patient p = q.dequeue();
            if (p.id != -1) {
                cout << "Assigned Patient ID " << p.id << " (" << p.name
                     << ") to Dr. " << doctors[docChoice - 1] << ".\n";
            }
        }
        else if (choice == 3) {
            q.display();
        }
        else if (choice == 4) {
            cout << "Exiting...\n";
            break;
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
