/* PROBLEM STATEMENT : find maximum number of meetings you can have with given start and end times*/

#include <bits/stdc++.h>
using namespace std;

struct meeting
{
  int start;
  int end;
  int pos;
};

bool comparator(struct meeting m1, struct meeting m2)
{
  if (m1.end < m2.end)
  {
    return true;
  }
  else if (m1.end > m2.end)
  {
    return false;
  }
  else if (m1.pos < m2.pos)
  {
    return true;
  }
  return false;
}

void max_meetings(vector<int> &s, vector<int> &e, int n)
{
  struct meeting m[n];
  for (int i = 0; i < n; i++)
  {
    m[i].start = s[i];
    m[i].end = e[i];
    m[i].pos = i + 1;
  }
  sort(m, m + n, comparator);
  vector<int> ans;
  int last = m[0].end;
  ans.push_back(m[0].pos);
  for (int i = 1; i < n; i++)
  {
    if (m[i].start > last)
    {
      last = m[i].end;
      ans.push_back(m[i].pos);
    }
  }

  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
}

int main()
{
  vector<int> s{1, 3, 0, 5, 8, 5};
  vector<int> e{2, 4, 6, 7, 9, 9};
  int n = s.size();
  max_meetings(s, e, n);
  return 0;
}
