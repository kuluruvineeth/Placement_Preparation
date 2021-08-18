/* PROBLEM STATEMENT : GFG practice job sequencing problem*/

#include <bits/stdc++.h>
using namespace std;

struct job
{
  int dead;
  int profit;
};

bool comparison(job a, job b)
{
  return (a.profit > b.profit);
}

pair<int, int> job_sequencing(job arr[], int n)
{
  sort(arr, arr + n, comparison);
  int maxi = arr[0].dead;
  for (int i = 1; i < n; i++)
  {
    maxi = max(maxi, arr[i].dead);
  }
  int slot[maxi + 1];
  for (int i = 0; i < n; i++)
  {
    slot[i] = -1;
  }
  int countjobs = 0, profit = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = arr[i].dead; j > 0; j--)
    {
      if (slot[j] == -1)
      {
        slot[j] = i;
        countjobs++;
        profit += arr[i].profit;
        break;
      }
    }
  }
  return make_pair(countjobs, profit);
}

int main()
{
  job v[] = {{4, 20}, {1, 10}, {1, 40}, {1, 30}};
  int n = sizeof(v) / sizeof(v[0]);
  pair<int, int> p = job_sequencing(v, n);
  cout << p.first << "," << p.second << endl;
  return 0;
}