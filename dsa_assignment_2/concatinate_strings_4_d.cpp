#include <iostream>
using namespace std;

int main() {
    char arr[100];
    cout << "Enter a word: ";
    cin >> arr;
    int n = 0;
    while (arr[n] != '\0') {
        n++;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "sorted string: " << arr << endl;
    return 0;
}
