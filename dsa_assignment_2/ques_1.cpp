#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int num) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == num) 
            return mid;
        else if (arr[mid] < num) 
            low = mid + 1;
        else 
            high = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {10,20,30,40,50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int num = 40;
    int result = binarySearch(arr, n, num);
    if(result==-1){cout<<"not found";}
    else{cout<<"number "<<num<<" found at "<< result;}
    return 0;
}