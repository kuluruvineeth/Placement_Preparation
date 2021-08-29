/* PROBLEM STATEMENT : Find median of matrix */

#include <bits/stdc++.h>
using namespace std;

int countSmallerThanMid(vector<int> &row, int mid)
{
  int l = 0, h = row.size() - 1;
  while (l <= h)
  {
    int md = (l + h) >> 1;
    if (row[md] <= mid)
    {
      l = md + 1;
    }
    else
    {
      h = md - 1;
    }
  }
  return l;
}

int findMedian(vector<vector<int>> &v)
{
  int low = 1;
  int high = 1e9;
  int n = v.size();
  int m = v[0].size();
  while (low <= high)
  {
    int mid = (low + high) >> 1;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
      count += countSmallerThanMid(v[i], mid);
    }

    if (count <= (n * m) / 2)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return low;
}

int main()
{
  vector<vector<int>> v = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  int ans = findMedian(v);
  cout << ans << endl;
  return 0;
}