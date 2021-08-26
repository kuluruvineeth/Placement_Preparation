/* PROBLEM STATEMENT : Given an array find next greater element of that element */

#include <bits/stdc++.h>
using namespace std;

vector<int> next_greater_element(vector<int> &v)
{
  int n = v.size();
  vector<int> nge(n, -1);
  stack<int> st;
  for (int i = 2 * n - 1; i >= 0; i--)
  {
    while (!st.empty() and st.top() <= v[i % n])
    {
      st.pop();
    }
    if (i < n)
    {
      if (!st.empty())
      {
        nge[i] = st.top();
      }
    }
    st.push(v[i % n]);
  }
  return nge;
}

int main()
{
  vector<int> v{2, 3, 1, 6, 7, 1};
  vector<int> ans = next_greater_element(v);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}