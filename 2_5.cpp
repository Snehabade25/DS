// Write a program to arrange the list of employees as per the average of their height and weight by using Merge and 
// Selection sorting method. Analyse their time complexities and conclude which algorithm will take less time to sort the list.
// Selection Sort:
// Simple, but O(n²) → becomes very slow for large n.
// Merge Sort:
// More complex, but O(n log n) → much faster as n grows.

#include <iostream>
#include <string>
using namespace std;

struct Employee {
    string name;
    float height;
    float weight;
    float avg; // (height + weight) / 2
};

// ---------- Utility: Swap ----------
void swapEmp(Employee &a, Employee &b) {
    Employee temp = a;
    a = b;
    b = temp;
}

// ---------- SELECTION SORT ----------
int selectionComparisons = 0;
int selectionSwaps = 0;

void selectionSort(Employee arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            selectionComparisons++;
            if (arr[j].avg < arr[minIndex].avg) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            swapEmp(arr[i], arr[minIndex]);
            selectionSwaps++;
        }
    }
}

// ---------- MERGE SORT ----------
int mergeComparisons = 0;

void merge(Employee arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Employee *L = new Employee[n1];
    Employee *R = new Employee[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        mergeComparisons++;
        if (L[i].avg <= R[j].avg) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // remaining elements
    while (i < n1) {
        arr[k] = L[i];
        i++; k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++; k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(Employee arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// ---------- DISPLAY ----------
void displayEmployees(Employee arr[], int n) {
    cout << "Name\tHeight\tWeight\tAverage\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i].name << "\t"
             << arr[i].height << "\t"
             << arr[i].weight << "\t"
             << arr[i].avg << endl;
    }
    cout << endl;
}

// ---------- MAIN ----------
int main() {
    int n;
    Employee empSel[50], empMerge[50];

    cout << "Enter number of employees: ";
    cin >> n;

    cout << "\nEnter employee details (name height weight):\n";
    for (int i = 0; i < n; i++) {
        cout << "Employee " << i + 1 << ":\n";
        cin >> empSel[i].name >> empSel[i].height >> empSel[i].weight;
        empSel[i].avg = (empSel[i].height + empSel[i].weight) / 2.0f;
        empMerge[i] = empSel[i]; // copy for merge sort
    }

    cout << "\nOriginal List:\n";
    displayEmployees(empSel, n);

    // ---- Selection Sort ----
    selectionSort(empSel, n);
    cout << "--- After Selection Sort (by average height+weight) ---\n";
    displayEmployees(empSel, n);
    cout << "Selection Sort comparisons: " << selectionComparisons << endl;
    cout << "Selection Sort swaps:       " << selectionSwaps << endl;

    // ---- Merge Sort ----
    mergeSort(empMerge, 0, n - 1);
    cout << "--- After Merge Sort (by average height+weight) ---\n";
    displayEmployees(empMerge, n);
    cout << "Merge Sort comparisons:     " << mergeComparisons << endl;

    // ---- Theoretical Conclusion ----
    cout << "\nTime Complexity (theoretical):\n";
    cout << "Selection Sort: O(n^2)\n";
    cout << "Merge Sort:     O(n log n)\n";

    cout << "\nConclusion: For larger number of employees, Merge Sort will take less time\n"
            "to sort the list compared to Selection Sort.\n";

    return 0;
}
