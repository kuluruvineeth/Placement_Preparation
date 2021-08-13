/* PROBLEM STATEMENT : Given a 2 dimensional array search for target element*/

#include <bits/stdc++.h>
using namespace std;

//1.GFG PROBLEM APPROACH
void search_gfg(vector<vector<int>> &v, int m, int n, int target)
{
  int i = 0, j = n - 1;
  while (i < m and j >= 0)
  {
    if (v[i][j] == target)
    {
      cout << "Found at : " << i << ", " << j;
      return;
    }
    if (v[i][j] > target)
    {
      j--;
    }
    else
    {
      i++;
    }
  }
  cout << "not found " << endl;
}

//2.leetcode problem approach
bool search_leetcode(vector<vector<int>> &v, int m, int n, int target)
{
  int low = 0, high = (m * n) - 1;
  while (low <= high)
  {
    int mid = (low + (high - low) / 2);
    if (v[mid / n][mid % n] == target)
    {
      return true;
    }
    if (v[mid / n][mid % n] < target)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return false;
}

int main()
{
  vector<vector<int>> v{{10, 20, 30, 40}, {11, 21, 36, 43}, {25, 29, 39, 50}, {50, 60, 70, 80}};
  vector<vector<int>> v1{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
  int m = v.size();
  int n = v[0].size();
  //search_gfg(v, m, n, 27);
  cout << search_leetcode(v1, v1.size(), v1[0].size(), 34);
  return 0;
}