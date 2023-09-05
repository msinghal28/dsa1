#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
   int arr[] = {1, 2, 2, 3, 4, 2,2,5,2,1,1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int count = 0;
    for(int i=0; i<n; i++) {
        bool found = false;
        for(int j=0; j<i; j++) {
            if(arr[i] == arr[j]) {
                found = true;
                break;
            }
        }
        if(!found) count++;
    }
    cout << "Distinct count: " << count;
    return 0;
}