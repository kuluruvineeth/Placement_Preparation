/* PROBLEM STATEMENT : Given an array find sums of all subsets of an array */

#include <bits/stdc++.h>
using namespace std;

void recursive_fun(int index, int sum, vector<int> &v, int N, vector<int> &s)
{
  if (index == N)
  {
    s.push_back(sum);
    return;
  }
  // pick the element
  recursive_fun(index + 1, sum + v[index], v, N, s);

  //Do not pick the element
  recursive_fun(index + 1, sum, v, N, s);
}

vector<int> subset_sums(vector<int> v, int N)
{
  vector<int> s;
  recursive_fun(0, 0, v, N, s);
  sort(s.begin(), s.end());
  return s;
}

int main()
{
  vector<int> v = {1, 2, 3};
  int n = v.size();
  vector<int> ans = subset_sums(v, n);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  return 0;
}