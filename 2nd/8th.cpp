#include <iostream>
using namespace std;

int countDistinct(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        bool isDuplicate = false;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate)
            count++;
    }
    return count;
}

int main() {
    int arr[] = {11, 23, 20, 37, 74, 48, 35, 23, 20, 37};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Total distinct elements: " << countDistinct(arr, n) << endl;
    return 0;
}
