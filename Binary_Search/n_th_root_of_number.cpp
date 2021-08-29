/* PROBLEM STATEMENT : Given a number find nth root of that number */

//TIME COMPLEXITY = NLOG(M*d)
#include <bits/stdc++.h>
using namespace std;

double multiply(double number, int n)
{
  double ans = 1.0;
  for (int i = 1; i <= n; i++)
  {
    ans = ans * number;
  }
  return ans;
}

double getNthRoot(int n, int m)
{
  double low = 1;
  double high = m;
  double diff = 1e-6;
  double mid;
  while ((high - low) > diff)
  {
    mid = (low + high) / 2.0;
    if (multiply(mid, n) < m)
    {
      low = mid;
    }
    else
    {
      high = mid;
    }
  }
  cout << low << " " << high << endl;

  //checking
  cout << pow(m, (double)(1.0 / (double)n)) << endl;
  return mid;
}

int main()
{
  int n, m;
  cin >> n >> m;
  cout << getNthRoot(n, m);
  return 0;
}