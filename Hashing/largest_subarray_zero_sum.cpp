/* PROBLEM STATEMENT : Given an array of numbers find the largest subarray with 0 sum*/

#include <bits/stdc++.h>
using namespace std;

//optimal approach : TIME=O(N),SPACE=O(N)
int maxlen(vector<int> &v, int n)
{
  int sum = 0, maxi = 0;
  unordered_map<int, int> m;
  for (int i = 0; i < n; i++)
  {
    sum += v[i];
    if (sum == 0)
    {
      maxi = i + 1;
    }
    else
    {
      if (m.find(sum) != m.end())
      {
        maxi = max(maxi, i - m[sum]);
      }
      else
      {
        m[sum] = i;
      }
    }
  }
  return maxi;
}

int main()
{

  vector<int> v{15, -2, 2, -8, 1, 7, 10, 23};
  cout << maxlen(v, v.size()) << endl;
  return 0;
}