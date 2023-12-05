#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>T(n), ans(n,0);
    for(int i=0;i<n;i++) cin>>T[i];

    int st[100], top=-1; // will store indices

    for(int i=0;i<n;i++){
        while(top!=-1 && T[i] > T[st[top]]){
            int idx = st[top--];
            ans[idx] = i - idx;
        }
        st[++top] = i;
    }

    cout<<"Days to wait: ";
    for(int x: ans) cout<<x<<" ";
    cout<<endl;
}
