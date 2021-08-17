/* PROBLEM STATEMENT : Given an array of binary numbers find length of max consecutive ones*/

#include <bits/stdc++.h>
using namespace std;

int find_max_consecutive_ones(vector<int> &v)
{
  int count = 0;
  int maxi = 0;
  for (int i = 0; i < v.size(); i++)
  {
    if (v[i] == 1)
    {
      count++;
    }
    else
    {
      count = 0;
    }
    maxi = max(maxi, count);
  }
  return maxi;
}

int main()
{
  vector<int> v{1, 1, 0, 0, 1, 1, 1, 1};
  cout << find_max_consecutive_ones(v) << endl;
  return 0;
}
