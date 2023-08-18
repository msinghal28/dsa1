#include<iostream>
using namespace std;

int main() {
  int arr[]={1, 1,1,66, 5, 3, 3, 3, 5, 16};
  int size= sizeof(arr)/sizeof(arr[0]);
  int i, j, sizex=0, newarr[sizex];
  bool match;
  for(i=0; i<size; i++){
    match=false;
    for(j=0; j<i; j++){
      if(arr[j]==arr[i]){
        match=true;
        break;
      }
    }
    if(match==false){
      newarr[sizex]=arr[i];
      sizex++;
    }
  }
  for(i=0; i<sizex; i++){
    cout<<newarr[i]<<" ";
  }

  return 0;
}