#include<iostream>
using namespace std;

int main (){

int a[]={4,6,9,2,3,6,1};
int n=sizeof(a)/sizeof(a[0]);
for(int i=0;i<n;i++)
{
    for(int j=0;j<n-1-i;j++)
    {
        if(a[j]>a[j+1])
        {
            int t=a[j];
            a[j]=a[j+1];
            a[j+1]=t;
        }
    }
}
for(int i=0;i<n;i++)
{
    cout<<a[i]<<" ";
}
    return 0;
}