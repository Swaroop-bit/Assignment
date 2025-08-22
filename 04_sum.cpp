#include <iostream>

using namespace std;

void findRowAndColumnSums(int matrix[3][3], int rows, int cols) {
    if (rows <= 0 || cols <= 0) {
        cout << "Matrix is empty." << endl;
        return;
    }

    cout << "Row Sums:" << endl;
    for (int i = 0; i < rows; ++i) {
        int sum = 0;
        for (int j = 0; j < cols; ++j) {
            sum += matrix[i][j];
        }
        cout << "Row " << i + 1 << ": " << sum << endl;
    }

    cout << "\nColumn Sums:" << endl;
    for (int j = 0; j < cols; ++j) {
        int sum = 0;
        for (int i = 0; i < rows; ++i) {
            sum += matrix[i][j];
        }
        cout << "Column " << j + 1 << ": " << sum << endl;
    }
}

int main() {
    int myMatrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    cout << "Matrix:" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << myMatrix[i][j] << "\t";
        }
        cout << endl;
    }

    findRowAndColumnSums(myMatrix, 3, 3);

    return 0;
}
