#include<iostream>
using namespace std;

int main() {
  int arr1[2][3]={{1,2,3},{4,5,6}};
  int arr2[3][2]={{1,2},{3,4},{5,6}};
  int r1= sizeof(arr1)/sizeof(arr1[0]);
  int c1= sizeof(arr1[0])/sizeof(arr1[0][0]);
  int r2= sizeof(arr2)/sizeof(arr2[0]);
  int c2= sizeof(arr2[0])/sizeof(arr2[0][0]);
  int i, j, m;
  int multiply[r1][c2]= {0};

  if(c1!=r2){
    cout<<"Multiplication not possible!\n";
  }
  for(i=0; i<r1; i++){
    for(m=0; m<c2; m++){
      for(j=0; j<c1; j++){
        multiply[i][m]+=arr1[i][j]*arr2[j][m];
      }
    }
  }
  for(i=0; i<r1; i++){
    for(j=0; j<c2; j++){
      cout<<multiply[i][j]<<" ";
    }
    cout<<'\n';
  }

  return 0;
}