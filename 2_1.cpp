// In Computer Engg. Dept. of VIT there are S.Y., T.Y., and B.Tech. students. 
// Assume that all these students are on ground for a function. 
// We need to identify a student of S.Y. div. (X) 
// whose name is "XYZ" and roll no. is "17". 
// Apply appropriate Searching method to identify the required student.
// | Operation         | Complexity                                 |
// | ----------------- | ------------------------------------------ |
// | **Linear Search** | **O(n)** (worst-case checks every student) |
// | **Space Used**    | **O(n)** to store student records          |

#include <iostream>
#include <string>
using namespace std;

struct Student {
    string year;
    string division;
    string name;
    int roll;
};

int main() {
    Student students[50];
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    // Input student data
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for student " << i + 1 << endl;
        cout << "Year (SY/TY/BTech): ";
        cin >> students[i].year;
        cout << "Division: ";
        cin >> students[i].division;
        cout << "Name: ";
        cin >> students[i].name;
        cout << "Roll No.: ";
        cin >> students[i].roll;
    }

    // Searching criteria
    string searchYear = "SY", searchDiv = "X", searchName = "XYZ";
    int searchRoll = 17;

    bool found = false;

    // Linear Search
    for (int i = 0; i < n; i++) {
        if (students[i].year == searchYear &&
            students[i].division == searchDiv &&
            students[i].name == searchName &&
            students[i].roll == searchRoll) {
            
            found = true;
            cout << "\n*** Student Found ***\n";
            cout << "Year: " << students[i].year << endl;
            cout << "Division: " << students[i].division << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Roll No.: " << students[i].roll << endl;
            break;
        }
    }

    if (!found)
        cout << "\nStudent NOT Found!" << endl;

    return 0;
}
