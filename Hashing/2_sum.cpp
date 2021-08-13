/* PROBLEM STATEMENT : Given an array find the pair indexes whose sum is equal to target */

#include <bits/stdc++.h>
using namespace std;

vector<int> twosum(vector<int> &v, int target)
{
  vector<int> ans;
  unordered_map<int, int> m;
  for (int i = 0; i < v.size(); i++)
  {
    if (m.find(target - v[i]) != m.end())
    {
      ans.push_back(m[target - v[i]]);
      ans.push_back(i);
      return ans;
    }
    m[v[i]] = i;
  }
  return ans;
}

int main()
{
  vector<int> v{2, 7, 11, 15};
  vector<int> ans = twosum(v, 18);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << ",";
  }
  return 0;
}