// Write a program to input marks of n students Sort the marks in ascending order using the Quick Sort algorithm 
// without using built-in library functions and analyse the sorting algorithm pass by pass. Find the minimum 
// and maximum marks using Divide and Conquer (recursively).
// | Case    | Time       |
// | ------- | ---------- |
// | Best    | O(n log n) |
// | Average | O(n log n) |
// | Worst   | O(n²)      |
// | Metric | Value                     |
// | ------ | ------------------------- |
// | Time   | O(n)                      |
// | Space  | O(log n) due to recursion |

#include <iostream>
using namespace std;

int passNo = 1;

// ----------------- Quick Sort -----------------
int partitionFunc(int arr[], int low, int high, int n) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            // swap
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // final pivot swap
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    // Display pass
    cout << "Pass " << passNo++ << ": ";
    for (int k = 0; k < n; k++) cout << arr[k] << " ";
    cout << endl;

    return i + 1;
}

void quickSort(int arr[], int low, int high, int n) {
    if (low < high) {
        int pi = partitionFunc(arr, low, high, n);
        quickSort(arr, low, pi - 1, n);
        quickSort(arr, pi + 1, high, n);
    }
}

// ----------------- Divide & Conquer Min/Max -----------------
void findMinMax(int arr[], int low, int high, int &minVal, int &maxVal) {

    if (low == high) {  
        if (arr[low] < minVal) minVal = arr[low];
        if (arr[low] > maxVal) maxVal = arr[low];
        return;
    }

    if (high == low + 1) { 
        if (arr[low] < arr[high]) {
            if (arr[low] < minVal) minVal = arr[low];
            if (arr[high] > maxVal) maxVal = arr[high];
        } else {
            if (arr[high] < minVal) minVal = arr[high];
            if (arr[low] > maxVal) maxVal = arr[low];
        }
        return;
    }

    int mid = (low + high) / 2;
    findMinMax(arr, low, mid, minVal, maxVal);
    findMinMax(arr, mid + 1, high, minVal, maxVal);
}

// ----------------- MAIN FUNCTION -----------------
int main() {
    int n;
    int marks[50];

    cout << "Enter number of students: ";
    cin >> n;

    cout << "Enter marks of " << n << " students:\n";
    for (int i = 0; i < n; i++)
        cin >> marks[i];

    cout << "\n--- Quick Sort Process (Pass by Pass) ---\n";
    quickSort(marks, 0, n - 1, n);

    cout << "\nSorted Marks (Ascending): ";
    for (int i = 0; i < n; i++)
        cout << marks[i] << " ";
    cout << endl;

    // Finding Min & Max using Divide and Conquer
    int minVal = marks[0], maxVal = marks[0];
    findMinMax(marks, 0, n - 1, minVal, maxVal);

    cout << "\nMinimum Marks: " << minVal << endl;
    cout << "Maximum Marks: " << maxVal << endl;

    return 0;
}
