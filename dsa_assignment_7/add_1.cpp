#include<iostream>
using namespace std;

void countingSort(int arr[], int n) {
    // Find max element
    int mx = arr[0];
    for(int i = 1; i < n; i++)
        if(arr[i] > mx)
            mx = arr[i];

    // Create count array
    int count[mx+1] = {0};

    // Store frequency
    for(int i = 0; i < n; i++)
        count[arr[i]]++;

    // Build sorted array
    int index = 0;
    for(int i = 0; i <= mx; i++) {
        while(count[i]--) {
            arr[index++] = i;
        }
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for(int i=0; i<n; i++) cin >> arr[i];

    countingSort(arr, n);

    cout << "Sorted array: ";
    for(int i=0; i<n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
