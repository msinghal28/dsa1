#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string str, rev;
    stack<char> s;
    cout << "apna naam batao: ";
    getline(cin, str);
    for (char ch : str) {
        s.push(ch);
    }
    while (!s.empty()) {
        rev += s.top();
        s.pop();
    }
    cout << "jadoouu: " << rev << endl;
    return 0;
}
