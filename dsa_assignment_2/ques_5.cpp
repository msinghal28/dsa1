#include <iostream>
using namespace std;

// Diagonal Matrix (only diagonal elements are non-zero)
class DiagonalMatrix {
    int *arr;
    int n;
public:
    DiagonalMatrix(int size) {
        n = size;
        arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = 0;
    }
    void set(int i, int j, int val) {
        if (i == j) arr[i] = val;
    }
    int get(int i, int j) {
        if (i == j) return arr[i];
        return 0;
    }
    void display() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

// Lower Triangular Matrix
class LowerTriangularMatrix {
    int *arr;
    int n;
public:
    LowerTriangularMatrix(int size) {
        n = size;
        arr = new int[n * (n + 1) / 2];
        for (int i = 0; i < n * (n + 1) / 2; i++) arr[i] = 0;
    }
    void set(int i, int j, int val) {
        if (i >= j) {
            int index = i * (i + 1) / 2 + j;
            arr[index] = val;
        }
    }
    int get(int i, int j) {
        if (i >= j) {
            int index = i * (i + 1) / 2 + j;
            return arr[index];
        }
        return 0;
    }
    void display() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

// Upper Triangular Matrix
class UpperTriangularMatrix {
    int *arr;
    int n;
public:
    UpperTriangularMatrix(int size) {
        n = size;
        arr = new int[n * (n + 1) / 2];
        for (int i = 0; i < n * (n + 1) / 2; i++) arr[i] = 0;
    }
    void set(int i, int j, int val) {
        if (i <= j) {
            int index = j * (j + 1) / 2 + i;
            arr[index] = val;
        }
    }
    int get(int i, int j) {
        if (i <= j) {
            int index = j * (j + 1) / 2 + i;
            return arr[index];
        }
        return 0;
    }
    void display() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n = 4;
    cout << "Diagonal Matrix:\n";
    DiagonalMatrix d(n);
    d.set(2,4,5); d.set(6,7,8); d.set(2,8,9); d.set(4,3,7);
    d.display();

    cout << "\nLower Triangular Matrix:\n";
    LowerTriangularMatrix l(n);
    l.set(1,0,2); l.set(2,1,3); l.set(3,0,8); l.set(2,3,8);
    l.display();

    cout << "\nUpper Triangular Matrix:\n";
    UpperTriangularMatrix u(n);
    u.set(0,1,6); u.set(0,2,7); u.set(1,3,9); u.set(2,3,0);
    u.display();

    return 0;
}
