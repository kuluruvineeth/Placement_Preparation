/* PROBLEM STATEMENT : Given an array find majority element in array */

#include <bits/stdc++.h>
using namespace std;

//1.OPTIMAL APPROACH : TIME=O(N),SPACE=O(1) -- Moores voting algorithm
int majorityelement(vector<int> &v)
{
  int count = 0, candidate = 0;
  for (int num : v)
  {
    if (count == 0)
    {
      candidate = num;
    }
    if (num == candidate)
    {
      count += 1;
    }
    else
    {
      count -= 1;
    }
  }
  return candidate;
}

int main()
{
  vector<int> v{3, 3, 4, 2, 4, 4, 2, 4, 4};
  cout << majorityelement(v);
  return 0;
}