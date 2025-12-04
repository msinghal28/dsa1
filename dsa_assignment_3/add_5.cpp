#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int>A(n), B;
    for(int i=0;i<n;i++) cin>>A[i];

    int S[200], top=-1;

    // Push all elements from A to stack S sorted
    for(int x : A){
        while(top!=-1 && S[top] > x){
            B.push_back(S[top--]);
        }
        S[++top] = x;
    }

    // Push remaining stack items to B
    while(top!=-1) B.push_back(S[top--]);

    // B is descending — reverse for ascending
    reverse(B.begin(), B.end());

    cout<<"Sorted result: ";
    for(int x: B) cout<<x<<" ";
    cout<<endl;
}
