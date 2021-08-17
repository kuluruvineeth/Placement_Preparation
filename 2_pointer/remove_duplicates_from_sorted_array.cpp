/* PROBLEM STATEMENT : Given an array of n integers with duplicate elements arrrange all unique elements at beginning of array and return size of unique elements*/

#include <bits/stdc++.h>
using namespace std;

//naive approach is to use sets : TIME=O(NLOGN)

//optimal approach is to use two pointers : TIME=O(N)

int remove_duplicates(vector<int> &v)
{
  if (v.size() == 0)
  {
    return 0;
  }
  int i = 0;
  for (int j = 1; j < v.size(); j++)
  {
    if (v[j] != v[i])
    {
      i++;
      v[i] = v[j];
    }
  }
  return i + 1;
}

int main()
{
  vector<int> v{1, 1, 2, 2, 2, 3, 3};
  cout << remove_duplicates(v);
  return 0;
}