#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &v, int target)
{
  int low = 0, high = v.size() - 1;
  while (low <= high)
  {
    int mid = (low + high) >> 1;
    if (v[mid] == target)
    {
      return mid;
    }

    //the left side is sorted
    if (v[low] <= v[mid])
    {
      if (target >= v[low] and target <= v[mid])
      {
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }
    else
    {
      if (target >= v[mid] and target <= v[high])
      {
        low = mid + 1;
      }
      else
      {
        high = mid - 1;
      }
    }
  }
  return -1;
}

int main()
{
  vector<int> v{4, 5, 6, 7, 0, 1, 2};
  cout << search(v, 0) << endl;
  return 0;
}