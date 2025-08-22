#include <iostream>
#include <vector>

using namespace std;

void displayMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }
}

void displayArray(const vector<int>& arr) {
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

void reverseArray(vector<int>& arr) {
    int start = 0;
    int end = arr.size() - 1;
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

vector<vector<int>> matrixMultiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int rowsA = A.size();
    int colsA = A[0].size();
    int rowsB = B.size();
    int colsB = B[0].size();

    if (colsA != rowsB) {
        cout << "Error: Matrices cannot be multiplied. Incompatible dimensions." << endl;
        return {};
    }

    vector<vector<int>> result(rowsA, vector<int>(colsB, 0));

    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            for (int k = 0; k < colsA; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

vector<vector<int>> transposeMatrix(const vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> transposed(cols, vector<int>(rows));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }
    return transposed;
}

int main() {
    cout << "--- Array Reversal ---" << endl;
    vector<int> myArray = {1, 2, 3, 4, 5};
    cout << "Original array: ";
    displayArray(myArray);
    
    reverseArray(myArray);
    cout << "Reversed array: ";
    displayArray(myArray);

    cout << "\n--- Matrix Multiplication ---" << endl;
    vector<vector<int>> matrixA = {{1, 2, 3}, {4, 5, 6}};
    vector<vector<int>> matrixB = {{7, 8}, {9, 10}, {11, 12}};

    cout << "Matrix A:" << endl;
    displayMatrix(matrixA);
    cout << "\nMatrix B:" << endl;
    displayMatrix(matrixB);

    vector<vector<int>> productMatrix = matrixMultiply(matrixA, matrixB);
    if (!productMatrix.empty()) {
        cout << "\nResult of A * B:" << endl;
        displayMatrix(productMatrix);
    }

    cout << "\n--- Matrix Transpose ---" << endl;
    vector<vector<int>> originalMatrix = {{1, 2, 3}, {4, 5, 6}};
    
    cout << "Original Matrix:" << endl;
    displayMatrix(originalMatrix);

    vector<vector<int>> transposedMatrix = transposeMatrix(originalMatrix);
    cout << "\nTransposed Matrix:" << endl;
    displayMatrix(transposedMatrix);

    return 0;
}
