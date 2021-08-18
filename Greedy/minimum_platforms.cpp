/* PROBLEM STATEMENT : Find the minimum number of platforms required for all trains*/

#include <bits/stdc++.h>
using namespace std;

int minimum_platforms(vector<int> &a, vector<int> &d, int n)
{
  sort(a.begin(), a.end());
  sort(d.begin(), d.end());
  int plat = 1;
  int i = 1;
  int j = 0;
  while (i < n)
  {
    if (a[i] <= d[j])
    {
      plat++;
    }
    else
    {
      j++;
    }
    i++;
  }
  return plat;
}

int main()
{
  vector<int> a{900, 940, 950, 1100, 1500, 1800};
  vector<int> d{910, 1200, 1120, 1130, 1900, 2000};
  int n = a.size();
  cout << minimum_platforms(a, d, n) << endl;
  return 0;
}