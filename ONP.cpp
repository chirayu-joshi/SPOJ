// Goal: To convert infix to Reverse Polish Notation (Postfix).
#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
  // isalpha() is used to check if input is alphabet or not.
  return !isalpha(c) && !isdigit(c);
}

int getPriority(char c) {
  if (c == '-' || c == '+') 
    return 1; 
  else if (c == '*' || c == '/') 
    return 2; 
  else if (c == '^') 
    return 3; 
  return 0; 
}

string infixToPostfix(string infix) {
  infix = '(' + infix + ')';
  stack<char> char_stack;
  string postfix;

  for (int i = 0; i < infix.length(); ++i) {
    if (isalpha(infix[i]) || isdigit(infix[i])) {
      // If character is operand, add it to postfix.
      postfix += infix[i];
    } else if (infix[i] == '(') {
      // If character is '(', push it to stack.
      char_stack.push('(');
    } else if (infix[i] == ')') {
      // If character is ')', pop untill ')' comes.
      while (char_stack.top() != '(') {
        postfix += char_stack.top();
        char_stack.pop();
      }
      char_stack.pop(); // Remove '(' from stack.
    } else {
      // Operator found.
      if (isOperator(char_stack.top())) {
        while (getPriority(infix[i]) <= getPriority(char_stack.top())) {
          postfix += char_stack.top();
          char_stack.pop();
        }
        char_stack.push(infix[i]);
      }
    }
  }
  return postfix;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  while (T--) {
    string s;
    cin >> s;

    cout << infixToPostfix(s) << "\n";
  }

  return 0;
}
