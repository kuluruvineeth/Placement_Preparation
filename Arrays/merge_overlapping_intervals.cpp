/* PROBLEM STATEMENT : Given an array with start and end times,merge those intervals which overlap */

/*There are three approaches to solve this problem.Approaches are in increasing order of their efficiency
1.NAIVE APPROACH : compare every interval with all other intervals
2.BETTER APPROACH : sorting and then using stack method
3.OPTIMAL APPROACH : sorting and then not using extra space
*/

#include <bits/stdc++.h>
using namespace std;

//1.NAIVE APPROACH : TIME=O(N^2),SPACE=O(1)
// void mergeintervals_naive(vector<pair<int, int>> &v, int n)
// {
//   for (int i = 0; i < n; i++)
//   {
//     for (int j = 0; j < n; j++)
//     {
//       if (i == j)
//       {
//         continue;
//       }
//       if (v[i].first <= v[j].second and v[i].first >= v[j].first)
//       {
//       }
//     }
//   }
// }

//2.BETTER APPROACH: TIME=O(NLOGN),SPACE=O(N)
void mergeintervals_better(vector<pair<int, int>> &v, int n)
{
  sort(v.begin(), v.end());
  stack<pair<int, int>> s;
  s.push({v[0].first, v[0].second});
  for (int i = 1; i < n; i++)
  {
    int start1 = s.top().first;
    int end1 = s.top().second;
    int start2 = v[i].first;
    int end2 = v[i].second;
    //not overlapping
    if (end1 < start2)
    {
      s.push({start2, end2});
    }
    //merging
    else
    {
      s.pop();
      end1 = max(end1, end2);
      s.push({start1, end1});
    }
  }
  while (!s.empty())
  {
    cout << "[" << s.top().first << " " << s.top().second << "]"
         << ",";
    s.pop();
  }
}

//3.OPTIMAL APPROACH: TIME=O(NLOGN),SPACE=O(1)
void mergeintervals_optimal(vector<pair<int, int>> &v, int n)
{
  sort(v.begin(), v.end());
  int index = 0;
  for (int i = 1; i < n; i++)
  {
    //merging case
    if (v[index].second >= v[i].first)
    {
      v[index].first = min(v[index].first, v[i].first);
      v[index].second = max(v[index].second, v[i].second);
    }
    //non merging case
    else
    {
      index++;
      v[index] = v[i];
    }
  }
  for (int i = 0; i <= index; i++)
  {
    cout << "[" << v[i].first << " " << v[i].second << "]"
         << ",";
  }
  cout << endl;
}
int main()
{
  vector<pair<int, int>> v{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  int n = v.size();
  //mergeintervals_better(v, n);
  mergeintervals_optimal(v, n);
  return 0;
}