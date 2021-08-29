/* PROBLEM STATEMENT : Find one single non duplicate number */

#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int> &v)
{
  int low = 0, high = v.size() - 2;
  while (low <= high)
  {
    int mid = (low + high) >> 1;
    if (v[mid] == v[mid ^ 1])
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return v[low];
}

int main()
{
  vector<int> v{1, 1, 2, 2, 3, 4, 4, 5, 5};
  cout << singleNonDuplicate(v) << endl;
  return 0;
}