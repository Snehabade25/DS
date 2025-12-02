// Write a program to construct and verify a magic square of order 'n' (for both even & odd) 
// such that all rows, columns, and diagonals sum to the same value.
#include <iostream>
using namespace std;

#define MAX 20

// Function to initialize matrix with 0
void initSquare(int square[MAX][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            square[i][j] = 0;
}

// ---------------- ODD ORDER MAGIC SQUARE (Siamese Method) ----------------
void generateOdd(int square[MAX][MAX], int n) {
    int num = 1;
    int i = 0;
    int j = n / 2;

    while (num <= n * n) {
        square[i][j] = num;
        num++;

        int new_i = (i - 1 + n) % n;
        int new_j = (j + 1) % n;

        if (square[new_i][new_j] != 0) {
            i = (i + 1) % n;
        } else {
            i = new_i;
            j = new_j;
        }
    }
}

// ------------ DOUBLY EVEN MAGIC SQUARE (n % 4 == 0) ------------
void generateDoublyEven(int square[MAX][MAX], int n) {
    int num = 1;

    // Fill with numbers from 1 to n^2
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            square[i][j] = num;
            num++;
        }
    }

    // Replace certain cells with (n*n + 1 - value)
    int N2 = n * n + 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Main pattern for doubly even magic square
            if ((i % 4 == 0 || i % 4 == 3) && (j % 4 == 0 || j % 4 == 3)) {
                square[i][j] = N2 - square[i][j];
            } else if ((i % 4 == 1 || i % 4 == 2) && (j % 4 == 1 || j % 4 == 2)) {
                square[i][j] = N2 - square[i][j];
            }
        }
    }
}

// ---------------- VERIFY MAGIC SQUARE ----------------
bool verifyMagicSquare(int square[MAX][MAX], int n) {
    if (n <= 0) return false;

    int magicSum = n * (n * n + 1) / 2;

    // Check rows
    for (int i = 0; i < n; i++) {
        int rowSum = 0;
        for (int j = 0; j < n; j++)
            rowSum += square[i][j];

        if (rowSum != magicSum)
            return false;
    }

    // Check columns
    for (int j = 0; j < n; j++) {
        int colSum = 0;
        for (int i = 0; i < n; i++)
            colSum += square[i][j];

        if (colSum != magicSum)
            return false;
    }

    // Check main diagonal
    int diag1 = 0;
    for (int i = 0; i < n; i++)
        diag1 += square[i][i];

    if (diag1 != magicSum)
        return false;

    // Check secondary diagonal
    int diag2 = 0;
    for (int i = 0; i < n; i++)
        diag2 += square[i][n - 1 - i];

    if (diag2 != magicSum)
        return false;

    return true;
}

// ---------------- DISPLAY SQUARE ----------------
void displaySquare(int square[MAX][MAX], int n) {
    cout << "\nMagic Square of order " << n << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << square[i][j] << "\t";
        }
        cout << endl;
    }
}

// ---------------- MAIN FUNCTION ----------------
int main() {
    int n;
    int square[MAX][MAX];

    cout << "Enter order of magic square (n): ";
    cin >> n;

    if (n <= 0 || n > MAX) {
        cout << "Invalid order. Please enter n between 1 and " << MAX << ".\n";
        return 0;
    }

    initSquare(square, n);

    if (n % 2 == 1) {
        // Odd order magic square
        generateOdd(square, n);
    } else if (n % 4 == 0) {
        // Doubly even magic square
        generateDoublyEven(square, n);
    } else {
        // Singly even (like 6, 10, 14...) – not implemented in this simple version
        cout << "Singly even order (like 6, 10, 14) magic square "
             << "is not implemented in this simple program.\n";
        return 0;
    }

    displaySquare(square, n);

    if (verifyMagicSquare(square, n)) {
        int magicSum = n * (n * n + 1) / 2;
        cout << "\nVerification successful! It is a magic square.\n";
        cout << "Each row/column/diagonal sums to: " << magicSum << endl;
    } else {
        cout << "\nVerification failed. It is NOT a magic square.\n";
    }

    return 0;
}
