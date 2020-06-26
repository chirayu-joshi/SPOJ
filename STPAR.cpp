#include <bits/stdc++.h>
using namespace std;

void printList(list<int> l) {
  for (auto i = l.begin(); i != l.end(); ++i) {
    cout << *i << " ";
  }
  cout << "\n";
}

void printStack(stack<int> s) {
  while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;
  while (N != 0) {
    int input;
    list<int> l;
    stack<int> s;

    // inputs
    for (int i = 0; i < N; ++i) {
      cin >> input;
      l.push_back(input);
    }

    list<int>::iterator cur = l.begin();
    list<int>::iterator next = l.begin();
    ++next;
    if (next == l.end()) {
      cout << "yes\n";
      cin >> N;
      continue;
    }

    while (cur != l.end()) {
      bool flag = false;
      // cout << "--------------------\n";
      // printList(l);
      // printStack(s);
      // cout << "current = " << *cur << " next = " << *next << "\n";
      // cout << "--------------------\n";
      if (!s.empty()) {
        if (s.top() >= *cur && s.top() <= *next) {
          l.insert(next, s.top());
          s.pop();
          ++cur;
          flag = true;
        }
      } 
      if (*next < *cur) {
        s.push(*cur);
        l.erase(cur);
        cur = next;
        ++next;
      } else {
        if (!flag) {
          ++cur;
          ++next;
        }
      }
    }

    // empty stack and merge with list
    while (!s.empty()) {
      l.push_back(s.top());
      s.pop();
    }

    if (is_sorted(l.begin(), l.end())) {
      cout << "yes\n";
    } else {
      cout << "no\n";
    }

    cin >> N; // Next input
  }

  return 0;
}