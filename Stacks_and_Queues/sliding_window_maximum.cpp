/* PROBLEM STATEMENT : Given an array find maximum element in all subarrays of size k */

#include <bits/stdc++.h>
using namespace std;

vector<int> maximum_sliding_window(vector<int> &v, int k)
{
  deque<int> dq;
  vector<int> ans;
  for (int i = 0; i < v.size(); i++)
  {
    if (!dq.empty() and dq.front() == i - k)
    {
      dq.pop_front();
    }
    while (!dq.empty() and v[dq.back()] < v[i])
    {
      dq.pop_back();
    }
    dq.push_back(i);
    if (i >= k - 1)
    {
      ans.push_back(v[dq.front()]);
    }
  }
  return ans;
}

int main()
{
  vector<int> v{1, -1, 2, 3, 7, 9, 12, 33};
  vector<int> ans = maximum_sliding_window(v, 3);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}