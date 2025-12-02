// Implement basic string operations such as length calculation, copy, reverse, and 
// concatenation using character single dimensional arrays without using built-in string library functions.
#include <iostream>
using namespace std;

// Function to calculate length of string
int stringLength(char str[]) {
    int count = 0;
    while (str[count] != '\0')
        count++;
    return count;
}

// Function to copy one string to another
void stringCopy(char source[], char destination[]) {
    int i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
}

// Function to reverse string
void stringReverse(char str[], char rev[]) {
    int len = stringLength(str);
    for (int i = 0; i < len; i++) {
        rev[i] = str[len - 1 - i];
    }
    rev[len] = '\0';
}

// Function to concatenate two strings
void stringConcat(char str1[], char str2[], char result[]) {
    int i = 0, j = 0;

    // Copy first string
    while (str1[i] != '\0') {
        result[i] = str1[i];
        i++;
    }

    // Append second string
    while (str2[j] != '\0') {
        result[i] = str2[j];
        i++;
        j++;
    }

    result[i] = '\0';
}

int main() {
    char str1[50], str2[50], temp[50], rev[50], concat[100];
    int choice;

    cout << "Enter first string: ";
    cin >> str1;

    cout << "Enter second string: ";
    cin >> str2;

    while (true) {
        cout << "\n--- String Operations Menu ---\n";
        cout << "1. Length of String 1\n";
        cout << "2. Copy String 1 to Another\n";
        cout << "3. Reverse String 1\n";
        cout << "4. Concatenate String 1 and String 2\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Length of String 1: " << stringLength(str1) << endl;
            break;

        case 2:
            stringCopy(str1, temp);
            cout << "Copied String: " << temp << endl;
            break;

        case 3:
            stringReverse(str1, rev);
            cout << "Reversed String: " << rev << endl;
            break;

        case 4:
            stringConcat(str1, str2, concat);
            cout << "Concatenated Result: " << concat << endl;
            break;

        case 5:
            cout << "Exiting Program.\n";
            return 0;

        default:
            cout << "Invalid choice.\n";
        }
    }
}
