#include<iostream>
#include<queue>
using namespace std;

int main() {
    int n;
    cout<<"Enter number of students: ";
    cin>>n;

    queue<int> students;
    queue<int> sandwiches;

    cout<<"Enter student preferences (0 or 1): ";
    for(int i=0; i<n; i++){
        int x; cin>>x;
        students.push(x);
    }

    cout<<"Enter sandwiches stack (top to bottom): ";
    for(int i=0; i<n; i++){
        int x; cin>>x;
        sandwiches.push(x);
    }

    int attempts = 0;

    while(!students.empty() && attempts < students.size()) {
        if(students.front() == sandwiches.front()) {
            students.pop();
            sandwiches.pop();
            attempts = 0; // reset since someone ate
        } else {
            // Move student to back
            students.push(students.front());
            students.pop();
            attempts++;
        }
    }

    cout<<"Students unable to eat lunch = "<<students.size()<<endl;

    return 0;
}
