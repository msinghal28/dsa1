#include<bits/stdc++.h>
using namespace std;

int main() {
  stack<char> check;
  string para = "[(]{}";
  int size = para.length();
  for(int i=0; i<size; i++){
    if(para[i]=='(' || para[i]=='{' || para[i]=='['){
      check.push(para[i]);
    } else if(para[i]==')' || para[i]=='}' || para[i]==']'){
      if(check.empty()) {
        cout<<"Unbalanced brakets";
        return 0;
      }
      char x = check.top();
      if ((check.top() == '(' && para[i] == ')') || 
          (check.top() == '{' && para[i] == '}') ||
          (check.top() == '[' && para[i] == ']')) check.pop();
      else {
        cout<<"Unbalanced brakets";
        return 0;
      }
    }
  }
  if(!check.empty()) {
    cout<<"Unbalanced brackets";
    return 0;
  }
  cout<<"Balanced brackets";

  return 1;
}