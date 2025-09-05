#include <bits/stdc++.h>
using namespace std;

int precedence(char op) {
  if (op == '^') return 3;
  if (op == '*' || op == '/') return 2;
  if (op == '+' || op == '-') return 1;
  return -1;
}

string infixToPostfix(string infix) {
  stack<char> st;
  string postfix;

  for (int i=0; i<infix.length(); i++) {
    if (infix[i]>='1' && infix[i]<='9') { 
      postfix += infix[i];
    }
    else if (infix[i] == '(') {
      st.push(infix[i]);
    }
    else if (infix[i] == ')') {
      while (!st.empty() && st.top() != '(') {
        postfix += st.top();
        st.pop();
      }
        st.pop(); 
    }
    else { 
      while (!st.empty() && precedence(st.top()) >= precedence(infix[i])) {
        postfix += st.top();
        st.pop();
      }
        st.push(infix[i]);
    }
  }

  while (!st.empty()) {
    postfix += st.top();
    st.pop();
  }

  return postfix;
}

int main() {
  string infix = "(2+6)*9";
  cout << "Infix: " << infix << endl;
  cout << "Postfix: " << infixToPostfix(infix) << endl;
  return 0;
}
