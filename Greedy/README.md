# List of Greedy based questions for Interview Preparation

## 1.[Activity Selection Problem](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Greedy/activity_selection_problem.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

static bool comp(pair<int,int> a,pair<int,int> b)
{
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int maxMeetings(int start[],int end[],int n)
{
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++) v[i] = {start[i],end[i]};
    sort(v.begin(),v.end(),comp);
    int i=0;
    int j=1;
    int c=1;
    while(j<n)
    {
        if(v[i].second < v[j].first)
        {
            c++;
            i=j;
            j++;
        }
        else j++;
    }
    return c;
}

int main()
{
  int s[] = {1, 3, 0, 5, 8, 5};
  int e[] = {2, 4, 6, 7, 9, 9};
  int n = sizeof(s)/sizeof(s[0]);
  cout<<"Max meetings can be held is : "<<maxMeetings(s, e, n)<<endl;
  return 0;
}
```

## 2. [Job Sequencing Problem](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Greedy/job_sequence.cpp)
```cpp
/* PROBLEM STATEMENT : GFG practice job sequencing problem*/
//Refer Code Library channel
#include <bits/stdc++.h>
using namespace std;

struct job
{
  int dead;
  int profit;
};

bool comparison(job a, job b)
{
  return (a.profit > b.profit);
}

pair<int, int> job_sequencing(job arr[], int n)
{
  sort(arr, arr + n, comparison);
  int maxi = arr[0].dead;
  for (int i = 1; i < n; i++)
  {
    maxi = max(maxi, arr[i].dead);
  }
  int slot[maxi + 1];
  for (int i = 0; i < n; i++)
  {
    slot[i] = -1;
  }
  int countjobs = 0, profit = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = arr[i].dead; j > 0; j--)
    {
      if (slot[j] == -1)
      {
        slot[j] = i;
        countjobs++;
        profit += arr[i].profit;
        break;
      }
    }
  }
  return make_pair(countjobs, profit);
}

int main()
{
  job v[] = {{4, 20}, {1, 10}, {1, 40}, {1, 30}};
  int n = sizeof(v) / sizeof(v[0]);
  pair<int, int> p = job_sequencing(v, n);
  cout << p.first << "," << p.second << endl;
  return 0;
}
```