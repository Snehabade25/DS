// Write a program using Bubble sort algorithm, assign the roll nos. to the students of your class 
// as per their previous years result. i.e. topper will be roll no. 1 and analyse the sorting algorithm pass by pass.
// | Metric               | Value                                    |
// | -------------------- | ---------------------------------------- |
// | **Time Complexity**  | Best: O(n), Average: O(n²), Worst: O(n²) |
// | **Space Complexity** | O(n) (due to array), O(1) extra          |

#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int prevMarks;
    int rollNo;  // will be assigned after sorting
};

void swapStudents(Student &a, Student &b) {
    Student temp = a;
    a = b;
    b = temp;
}

void displayPass(Student arr[], int n, int pass) {
    cout << "After Pass " << pass << ": ";
    for (int i = 0; i < n; i++) {
        cout << "(" << arr[i].name << ", " << arr[i].prevMarks << ") ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of students in the class: ";
    cin >> n;

    Student s[50];

    cout << "\nEnter student details (name and previous year marks):\n";
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << " Name: ";
        cin >> s[i].name;
        cout << "Student " << i + 1 << " Previous Year Marks: ";
        cin >> s[i].prevMarks;
        s[i].rollNo = 0; // not assigned yet
    }

    cout << "\n--- Bubble Sort Process (Sorting by marks in DESCENDING order) ---\n";

    // Bubble sort based on prevMarks (descending: highest marks first)
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j].prevMarks < s[j + 1].prevMarks) {  // descending
                swapStudents(s[j], s[j + 1]);
                swapped = true;
            }
        }
        // Show array after each pass
        displayPass(s, n, i + 1);

        if (!swapped) { // optimization: stop if already sorted
            break;
        }
    }

    // Assign roll numbers as per rank
    for (int i = 0; i < n; i++) {
        s[i].rollNo = i + 1;  // topper gets 1, next gets 2, ...
    }

    cout << "\n--- Final Roll Number Assignment (Topper = Roll No. 1) ---\n";
    cout << "RollNo\tName\tMarks\n";
    for (int i = 0; i < n; i++) {
        cout << s[i].rollNo << "\t" << s[i].name << "\t" << s[i].prevMarks << endl;
    }

    return 0;
}
