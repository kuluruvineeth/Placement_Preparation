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

## 3. [Fractional Knapsack Problem](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Greedy/fractional_knapsack.cpp)
```cpp
/* PROBLEM STATEMENT : Find maxiumum value of worth you can take away even with partial takeaways*/

#include <bits/stdc++.h>
using namespace std;

struct item
{
  int value;
  int weight;
};

bool comp(item a, item b)
{
  double i1 = (double)a.value / (double)a.weight;
  double i2 = (double)b.value / (double)b.weight;
  return i1 > i2;
}

double fractional_knapsack(int W, item a[], int n)
{
  sort(a, a + n, comp);
  int current_weight = 0;
  double final_value = 0.0;
  for (int i = 0; i < n; i++)
  {
    if (current_weight + a[i].weight <= W)
    {
      current_weight += a[i].weight;
      final_value += a[i].value;
    }
    else
    {
      int remain = W - current_weight;
      final_value += (a[i].value / (double)a[i].weight) * (double)remain;
      break;
    }
  }
  return final_value;
}

int main()
{
  item a[] = {{60, 10}, {100, 20}, {120, 30}};
  int n = sizeof(a) / sizeof(a[0]);
  cout << fractional_knapsack(50, a, n) << endl;
  return 0;
}
```

## 4. [Choose and Swap](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Greedy/choose_and_swap.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

string chooseAndSwap(string a)
{
    set<char> s;
    for(int i=0;i<a.length();i++) s.insert(a[i]);
    for(int i=0;i<a.length();i++)
    {
        s.erase(a[i]);
        if(s.empty()) break;
        char ch = *s.begin();
        if(ch<a[i])
        {
            int ch2 = a[i];
            for(int j=0;j<a.length();j++)
            {
                if(a[j]==ch2) a[j] = ch;
                else if(a[j]==ch) a[j] = ch2;
            }
            break;
        }
    }
    return a;
}

int main()
{
    string s="ccad";
    cout<<chooseAndSwap(s)<<endl;
    return 0;
}
```

## 5. [Minimum Platforms Problem](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Greedy/minimum_platforms.cpp)
```cpp
/* PROBLEM STATEMENT : Find the minimum number of platforms required for all trains*/

#include <bits/stdc++.h>
using namespace std;

int minimum_platforms(vector<int> &a, vector<int> &d, int n)
{
  sort(a.begin(), a.end());
  sort(d.begin(), d.end());
  int plat = 1;
  int i = 1;
  int j = 0;
  while (i < n)
  {
    if (a[i] <= d[j])
    {
      plat++;
    }
    else
    {
      j++;
    }
    i++;
  }
  return plat;
}

int main()
{
  vector<int> a{900, 940, 950, 1100, 1500, 1800};
  vector<int> d{910, 1200, 1120, 1130, 1900, 2000};
  int n = a.size();
  cout << minimum_platforms(a, d, n) << endl;
  return 0;
}
```