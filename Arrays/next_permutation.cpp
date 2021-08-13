/* PROBLEM STATEMENT : Given an array of numbers find lexicographically next permutation*/

#include <bits/stdc++.h>
using namespace std;

//1.OPTIMAL APPROACH : TIME=O(N),SPACE=O(1)
void next_optimal(vector<int> &v, int n)
{
  int index = -1;
  for (int i = n - 1; i >= 0; i--)
  {
    if (v[i] > v[i - 1])
    {
      index = i;
      break;
    }
  }
  if (index == -1)
  {
    reverse(v.begin(), v.end());
  }
  else
  {
    int previous = index;
    for (int i = index + 1; i < n; i++)
    {
      if (v[i] > v[index - 1] and v[i] <= v[previous])
      {
        previous = i;
      }
    }
    swap(v[index - 1], v[previous]);
    reverse(v.begin() + index, v.end());
  }
  for (int i = 0; i < n; i++)
  {
    cout << v[i];
  }
  cout << endl;
}

int main()
{
  vector<int> v{1, 3, 5, 4, 2};
  int n = v.size();
  next_optimal(v, n);
  return 0;
}