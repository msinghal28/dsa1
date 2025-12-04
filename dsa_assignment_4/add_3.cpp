#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int main() {
    queue<int> q;
    stack<int> st;

    int n, x;
    cout<<"Enter n: ";
    cin>>n;

    cout<<"Enter queue elements: ";
    for(int i=0; i<n; i++){
        cin>>x;
        q.push(x);
    }

    int expected = 1;

    while(!q.empty()) {
        if(q.front() == expected) {
            q.pop();
            expected++;
        }
        else if(!st.empty() && st.top() == expected) {
            st.pop();
            expected++;
        }
        else {
            st.push(q.front());
            q.pop();
        }
    }

    while(!st.empty() && st.top() == expected) {
        st.pop();
        expected++;
    }

    if(expected - 1 == n)
        cout<<"YES";
    else
        cout<<"NO";

    return 0;
}
