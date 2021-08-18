/* PROBLEM STATEMENT : Find minimum number of coins to add up to our value */

#include <bits/stdc++.h>
using namespace std;

void minimum_coins(int value)
{
  int deno[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
  int n = 9;
  vector<int> ans;

  for (int i = n - 1; i >= 0; i--)
  {
    while (value >= deno[i])
    {
      value -= deno[i];
      ans.push_back(deno[i]);
    }
  }
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
}

int main()
{
  minimum_coins(49);
  return 0;
}