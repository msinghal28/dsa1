#include<iostream>
using namespace std;

int main() {
  int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
  int i, j;
  int column= sizeof(arr[0])/sizeof(arr[0][0]);
  int row= sizeof(arr)/sizeof(arr[0]);
  int sumr[row]={0}, sumc[column]={0};
  //sum of rows
  for(i=0; i<row; i++){
    for(j=0; j<column; j++){
      sumr[i]=sumr[i]+arr[i][j];
    }
  }
  //sum of columns
  for(i=0; i<column; i++){
    for(j=0; j<row; j++){
      sumc[i]=sumc[i]+arr[j][i];
    }
  }
  cout<<"\n Sum of each row is given as: \n";
  for(i=0; i<row; i++){
    cout<<sumr[i]<<" ";
  }
  cout<<"\n Sum of each column is given as: \n";
  for(i=0; i<column; i++){
    cout<<sumc[i]<<" ";
  }

  return 0;
}