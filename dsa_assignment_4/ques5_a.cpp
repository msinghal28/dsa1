#include <iostream>
#include <bits/stdc++.h>
#include <queue>
using namespace std;

class Stack {
    queue<int> q1, q2;
public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    void pop(){
        if (!q1.empty()) {
            q1.pop();
        }
    }
    int top() {
        if (q1.empty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return q1.front();
    }
};

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout << "Top element is: " << st.top() << endl;
    st.pop();
    cout << "Top element is: " << st.top() << endl;
}
