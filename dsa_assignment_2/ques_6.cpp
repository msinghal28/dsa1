#include <iostream>
using namespace std;

// Structure to store a single non-zero element (triplet form)
struct Entry {
    int row, col, val;
};

// Function to print sparse matrix in triplet form
void showSparse(Entry arr[], int total) {
    cout << "Row  Col  Value\n";
    for (int i = 0; i < total; i++) {
        cout << arr[i].row << "    " 
             << arr[i].col << "    " 
             << arr[i].val << "\n";
    }
}

// Function to find transpose
void transpose(Entry A[], Entry B[], int terms, int r, int c) {
    int k = 0;
    for (int j = 0; j < c; j++) {
        for (int i = 0; i < terms; i++) {
            if (A[i].col == j) {
                B[k].row = A[i].col;
                B[k].col = A[i].row;
                B[k].val = A[i].val;
                k++;
            }
        }
    }
}

// Function to add two sparse matrices
int addSparse(Entry A[], int t1, Entry B[], int t2, Entry C[]) {
    int i = 0, j = 0, k = 0;
    while (i < t1 && j < t2) {
        if (A[i].row < B[j].row || 
           (A[i].row == B[j].row && A[i].col < B[j].col)) {
            C[k++] = A[i++];
        } else if (B[j].row < A[i].row || 
                  (B[j].row == A[i].row && B[j].col < A[i].col)) {
            C[k++] = B[j++];
        } else {
            C[k] = A[i];
            C[k].val = A[i].val + B[j].val;
            k++; i++; j++;
        }
    }
    while (i < t1) C[k++] = A[i++];
    while (j < t2) C[k++] = B[j++];
    return k;
}

// Function to multiply two sparse matrices
int multiplySparse(Entry A[], int t1, Entry B[], int t2, Entry C[], 
                   int rA, int cA, int cB) {
    int k = 0;
    for (int i = 0; i < rA; i++) {
        for (int j = 0; j < cB; j++) {
            int sum = 0;
            for (int p = 0; p < t1; p++) {
                if (A[p].row == i) {
                    for (int q = 0; q < t2; q++) {
                        if (B[q].row == A[p].col && B[q].col == j) {
                            sum += A[p].val * B[q].val;
                        }
                    }
                }
            }
            if (sum != 0) {
                C[k].row = i;
                C[k].col = j;
                C[k].val = sum;
                k++;
            }
        }
    }
    return k;
}

int main() {
    // Matrix A in triplet form
    Entry A[6] = { {0,2,4}, {0,4,3}, {1,1,5}, {2,0,2}, {3,2,7}, {4,3,6} };
    int t1 = 6, rowsA = 5, colsA = 5;
    cout << "Matrix A (triplet form):\n";
    showSparse(A, t1);

    // Matrix B in triplet form
    Entry B[5] = { {0,1,8}, {1,4,9}, {2,2,3}, {3,0,1}, {4,4,2} };
    int t2 = 5, rowsB = 5, colsB = 5;
    cout << "\nMatrix B (triplet form):\n";
    showSparse(B, t2);

    // Transpose of A
    Entry T[12];
    transpose(A, T, t1, rowsA, colsA);
    cout << "\nTranspose of A:\n";
    showSparse(T, t1);

    // Addition
    Entry C[20];
    int t3 = addSparse(A, t1, B, t2, C);
    cout << "\nA + B (Result):\n";
    showSparse(C, t3);

    // Multiplication
    Entry M[25];
    int t4 = multiplySparse(A, t1, B, t2, M, rowsA, colsA, colsB);
    cout << "\nA * B (Result):\n";
    showSparse(M, t4);

    return 0;
}
