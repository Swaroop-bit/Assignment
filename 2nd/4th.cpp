#include <iostream>
using namespace std;

void concatenateStrings(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0') i++;
    int j = 0;
    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++; j++;
    }
    str1[i] = '\0';
    cout << "Concatenated string: " << str1 << endl;
}

void reverseString(char str[]) {
    int len = 0;
    while (str[len] != '\0') len++;
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    cout << "Reversed string: " << str << endl;
}

void deleteVowels(char str[]) {
    char result[100];
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' &&
            c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U') {
            result[j++] = c;
        }
    }
    result[j] = '\0';
    cout << "String without vowels: " << result << endl;
}

void sortStrings(char arr[][100], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int k = 0;
            while (arr[i][k] == arr[j][k] && arr[i][k] != '\0') k++;
            if (arr[i][k] > arr[j][k]) {
                char temp[100];
                int m = 0;
                while (arr[i][m] != '\0') {
                    temp[m] = arr[i][m];
                    m++;
                }
                temp[m] = '\0';

                m = 0;
                while (arr[j][m] != '\0') {
                    arr[i][m] = arr[j][m];
                    m++;
                }
                arr[i][m] = '\0';

                m = 0;
                while (temp[m] != '\0') {
                    arr[j][m] = temp[m];
                    m++;
                }
                arr[j][m] = '\0';
            }
        }
    }

    cout << "Sorted strings:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
}

void toLowercase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
    }
    cout << "Lowercase string: " << str << endl;
}

int main() {
    char str1[100] = "Hello ";
    char str2[100] = "World!";
    concatenateStrings(str1, str2);

    char str3[100] = "DataStructures";
    reverseString(str3);

    char str4[100] = "Beautiful";
    deleteVowels(str4);

    char strArr[5][100] = {"Banana", "Apple", "Mango", "Cherry", "Peach"};
    sortStrings(strArr, 5);

    char str5[100] = "UPPERCASE";
    toLowercase(str5);

    return 0;
}
