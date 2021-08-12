/* PROBLEM STATEMENT : Given an array count number of inversion on condition i<j and a[i]>a[j]*/

/*There are two approaches to solve this problem.Approaches are in increasing order of their efficiency
1.NAIVE APPROACH: use two loops and keep counting on condition
2.OPTIMAL APPROACH: divide and conquer method(merge sort)
*/

#include <bits/stdc++.h>
using namespace std;

//1.NAIVE APPROACH: TIME=O(N^2),SPACE=O(1)
void inversions_naive(vector<int> &v, int n)
{
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (v[i] > v[j])
      {
        count++;
      }
    }
  }
  cout << "Number of inversions count are : " << count << endl;
}

//2.OPTIMAL APPROACH: TIME=O(NLOGN),SPACE=O(N)
int merge(vector<int> &v, vector<int> &t, int start, int mid, int end)
{
  int i = start, j = mid, k = start;
  int count = 0;
  while ((i <= mid - 1) and (j <= end))
  {
    if (v[i] < v[j])
    {
      t[k++] = v[i++];
    }
    else
    {
      count += mid - i;
      t[k++] = v[j++];
    }
  }
  while (i <= mid - 1)
  {
    t[k++] = v[i++];
  }
  while (j <= end)
  {
    t[k++] = v[j++];
  }
  for (int i = start; i <= end; i++)
  {
    v[i] = t[i];
  }
  return count;
}

int mergesort(vector<int> &v, vector<int> &t, int start, int end)
{
  int count = 0;
  if (start < end)
  {
    int mid = (start + end) / 2;
    count += mergesort(v, t, start, mid);
    count += mergesort(v, t, mid + 1, end);
    count += merge(v, t, start, mid + 1, end);
  }
  return count;
}

int inversion_optimal(vector<int> &v, int n)
{
  vector<int> t(n);
  return mergesort(v, t, 0, n - 1);
}

int main()
{
  vector<int> v{8, 4, 2, 1};
  vector<int> t;
  int n = v.size();
  //inversions_naive(v, n);
  int count = inversion_optimal(v, n);
  cout << "inversion counts : " << count << endl;
  return 0;
}