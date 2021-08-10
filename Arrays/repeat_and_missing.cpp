/* PROBLEM STATEMENT : Given an array of n elements in the range of 1 to n,one number is missing and other is repeating twice,
find missing and repeating number */

/*There are three approaches to solve this problem.Approches are in increasing order of their efficiency
1.NAIVE APPROACH : just sort with sort function and traverse to find missing and repeating
2.BETTER APPROACH : use count sort(two traversals),the one with 0 is missing and one with 2 is repeating
3.OPTIMAL APPROACH : use elements as index and marking visited places

*/

#include <bits/stdc++.h>
using namespace std;

//1.NAIVE APPROACH: TIME=O(NLOGN), SPACE=O(1)
void rm_naive(vector<int> &v, int n)
{
  sort(v.begin(), v.end());
  int repeating = 0, missing = 0;
  for (int i = 0; i < n - 1; i++)
  {
    if (v[i] == v[i + 1])
    {
      repeating = v[i];
    }
    if ((v[i + 1] - v[i]) != 1)
    {
      missing = i + 1;
    }
  }
  cout << "repeating: " << repeating << " ";
  cout << "missing: " << missing << " ";
}

//2.BETTER APPROACH: TIME=O(N),SPACE=O(N)
void rm_better(vector<int> &v, int n)
{
  int count[n];
  for (int i = 0; i < n; i++)
  {
    count[i] = 0;
  }
  int repeating = 0, missing = 0;
  for (int i = 0; i < n; i++)
  {
    count[v[i]]++;
  }
  for (int i = 0; i < n; i++)
  {
    if (count[i] == 0)
    {
      missing = i;
    }
    if (count[i] == 2)
    {
      repeating = i;
    }
  }
  cout << "repeating: " << repeating << " ";
  cout << "missing: " << missing << " ";
}

//3.OPTIMAL APPROACH : TIME=O(N),SPACE=O(1)
void rm_optimal(vector<int> &v, int n)
{
  int missing = 0, repeating = 0;
  for (int i = 0; i < n; i++)
  {
    if (v[abs(v[i]) - 1] > 0)
    {
      v[abs(v[i]) - 1] = -v[abs(v[i]) - 1];
    }
    else
    {
      repeating = abs(v[i]);
    }
  }

  for (int i = 0; i < n; i++)
  {
    if (v[i] > 0)
    {
      missing = i + 1;
    }
  }
  cout << "repeating: " << repeating << " ";
  cout << "missing: " << missing << " ";
}

int main()
{
  vector<int> v{4, 3, 6, 2, 1, 1};
  int n = v.size();
  //rm_naive(v, n);
  //rm_better(v, n);
  rm_optimal(v, n);
  return 0;
}
