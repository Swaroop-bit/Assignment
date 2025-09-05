#include <iostream>
using namespace std;

// Diagonal Matrix: Only store elements where row == col
class DiagonalMatrix {
    int *data;
    int size;
public:
    DiagonalMatrix(int n) {
        size = n;
        data = new int[n];
    }

    void set(int row, int col, int value) {
        if (row == col) data[row - 1] = value;
    }

    int get(int row, int col) {
        return (row == col) ? data[row - 1] : 0;
    }

    void show() {
        cout << "\nDiagonal Matrix:\n";
        for (int i = 1; i <= size; i++) {
            for (int j = 1; j <= size; j++)
                cout << get(i, j) << " ";
            cout << endl;
        }
    }
};

// Tri-diagonal Matrix: Store main diagonal + diagonals just above and below
class TriDiagonalMatrix {
    int *data;
    int size;
public:
    TriDiagonalMatrix(int n) {
        size = n;
        data = new int[3 * n - 2];
    }

    void set(int row, int col, int value) {
        if (row - col == 1) data[row - 2] = value;
        else if (row == col) data[size - 1 + row - 1] = value;
        else if (row - col == -1) data[2 * size - 1 + row - 1] = value;
    }

    int get(int row, int col) {
        if (row - col == 1) return data[row - 2];
        else if (row == col) return data[size - 1 + row - 1];
        else if (row - col == -1) return data[2 * size - 1 + row - 1];
        else return 0;
    }

    void show() {
        cout << "\nTri-diagonal Matrix:\n";
        for (int i = 1; i <= size; i++) {
            for (int j = 1; j <= size; j++)
                cout << get(i, j) << " ";
            cout << endl;
        }
    }
};

// Lower Triangular Matrix: Store only when row >= col
class LowerTriangularMatrix {
    int *data;
    int size;
public:
    LowerTriangularMatrix(int n) {
        size = n;
        data = new int[n * (n + 1) / 2];
    }

    void set(int row, int col, int value) {
        if (row >= col)
            data[row * (row - 1) / 2 + col - 1] = value;
    }

    int get(int row, int col) {
        return (row >= col) ? data[row * (row - 1) / 2 + col - 1] : 0;
    }

    void show() {
        cout << "\nLower Triangular Matrix:\n";
        for (int i = 1; i <= size; i++) {
            for (int j = 1; j <= size; j++)
                cout << get(i, j) << " ";
            cout << endl;
        }
    }
};

// Upper Triangular Matrix: Store only when row <= col
class UpperTriangularMatrix {
    int *data;
    int size;
public:
    UpperTriangularMatrix(int n) {
        size = n;
        data = new int[n * (n + 1) / 2];
    }

    void set(int row, int col, int value) {
        if (row <= col)
            data[row * size - (row - 1) * row / 2 + col - row] = value;
    }

    int get(int row, int col) {
        return (row <= col) ? data[row * size - (row - 1) * row / 2 + col - row] : 0;
    }

    void show() {
        cout << "\nUpper Triangular Matrix:\n";
        for (int i = 1; i <= size; i++) {
            for (int j = 1; j <= size; j++)
                cout << get(i, j) << " ";
            cout << endl;
        }
    }
};

// Symmetric Matrix: A[i][j] == A[j][i], so store only lower triangle
class SymmetricMatrix {
    int *data;
    int size;
public:
    SymmetricMatrix(int n) {
        size = n;
        data = new int[n * (n + 1) / 2];
    }

    void set(int row, int col, int value) {
        if (row >= col)
            data[row * (row - 1) / 2 + col - 1] = value;
        else
            data[col * (col - 1) / 2 + row - 1] = value;
    }

    int get(int row, int col) {
        return (row >= col)
            ? data[row * (row - 1) / 2 + col - 1]
            : data[col * (col - 1) / 2 + row - 1];
    }

    void show() {
        cout << "\nSymmetric Matrix:\n";
        for (int i = 1; i <= size; i++) {
            for (int j = 1; j <= size; j++)
                cout << get(i, j) << " ";
            cout << endl;
        }
    }
};

int main() {
    int n = 4;

    DiagonalMatrix diag(n);
    diag.set(1, 1, 5); diag.set(2, 2, 8); diag.set(3, 3, 3); diag.set(4, 4, 6);
    diag.show();

    TriDiagonalMatrix tri(n);
    tri.set(1, 1, 4); tri.set(1, 2, 5);
    tri.set(2, 1, 6); tri.set(2, 2, 7); tri.set(2, 3, 8);
    tri.set(3, 2, 9); tri.set(3, 3, 1); tri.set(3, 4, 2);
    tri.set(4, 3, 3); tri.set(4, 4, 4);
    tri.show();

    LowerTriangularMatrix lower(n);
    int val = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            lower.set(i, j, val++);
    lower.show();

    UpperTriangularMatrix upper(n);
    val = 1;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            upper.set(i, j, val++);
    upper.show();

    SymmetricMatrix sym(n);
    val = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            sym.set(i, j, val++);
    sym.show();

    return 0;
}
