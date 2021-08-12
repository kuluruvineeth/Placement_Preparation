/* PROBLEM STATEMENT : Given an matrix rotate it by clockwise 90 degrees*/

/*There are two approaches.Approaches are in increasing order of their efficiency
1.NAIVE APPROACH: using extra matrix approach
2.OPTIMAL APPROACH: in place rotation
*/

#include <bits/stdc++.h>
using namespace std;

//2.OPTIMAL APPROACH : TIME=O(N^2),SPACE=O(1)
void rotate_optimal(vector<vector<int>> &v, int m)
{
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < i; j++)
    {
      swap(v[i][j], v[j][i]);
    }
  }
  for (int i = 0; i < m; i++)
  {
    reverse(v[i].begin(), v[i].end());
  }
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < v[i].size(); j++)
    {
      cout << v[i][j] << " ";
    }
    cout << endl;
  }
}

int main()
{
  vector<vector<int>> v{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int m = v.size();
  rotate_optimal(v, m);
  return 0;
}