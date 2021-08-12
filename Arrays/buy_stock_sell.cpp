/* PROBLEM STATEMENT: Given an array of stock prices,find maximum profit we can make with one transaction*/

/*There are two approaches to solve this problem.Approaches are in increasing order of their efficiency
1.NAIVE APPROACH : using two loops
2.OPTIMAL APPROACH : DP approach
*/

#include <bits/stdc++.h>
using namespace std;

//1.NAIVE APPROACH: TIME=O(N^2),SPACE=O(1)
void profit_naive(vector<int> &v, int n)
{
  int max_profit = INT_MIN;
  for (int i = 0; i < n; i++)
  {
    int costprice = v[i];
    int maxi = INT_MIN;
    for (int j = i + 1; j < n; j++)
    {
      if (v[j] > costprice)
      {
        maxi = max(maxi, v[j]);
      }
    }
    int profit = 0;
    if (maxi != INT_MIN)
    {
      profit = maxi - costprice;
    }
    max_profit = max(max_profit, profit);
  }
  cout << "The maximum profit is : " << max_profit << endl;
}

//2.OPTIMAL APPROACH: TIME=O(N),SPACE=O(1)
void profit_optimal(vector<int> &v, int n)
{
  int max_profit = 0;
  int min_price = INT_MAX;
  for (int i = 0; i < n; i++)
  {
    min_price = min(min_price, v[i]);
    max_profit = max(max_profit, v[i] - min_price);
  }
  cout << "The maximum profit is : " << max_profit << endl;
}

int main()
{
  vector<int> v{7, 1, 5, 3, 6, 4};
  int n = v.size();
  //profit_naive(v, n);
  profit_optimal(v, n);
  return 0;
}