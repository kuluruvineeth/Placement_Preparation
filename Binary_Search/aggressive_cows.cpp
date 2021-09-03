#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &v, int n, int cows, int minDist)
{
  int count = 1;
  int lastPlaced = v[0];
  for (int i = 1; i < n; i++)
  {
    if ((v[i] - lastPlaced) >= minDist)
    {
      count++;
      lastPlaced = v[i];
    }
  }
  if (count >= cows)
    return true;
  return false;
}

int main()
{
  vector<int> v{1, 2, 8, 4, 9};
  int n = v.size();
  sort(v.begin(), v.end());
  int low = 1, high = v[n - 1] - v[0];
  while (low <= high)
  {
    int mid = (low + high) >> 1;
    if (isPossible(v, n, 3, mid))
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  cout << high << endl;
  return 0;
}