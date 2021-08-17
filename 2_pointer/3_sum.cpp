/* PROBLEM STATEMENT : Given an array of n numbers find unique triplets whose sum is zero*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> three_sum(vector<int> &v)
{
  sort(v.begin(), v.end());
  vector<vector<int>> res;

  for (int i = 0; i < v.size() - 2; i++)
  {
    if (i == 0 || (i > 0 and v[i] != v[i - 1]))
    {
      int low = i + 1, high = v.size() - 1, sum = 0 - v[i];
      while (low < high)
      {
        if (v[low] + v[high] == sum)
        {
          vector<int> temp;
          temp.push_back(v[i]);
          temp.push_back(v[low]);
          temp.push_back(v[high]);
          res.push_back(temp);

          while (low < high and v[low] == v[low + 1])
          {
            low++;
          }
          while (low < high and v[high] == v[high - 1])
          {
            high--;
          }
          low++;
          high--;
        }
        else if (v[low] + v[high] < sum)
        {
          low++;
        }
        else
        {
          high--;
        }
      }
    }
  }
  return res;
}

int main()
{
  vector<int> v{-1, 0, 1, 2, -1, -4};
  vector<vector<int>> res = three_sum(v);
  for (int i = 0; i < res.size(); i++)
  {
    for (int j = 0; j < res[i].size(); j++)
    {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}