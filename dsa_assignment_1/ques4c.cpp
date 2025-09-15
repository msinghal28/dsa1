#include<iostream>
using namespace std;

int main() {
  //c
  int arr[2][3]= {{1,2,3}, {4,5,6}};
  int row= sizeof(arr)/sizeof(arr[0]);
  int column= sizeof(arr[0])/sizeof(arr[0][0]);
  int temp[column][row]= {0};
  int i, j;
  for(i=0; i<row; i++){
    for(j=0; j<column; j++){
      temp[j][i]=arr[i][j];
    }
  }
  for(i=0; i<column; i++){
    for(j=0; j<row; j++){
      cout<<temp[i][j]<<" ";
    }
    cout<<'\n';
  }

  return 0;
}