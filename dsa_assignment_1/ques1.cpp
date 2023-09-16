#include<iostream>
using namespace std;

int main() {
  int size;
  cout<<"Enter size of array: ";
  cin>>size;
  int arr[size];
  int i;
  //CREATE
  for(i=0; i<size; i++){
    cout<<"Enter element "<<i+1<<": ";
    cin>>arr[i];
  }
  //DISPLAY
  cout<<"Your array is: ";
  for(i=0; i<size; i++){
    cout<<arr[i]<<" ";
  }
  cout<<'\n';
  //INSERT
  int arrc[size+1], num, index;
  for(i=0; i<size; i++){
    arrc[i]=arr[i];
  }
  cout<<"Enter index to insert new element: ";
  cin>>index;
  cout<<"Enter number to be inserted: ";
  cin>>num;
  for(i=size; i>index; i--){
    arrc[i]=arrc[i-1];
  }
  arrc[index]=num;
  cout<<"Your array is: ";
  for(i=0; i<size+1; i++){
    cout<<arrc[i]<<" ";
  }
  cout<<'\n';
  //DELETE+LINEAR SEARCH
  int num2, index2;
  cout<<"Enter number to be deleted: ";
  cin>>num2;
  for(i=0; i<=size; i++){
    if(arrc[i]==num2){
      index=i;
      break;
    } else{
      cout<<"Element not found! \n";
      break;
    }
  }
  for(i=index; i<size+1; i++){
    arrc[i]=arrc[i+1];
  }
  cout<<"Your array is: ";
  for(i=0; i<size; i++){
    cout<<arrc[i]<<" ";
  }

  return 0;
}