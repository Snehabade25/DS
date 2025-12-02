// Develop a program to compute the fast transpose of a sparse matrix 
// using its compact (triplet) representation efficiently.
// r = number of rows
// c = number of columns
// t = number of non-zero elements
// Creating sparse rep from full matrix:
// Time: O(r * c)
// Extra space (sparse array): O(t)
// Fast transpose (triplet → transposed triplet):
// Time: O(c + t)
// One pass to count terms per column → O(t)
// One pass to compute starting positions → O(c)
// One pass to place all terms in result → O(t)
// Extra space: O(c + t) (arrays rowTerms, startingPos, and transposed triplets)

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

    // header term
    sparse[0].row = rows;
    sparse[0].col = cols;
    sparse[0].value = k - 1;   // number of non-zero elements

    return k; // total terms including header
}

// Display sparse matrix (triplet form)
void displaySparse(Term sparse[MAX_TERMS]) {
    int n = sparse[0].value;
    cout << "\nRow\tCol\tValue\n";
    for (int i = 0; i <= n; i++) {
        cout << sparse[i].row << "\t" << sparse[i].col << "\t" << sparse[i].value << endl;
    }
}

// Fast transpose of sparse matrix (triplet form)
void fastTranspose(Term a[MAX_TERMS], Term b[MAX_TERMS]) {
    int numRows = a[0].row;
    int numCols = a[0].col;
    int numTerms = a[0].value;

    b[0].row = numCols;
    b[0].col = numRows;
    b[0].value = numTerms;

    if (numTerms == 0) return;

    int rowTerms[MAX_COLS];     // how many terms in each column of a
    int startingPos[MAX_COLS];  // starting position of each column in b

    // 1. Initialize rowTerms to 0
    for (int i = 0; i < numCols; i++)
        rowTerms[i] = 0;

    // 2. Count number of terms in each column of a
    for (int i = 1; i <= numTerms; i++)
        rowTerms[a[i].col]++;

    // 3. Compute starting positions for each column in b
    startingPos[0] = 1;  // first term of first column goes at index 1
    for (int i = 1; i < numCols; i++)
        startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];

    // 4. Place terms in b at correct positions
    for (int i = 1; i <= numTerms; i++) {
        int col = a[i].col;
        int pos = startingPos[col];

        b[pos].row = a[i].col;    // swap row and col
        b[pos].col = a[i].row;
        b[pos].value = a[i].value;

        startingPos[col]++;       // next term of this column will go to next slot
    }
}

int main() {
    int rows, cols;
    int mat[MAX_ROWS][MAX_COLS];
    Term sparse[MAX_TERMS], transposed[MAX_TERMS];

    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    if (rows <= 0 || cols <= 0 || rows > MAX_ROWS || cols > MAX_COLS) {
        cout << "Invalid matrix size.\n";
        return 0;
    }

    cout << "\nEnter matrix elements (" << rows << " x " << cols << "):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> mat[i][j];
        }
    }

    // Create sparse representation
    createSparse(mat, rows, cols, sparse);

    cout << "\nSparse representation of original matrix:\n";
    displaySparse(sparse);

    // Fast transpose
    fastTranspose(sparse, transposed);

    cout << "\nSparse representation after fast transpose:\n";
    displaySparse(transposed);

    return 0;
}
