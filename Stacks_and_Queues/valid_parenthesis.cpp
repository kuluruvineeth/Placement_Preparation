/* PROBLEM STATEMENT : Verify if the given string is balanced or not */

#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
  stack<char> st;
  for (auto it : s)
  {
    if (it == '(' or it == '{' or it == '[')
    {
      st.push(it);
    }
    else
    {
      if (st.size() == 0)
      {
        return false;
      }
      char ch = st.top();
      st.pop();
      if ((it == ')' and ch == '(') or (it == ']' and ch == '[') or (it == '}' and ch == '{'))
      {
        continue;
      }
      else
      {
        return false;
      }
    }
  }
  return st.empty();
}

int main()
{
  string s = "{[()]}";
  if (isValid(s))
  {
    cout << "string is balanced" << endl;
  }
  else
  {
    cout << "string is not balanced" << endl;
  }
  return 0;
}