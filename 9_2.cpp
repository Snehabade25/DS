// Use Hashtable to Store and retrieve student records using roll numbers.

#include <iostream>
using namespace std;

class Student {
public:
    int roll;
    string name;

    Student() {
        roll = -1;     // -1 means empty slot
        name = "";
    }
};

class HashTable {
private:
    Student table[20];  // fixed-size hash table
    int size;

public:
    HashTable(int s) {
        size = s;
    }

    // Hash Function
    int hash(int key) {
        return key % size;
    }

    // Insert a student
    void insert(int roll, string name) {
        int index = hash(roll);

        // Linear probing
        while (table[index].roll != -1) {
            index = (index + 1) % size;
        }

        table[index].roll = roll;
        table[index].name = name;

        cout << "Inserted: " << roll << " - " << name << endl;
    }

    // Search a student by roll number
    void search(int roll) {
        int index = hash(roll);
        int start = index;

        while (table[index].roll != -1) {

            if (table[index].roll == roll) {
                cout << "Record Found: Roll = " << roll 
                     << ", Name = " << table[index].name << endl;
                return;
            }

            index = (index + 1) % size;

            if (index == start) break;   // full loop
        }

        cout << "Record NOT Found!" << endl;
    }

    // Display table
    void display() {
        cout << "\nHash Table Records:\n";
        for (int i = 0; i < size; i++) {
            if (table[i].roll != -1)
                cout << i << " --> Roll: " << table[i].roll 
                     << ", Name: " << table[i].name << endl;
            else
                cout << i << " --> EMPTY" << endl;
        }
    }
};

int main() {
    int size;
    cout << "Enter hash table size: ";
    cin >> size;

    HashTable ht(size);

    int choice;
    while (true) {
        cout << "\n1. Insert Student\n2. Search Student\n3. Display Table\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int roll;
            string name;
            cout << "Enter Roll Number: ";
            cin >> roll;
            cout << "Enter Name: ";
            cin >> name;
            ht.insert(roll, name);
        }
        else if (choice == 2) {
            int roll;
            cout << "Enter Roll Number to Search: ";
            cin >> roll;
            ht.search(roll);
        }
        else if (choice == 3) {
            ht.display();
        }
        else {
            break;
        }
    }

    return 0;
}