/* PROBLEM STATEMENT : leetcode problem with certain conditions*/

#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &v, int low, int mid, int high)
{
  int count = 0;
  int j = mid + 1;
  for (int i = low; i <= mid; i++)
  {
    while (j <= high && v[i] > 2 * v[j])
    {
      j++;
    }
    count += (j - (mid + 1));
  }

  vector<int> temp;
  int left = low, right = mid + 1;
  while (left <= mid and right <= high)
  {
    if (v[left] <= v[right])
    {
      temp.push_back(v[left++]);
    }
    else
    {
      temp.push_back(v[right++]);
    }
  }
  while (left <= mid)
  {
    temp.push_back(v[left++]);
  }
  while (right <= high)
  {
    temp.push_back(v[right++]);
  }
  for (int i = low; i <= high; i++)
  {
    v[i] = temp[i - low];
  }
  return count;
}

int mergesort(vector<int> &v, int low, int high)
{
  if (low >= high)
  {
    return 0;
  }
  int mid = (low + high) / 2;
  int inv = mergesort(v, low, mid);
  inv += mergesort(v, mid + 1, high);
  inv += merge(v, low, mid, high);
  return inv;
}

int reversepairs(vector<int> &v)
{
  return mergesort(v, 0, v.size() - 1);
}

int main()
{
  vector<int> v{2, 4, 3, 5, 1};
  cout << reversepairs(v);
  return 0;
}