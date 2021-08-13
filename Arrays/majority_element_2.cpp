/* PROBLEM STATEMENT : Given an array,find majority elements greater than n/3 elements*/

#include <bits/stdc++.h>
using namespace std;

//1.Improvised version of moores algorithm
vector<int> majorityelement(vector<int> &v)
{
  int n = v.size();
  int num1 = -1, num2 = -1, count1 = 0, count2 = 0;
  for (int i = 0; i < n; i++)
  {
    if (v[i] == num1)
    {
      count1++;
    }
    else if (v[i] == num2)
    {
      count2++;
    }
    else if (count1 == 0)
    {
      num1 = v[i];
      count1 = 1;
    }
    else if (count2 == 0)
    {
      num2 = v[i];
      count2 = 1;
    }
    else
    {
      count1--;
      count2--;
    }
  }
  vector<int> ans;
  count1 = 0, count2 = 0;
  for (int i = 0; i < n; i++)
  {
    if (v[i] == num1)
    {
      count1++;
    }
    else if (v[i] == num2)
    {
      count2++;
    }
  }
  if (count1 > n / 3)
  {
    ans.push_back(num1);
  }
  if (count2 > n / 3)
  {
    ans.push_back(num2);
  }
  return ans;
}

int main()
{
  vector<int> v{1, 1, 1, 3, 3, 2, 2, 2};
  vector<int> ans = majorityelement(v);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}