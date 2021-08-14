/* PROBLEM STATEMENT : Given an array find four numbers whose sum is equal to target*/

#include <bits/stdc++.h>
using namespace std;

//OPTIMAL APPROACH : TIME : O(N^3),SPACE=O(N^2)
vector<vector<int>> foursum(vector<int> &v, int target)
{
  vector<vector<int>> res;
  if (v.empty())
  {
    return res;
  }
  int n = v.size();
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      int target_2 = target - v[i] - v[j];
      int front = j + 1;
      int back = n - 1;
      while (front < back)
      {
        int two_sum = v[front] + v[back];
        if (two_sum < target_2)
        {
          front++;
        }
        else if (two_sum > target_2)
        {
          back--;
        }
        else
        {
          vector<int> quadruplet(4, 0);
          quadruplet[0] = v[i];
          quadruplet[1] = v[j];
          quadruplet[2] = v[front];
          quadruplet[3] = v[back];
          res.push_back(quadruplet);

          //processing the duplicates from front
          while (front < back and v[front] == quadruplet[2])
          {
            front++;
          }
          //processing the duplicates from back
          while (front < back and v[back] == quadruplet[3])
          {
            back--;
          }
        }
      }
      while (j + 1 < n and v[j + 1] == v[j])
      {
        j++;
      }
    }
    while (i + 1 < n and v[i + 1] == v[i])
    {
      i++;
    }
  }
  return res;
}

int main()
{
  vector<int> v{1, 0, -1, 0, -2, 2};
  vector<vector<int>> res = foursum(v, 0);
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