/* PROBLEM STATEMENT : Given an array find all possible subsets with given sum as target */

#include <bits/stdc++.h>
using namespace std;

void find_combination(int index, int target, vector<int> &v, vector<vector<int>> &ans, vector<int> &t)
{
  if (index == v.size())
  {
    if (target == 0)
    {
      ans.push_back(t);
    }
    return;
  }
  //pick up the element
  if (v[index] <= target)
  {
    t.push_back(v[index]);
    find_combination(index, target - v[index], v, ans, t);
    t.pop_back();
  }
  find_combination(index + 1, target, v, ans, t);
}

vector<vector<int>> combination_sum(vector<int> &c, int target)
{
  vector<vector<int>> ans;
  vector<int> t;
  find_combination(0, target, c, ans, t);
  return ans;
}

int main()
{
  vector<int> v = {2, 3, 6, 7};
  vector<vector<int>> ans = combination_sum(v, 7);
  for (int i = 0; i < ans.size(); i++)
  {
    for (int j = 0; j < ans[i].size(); j++)
    {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
