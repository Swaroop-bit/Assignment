#include <iostream>
using namespace std;

// Transpose function: input is a 2D array of triplets [row, col, value]
void transposeSparse(int input[][3], int output[][3], int count) {
    for (int i = 0; i < count; i++) {
        output[i][0] = input[i][1]; // row becomes col
        output[i][1] = input[i][0]; // col becomes row
        output[i][2] = input[i][2]; // value stays the same
    }
}

// Display function without string parameter
void displaySparse(int mat[][3], int count, int type) {
    if (type == 0)
        cout << "\nOriginal Matrix (Triplet Format):\n";
    else if (type == 1)
        cout << "\nTransposed Matrix (Triplet Format):\n";

    for (int i = 0; i < count; i++) {
        cout << "[" << mat[i][0] << ", " << mat[i][1] << "] = " << mat[i][2] << endl;
    }
}

int main() {
    // Original sparse matrix in triplet form: [row, col, value]
    int original[][3] = {
        {0, 0, 5},
        {0, 2, 8},
        {1, 1, 3},
        {2, 0, 6}
    };
    int count = sizeof(original) / sizeof(original[0]);

    int transposed[10][3]; // Transposed matrix

    transposeSparse(original, transposed, count);

    displaySparse(original, count, 0);   // 0 = original
    displaySparse(transposed, count, 1); // 1 = transposed

    return 0;
}
