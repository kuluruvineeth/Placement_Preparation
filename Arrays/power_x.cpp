/* PROBLEM STATEMENT : calculate the power of given number*/

#include <bits/stdc++.h>
using namespace std;

//1.OPTIMAL APPROACH : TIME=O(LOGN),SPACE=O(1)
double power(double x, int n)
{
  double ans = 1.0;
  long long nn = n;
  if (nn < 0)
  {
    nn = -1 * nn;
  }
  while (nn)
  {
    if (nn % 2)
    {
      ans = ans * x;
      nn = nn - 1;
    }
    else
    {
      x = x * x;
      nn = nn / 2;
    }
  }
  if (n < 0)
  {
    ans = (double)(1.0) / (double)(ans);
  }
  return ans;
}

int main()
{
  double ans = 0.0;
  ans = power(2, 4);
  cout << ans << endl;
  return 0;
}