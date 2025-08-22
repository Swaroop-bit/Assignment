#include <iostream>
#include <vector>
using namespace std;

void removeDuplicates(vector<int>& arr) {
    if (arr.size() <= 1) {
        return;
    }

    int uniqueCount = 1;
    for (size_t i = 1; i < arr.size(); i++) {
        bool isDuplicate = false;
        for (int j = 0; j < uniqueCount; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            arr[uniqueCount] = arr[i];
            uniqueCount++;
        }
    }
    arr.resize(uniqueCount);
}

void displayVector(const vector<int>& arr) {
    if (arr.empty()) {
        cout << "Vector is empty." << endl;
        return;
    }
    for (int element : arr) {
        cout << element << " ";
    }
    cout << endl;
}

int main() {
    vector<int> myVector = {4, 2, 5, 2, 8, 4, 9, 5};

    cout << "Original vector";
    displayVector(myVector);

    removeDuplicates(myVector);

    cout << "Vector after removing duplicates";
    displayVector(myVector);
    cout << "New size of the vector" << myVector.size() << endl;

    return 0;
}