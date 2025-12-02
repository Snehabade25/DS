// Implement a hash table with collision resolution using linear probing.

#include <iostream>
using namespace std;

class HashTable {
private:
    int table[50];
    int size;

public:
    HashTable(int s) {
        size = s;
        for (int i = 0; i < size; i++)
            table[i] = -1;   // -1 means empty
    }

    // Hash Function
    int hash(int key) {
        return key % size;
    }

    // Insert using Linear Probing
    void insert(int key) {
        int index = hash(key);

        // If occupied, probe linearly
        int startIndex = index;

        while (table[index] != -1) {
            index = (index + 1) % size;

            // Table is full
            if (index == startIndex) {
                cout << "Hash Table Full! Cannot insert " << key << endl;
                return;
            }
        }

        table[index] = key;
        cout << "Inserted " << key << " at index " << index << endl;
    }

    // Search using Linear Probing
    int search(int key) {
        int index = hash(key);
        int startIndex = index;

        while (table[index] != -1) {
            if (table[index] == key)
                return index;   // key found

            index = (index + 1) % size;

            if (index == startIndex)
                return -1;      // searched all positions
        }
        return -1;              // not found
    }

    void display() {
        cout << "\nHash Table:\n";
        for (int i = 0; i < size; i++) {
            cout << i << " : " << table[i] << endl;
        }
    }
};

int main() {
    int size;
    cout << "Enter hash table size: ";
    cin >> size;

    HashTable h(size);

    int n;
    cout << "Enter number of elements to insert: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;
        h.insert(key);
    }

    h.display();

    int key;
    cout << "\nEnter key to search: ";
    cin >> key;

    int result = h.search(key);

    if (result != -1)
        cout << "Key found at index: " << result << endl;
    else
        cout << "Key not found in the table.\n";

    return 0;
}
