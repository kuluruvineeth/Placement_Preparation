/* PROBLEM STATEMENT : Given an array of numbers find the longest increasing subsequence in the array*/

#include <bits/stdc++.h>
using namespace std;

//optimal approach
int longestconsequence(vector<int> &v)
{
  set<int> s;
  for (int num : v)
  {
    s.insert(num);
  }
  int longeststreak = 0;
  for (int num : v)
  {
    if (!s.count(num - 1))
    {
      int currentnum = num;
      int currentstreak = 1;
      while (s.count(currentnum + 1))
      {
        currentnum += 1;
        currentstreak += 1;
      }
      longeststreak = max(longeststreak, currentstreak);
    }
  }
  return longeststreak;
}

int main()
{
  vector<int> v{2, 6, 1, 9, 4, 5, 3};
  cout << longestconsequence(v) << endl;
  return 0;
}