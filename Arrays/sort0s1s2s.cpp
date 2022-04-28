#include <bits/stdc++.h>
using namespace std;

/* PROBLEM STATEMENT : Given an array of 0s,1s and 2s sort the array without using sort algorithm*/

/*There are three approaches to solve this problem.Approches are in increasing order of their efficiency
1.NAIVE APPROACH : just sort with sort function
2.BETTER APPROACH : use count sort(two traversals)
3.OPTIMAL APPROACH : Dutch National Flag Algorithm(using three pointers)

*/

//1.NAIVE APPROACH : TIME=O(NLOGN), SPACE=O(1)
void sortnaive(vector<int> &v, int n)
{
  //sort algorithm
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

//2.BETTER APPROACH : TIME=O(N), SPACE=O(1)

void sortbetter(vector<int> &v, int n)
{
  int count0 = 0, count1 = 0, count2 = 0;
  int i = 0;
  while (i < n)
  {
    switch (v[i])
    {
    case 0:
      count0++;
      break;

    case 1:
      count1++;
      break;

    case 2:
      count2++;
      break;
    default:
      exit(1);
    }
    i++;
  }

  i = 0;
  while (count0 > 0)
  {
    v[i++] = 0;
    count0--;
  }
  while (count1 > 0)
  {
    v[i++] = 1;
    count1--;
  }

  while (count2 > 0)
  {
    v[i++] = 2;
    count2--;
  }

  for (int j = 0; j < n; j++)
  {
    cout << v[j] << " ";
  }
  cout << endl;
}

//3.OPTIMAL APPROACH : TIME=O(N) , SPACE=O(1)

void sortoptimal(vector<int> &v, int n)
{
  int low = 0;
  int mid = 0;
  int high = n - 1;
  while (mid <= high)
  {
    switch (v[mid])
    {
    case 0:
      swap(v[mid++], v[low++]);
      break;
    case 1:
      mid++;
      break;
    case 2:
      swap(v[mid], v[high--]);
      break;
    default:
      exit(1);
    }
  }
  for (int i = 0; i < n; i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

int main()
{
  vector<int> v{0, 1, 2, 1, 2, 0, 1, 2};
  int n = v.size();
  sortnaive(v, n);
  sortbetter(v,n);
  sortoptimal(v,n);
}
