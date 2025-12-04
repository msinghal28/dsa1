#include<iostream>
#include<queue>
using namespace std;

int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;

    queue<string> q;
    q.push("1");

    cout<<"Binary numbers from 1 to "<<n<<": ";

    for(int i = 1; i <= n; i++) {
        string cur = q.front();
        q.pop();

        cout<<cur<<" ";

        // Generate next two binary numbers
        q.push(cur + "0");
        q.push(cur + "1");
    }

    return 0;
}
