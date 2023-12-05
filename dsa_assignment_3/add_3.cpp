#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>A(n), ans(n);
    for(int i=0;i<n;i++) cin>>A[i];

    int st[100], top=-1;

    for(int i=n-1;i>=0;i--){
        while(top!=-1 && st[top] <= A[i]) top--;
        ans[i] = (top==-1 ? -1 : st[top]);
        st[++top] = A[i];
    }

    cout<<"Next Greater Elements: ";
    for(int x: ans) cout<<x<<" ";
    cout<<endl;
}
