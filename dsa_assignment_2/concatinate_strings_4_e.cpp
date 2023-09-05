#include <iostream>
using namespace std;
int main() {
    char arr[100];
    cout << "enter uppercase: ";
    cin.getline(arr, 100);
    int i = 0;
    while (arr[i] != '\0') {
        if (arr[i] >= 'A' && arr[i] <= 'Z') {
            arr[i] = arr[i] + 32;   
        }
        i++;
    }

    cout << "In lowercase: " << arr << endl;
    return 0;
}
