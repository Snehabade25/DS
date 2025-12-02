// WAP to implement Bubble sort and Quick Sort on a 1D array of Student structure 
// (contains student_name, student_roll_no, total_marks), with key as student_roll_no. 
// And count the number of swap performed by each method.
// | Sorting Method  | Time Complexity                                 | Space                | Swap Count |
// | --------------- | ----------------------------------------------- | -------------------- | ---------- |
// | **Bubble Sort** | O(n²)                                           | O(1)                 | High       |
// | **Quick Sort**  | Best: O(n log n), Worst: O(n²), Avg: O(n log n) | O(log n) (recursive) | Lower      |

#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int roll_no;
    float total_marks;
};

// ---------- Swap Function ----------
void swap(Student &a, Student &b) {
    Student temp = a;
    a = b;
    b = temp;
}

// ---------- Bubble Sort ----------
int bubbleSort(Student arr[], int n) {
    int swapCount = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].roll_no > arr[j + 1].roll_no) {
                swap(arr[j], arr[j + 1]);
                swapCount++;
            }
        }
    }
    return swapCount;
}

// ---------- Quick Sort ----------
int quickSwapCount = 0;

int partition(Student arr[], int low, int high) {
    int pivot = arr[high].roll_no;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].roll_no < pivot) {
            i++;
            swap(arr[i], arr[j]);
            quickSwapCount++;
        }
    }
    swap(arr[i + 1], arr[high]);
    quickSwapCount++;
    return i + 1;
}

void quickSort(Student arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

// ---------- Display Students ----------
void display(Student arr[], int n) {
    cout << "\nRoll_No\tName\tTotal_Marks\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i].roll_no << "\t" << arr[i].name << "\t" << arr[i].total_marks << endl;
    }
}

int main() {
    int n;

    cout << "Enter total number of students: ";
    cin >> n;

    Student arr1[50], arr2[50]; // Two copies for both sorting methods

    cout << "\nEnter student details:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nStudent " << i + 1 << ":\n";
        cout << "Name: ";
        cin >> arr1[i].name;
        cout << "Roll No: ";
        cin >> arr1[i].roll_no;
        cout << "Total Marks: ";
        cin >> arr1[i].total_marks;

        arr2[i] = arr1[i]; // Copy for quick sort
    }

    // -------- Bubble Sort --------
    cout << "\n--- Applying Bubble Sort ---\n";
    int bubbleSwaps = bubbleSort(arr1, n);
    display(arr1, n);
    cout << "\nTotal swaps by Bubble Sort: " << bubbleSwaps << endl;

    // -------- Quick Sort --------
    cout << "\n--- Applying Quick Sort ---\n";
    quickSort(arr2, 0, n - 1);
    display(arr2, n);
    cout << "\nTotal swaps by Quick Sort: " << quickSwapCount << endl;

    return 0;
}
