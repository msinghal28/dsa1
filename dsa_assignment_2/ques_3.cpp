#include<iostream>
using namespace std;
int main (){
// let the array be such that it follows an A.P. sequence of which we dont know the common difference
int diff;
int arr[9]={2,4,8,10,12,14};
if(arr[2]-arr[1] == arr[3]-arr[2])
{
    diff=arr[2]-arr[1];
}
else{
    diff=arr[5]-arr[4];
}
int count=arr[0];
for(int i=0;i<9;i++)
{
    if(arr[i]!=count)
    {
        cout<<"one number is missing and that is "<<count<<" which should be at "<<(i+1)<<" position\n";
        break;
    }

    count=count+diff;
}

    return 0;
}