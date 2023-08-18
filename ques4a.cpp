#include<iostream>
using namespace std;

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int size = sizeof(arr)/sizeof(arr[0]);
  int reverse[size];
  for(int i=0; i<size; i++){
    reverse[i]=arr[size-i-1];
    cout<<reverse[i]<<" ";
  }

  return 0;
}