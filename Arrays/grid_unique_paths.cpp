/* PROBLEM STATEMENT : Find number of unique paths from start to end */

#include <bits/stdc++.h>
using namespace std;

//reacurison and dp approach you will have to say.

//1.OPTIMAL APPROACH : combinatorial approach
int uniquepaths(int m, int n)
{
  int N = n + m - 2;
  int r = m - 1;
  double res = 1;
  for (int i = 1; i <= r; i++)
  {
    res = res * (N - r + 1) / i;
  }
  return (int)res;
}

int main()
{
  cout << uniquepaths(2, 3);
  return 0;
}