// Develop a program to identify and efficiently store a sparse matrix using compact representation and 
// perform basic operations like display and simple transpose.
// Creating sparse from full matrix: O(rows × cols)
// Display full from sparse: O(rows × cols)
// Display sparse: O(nnz) (nnz = non-zero count)
// Simple transpose (simple method): O(cols × nnz) (in worst case)
// Space for sparse: O(nnz) vs full O(rows × cols)

#include <iostream>
using namespace std;

const int MAX_ROWS = 20;
const int MAX_COLS = 20;
const int MAX_TERMS = 400;   // max non-zero elements

// Triplet representation: (row, col, value)
struct Term {
    int row;
    int col;
    int value;
};

// Create sparse representation from full matrix
int createSparse(int mat[MAX_ROWS][MAX_COLS], int rows, int cols, Term sparse[MAX_TERMS]) {
    int k = 1; // index for sparse array (0 reserved for header)

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] != 0) {
                sparse[k].row = i;
                sparse[k].col = j;
                sparse[k].value = mat[i][j];
                k++;
            }
        }
    }

    // header
    sparse[0].row = rows;
    sparse[0].col = cols;
    sparse[0].value = k - 1;   // number of non-zero elements

    return k; // total terms used (including header)
}

// Display sparse matrix (triplet form)
void displaySparse(Term sparse[MAX_TERMS]) {
    int n = sparse[0].value;

    cout << "\nRow\tCol\tValue\n";
    for (int i = 0; i <= n; i++) {
        cout << sparse[i].row << "\t" << sparse[i].col << "\t" << sparse[i].value << endl;
    }
}

// Display full matrix from sparse form
void displayFullFromSparse(Term sparse[MAX_TERMS]) {
    int rows = sparse[0].row;
    int cols = sparse[0].col;
    int n = sparse[0].value;

    int k = 1; // index in sparse

    cout << "\nMatrix (" << rows << " x " << cols << "):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (k <= n && sparse[k].row == i && sparse[k].col == j) {
                cout << sparse[k].value << "\t";
                k++;
            } else {
                cout << "0\t";
            }
        }
        cout << endl;
    }
}

// Simple transpose of sparse matrix
void simpleTranspose(Term a[MAX_TERMS], Term b[MAX_TERMS]) {
    int n = a[0].value;   // number of non-zero terms
    int rows = a[0].row;
    int cols = a[0].col;

    b[0].row = cols;
    b[0].col = rows;
    b[0].value = n;

    if (n == 0) return;

    int k = 1;
    // For each column of original, scan all terms
    for (int col = 0; col < cols; col++) {
        for (int i = 1; i <= n; i++) {
            if (a[i].col == col) {
                b[k].row = a[i].col;   // swapped
                b[k].col = a[i].row;
                b[k].value = a[i].value;
                k++;
            }
        }
    }
}

int main() {
    int rows, cols;
    int mat[MAX_ROWS][MAX_COLS];
    Term sparse[MAX_TERMS], transposed[MAX_TERMS];
    int choice;
    bool hasSparse = false;

    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    if (rows > MAX_ROWS || cols > MAX_COLS || rows <= 0 || cols <= 0) {
        cout << "Invalid size.\n";
        return 0;
    }

    cout << "\nEnter matrix elements (" << rows << " x " << cols << "):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> mat[i][j];
        }
    }

    // Build sparse once
    createSparse(mat, rows, cols, sparse);
    hasSparse = true;

    while (true) {
        cout << "\n--- Sparse Matrix Operations ---\n";
        cout << "1. Display original matrix\n";
        cout << "2. Display sparse representation\n";
        cout << "3. Simple transpose (sparse) and display\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            displayFullFromSparse(sparse);
        } 
        else if (choice == 2) {
            displaySparse(sparse);
        } 
        else if (choice == 3) {
            if (!hasSparse) {
                cout << "Sparse matrix not created.\n";
            } else {
                simpleTranspose(sparse, transposed);
                cout << "\nTransposed Sparse Representation:\n";
                displaySparse(transposed);
                cout << "\nTransposed Full Matrix:\n";
                displayFullFromSparse(transposed);
            }
        } 
        else if (choice == 4) {
            cout << "Exiting...\n";
            break;
        } 
        else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
