#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q, first, second;
    int n, x; 
    cout<<"Enter number of elements: ";
    cin >> n;
    for (int i = 0; i < n; i++) { 
        cout<<"enter the "<<i+1<<">> element: ";
        cin >> x; q.push(x); }
    for(int i = 0; i < n/2; i++){
        first.push(q.front()); 
        q.pop();
    }
    while(!q.empty()){
        second.push(q.front());
        q.pop();
    }
    while(!first.empty() && !second.empty()) {
        cout << first.front() << " " << second.front() << " ";
        first.pop();
        second.pop();
    }
}
