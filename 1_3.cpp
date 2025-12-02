// Implement matrix multiplication and analyse its performance using row-major
// Time complexity: O(n³)
// Space complexity: O(n²)
#include <iostream>
using namespace std;

const int MAX = 20;   // maximum size of rows/columns

int main() {
    int r1, c1, r2, c2;
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

    cout << "Enter rows and columns of matrix A (r1 c1): ";
    cin >> r1 >> c1;

    cout << "Enter rows and columns of matrix B (r2 c2): ";
    cin >> r2 >> c2;

    if (c1 != r2) {
        cout << "Matrix multiplication not possible. (c1 must equal r2)\n";
        return 0;
    }

    cout << "\nEnter elements of matrix A (" << r1 << "x" << c1 << "):\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cin >> A[i][j];
        }
    }

    cout << "\nEnter elements of matrix B (" << r2 << "x" << c2 << "):\n";
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            cin >> B[i][j];
        }
    }

    // Initialize result matrix C with 0
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            C[i][j] = 0;
        }
    }

    // ---------------- ROW-MAJOR MATRIX MULTIPLICATION ----------------
    // C[i][j] = sum over k of A[i][k] * B[k][j]
    for (int i = 0; i < r1; i++) {          // loop over rows of A
        for (int j = 0; j < c2; j++) {      // loop over cols of B
            int sum = 0;
            for (int k = 0; k < c1; k++) {  // inner dimension
                sum += A[i][k] * B[k][j];   // row of A, column of B
            }
            C[i][j] = sum;
        }
    }

    // ---------------- DISPLAY RESULT ----------------
    cout << "\nResultant matrix C (" << r1 << "x" << c2 << "):\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
