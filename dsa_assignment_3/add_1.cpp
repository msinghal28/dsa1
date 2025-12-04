#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cout<<"Enter size: ";
    cin>>n;

    vector<int>A(n), ans(n);
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++) cin>>A[i];

    int st[100], top=-1;  // simple manual stack

    for(int i=0;i<n;i++){
        while(top!=-1 && st[top] >= A[i]) top--;
        ans[i] = (top==-1 ? -1 : st[top]);
        st[++top] = A[i];
    }

    cout<<"Nearest Smaller to Left: ";
    for(int x: ans) cout<<x<<" ";
    cout<<endl;
}
