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

## 6. [Buy max stocks if i stocks can be bought on ithday](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Greedy/buy_max_stocks_if_i_stocks_can_be_bought_on_ithday.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++) v.push_back({a[i],i+1});
    sort(v.begin(),v.end());
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int price = v[i].first;
        int stock = v[i].second;
        if(price*stock<=k)
        {
            ans += stock;
            k -= price*stock;
        }
        else
        {
            ans += (k/price);
            k -= price*(k/price);
        }
    }
    cout<<ans<<endl;
    return 0;
}
```

## 7. [Shop in candy store](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Greedy/shop_in_candy_store.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

vector<int> candyStore(int candies[],int n,int k)
{
    sort(candies,candies+n);
    int ma=0;
    int mi=0;
    int i=0;
    int j=n-1;
    while(i<=j)
    {
        mi += candies[i];
        i++;
        j=j-k;
    }
    reverse(candies,candies+n);
    i=0;j=n-1;
    while(i<=j)
    {
        ma += candies[i];
        i++;
        j=j-k;
    }
    return {mi,ma};
}
int main()
{
    int arr[] = {3,2,1,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k;cin>>k;
    vector<int> ans = candyStore(arr,n,k);
    cout<<ans[0]<<" , "<<ans[1]<<endl;
    return 0;
}
```

## 8. [Min cost to cut board into squares](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Greedy/min_cost_to_cut_board_into_square.cpp)
```cpp
/*
initially board is altogether, but after each cut it will be divided and furthur cuts will be made on the basis of different grouped sections
	eg.
	- - - -
	- - - -
	- - - -
	- - - -
	after cut in row sections will be like
	- - - -
	- - - -
	- - - -
	- - - -
	after cut in column sections will be like
	- - -   -
	- - -   -
	- - -   -
	- - -   -
	and hence cost will be accordingly
*/
#include<bits/stdc++.h>
using namespace std;

//method returns minimum cost to break board into m*n squares
int minimumCostOfBreaking(int X[],int Y[],int m,int n)
{
    int res=0;
    //sort the horizontal cost in reverse order
    sort(X,X+m,greater<int>());
    //sort the vertical cost in reverse order
    sort(Y,Y+n,greater<int>());
    //initialize current width as 1
    int hor=1,ver=1;

    //loop until one or both cost array are processed
    int i=0,j=0;
    while(i<m && j<n)
    {
        if(X[i]>Y[j])
        {
            res += X[i]*ver;
            //increse current horizontal part count by 1
            hor++;
            i++;
        }
        else
        {
            res += Y[j]*hor;
            //increase current vertical part count by 1
            ver++;
            j++;
        }
    }
    //loop for horizontal array,if remains
    int total=0;
    while(i<m)
    {
        total += X[i++];
    }
    res += total*ver;

    //loop for vertical array, if remains
    total =0;
    while(j<n)
    {
        total += Y[j++];
    }
    res += total*hor;
    return res;
}

int main()
{
    int m=6,n=4;
    int X[m-1] = {2,1,3,1,4};
    int Y[n-1] = {4,1,2};
    cout<<minimumCostOfBreaking(X,Y,m-1,n-1);
    return 0;
}
```

## 9. [Check if its possible to survive on island](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Greedy/check_if_its_possible_to_survive_on_island.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;
/*
N – Maximum unit of food you can buy each day.
S – Number of days you are required to survive.
M – Unit of food required each day to survive.
*/
int main()
{
    int S,N,M;
    cin>>S>>N>>M;

    int x = S/7; // to get sundays count
    int y = S - x; //to get number of days we can buy food
    int SM = S*M; //total food units required to survive S days
    int days = SM/N; //actual days required to buy required food
    if(SM%N != 0) days++;
    if(days<=y) cout<<"Yes "<<days;
    else cout<<"No";
    return 0;
}
```

## 10. [Maximum product subset of an array](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Greedy/maximum_product_subset_of_an_array.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int zero_count = 0;
    int negative_count = 0;
    int prod=1;
    int max_negative = INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            zero_count++;
            continue;
        }
        if(a[i]<0)
        {
            negative_count++;
            max_negative = max(max_negative,a[i]);
        }
        prod = prod*a[i];
    }
    if(zero_count==n)
    {
        cout<<"0";
        return 0;
    }
    else if(negative_count==1 and zero_count+negative_count==n)
    {
        cout<<"0";
        return 0;
    }
    else if(negative_count&1) //if negative count is odd
    {
        prod = prod/max_negative;
    }
    cout<<prod;
    return 0;
}
```

## 11. [Maximum array sum after k negations](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Greedy/maximize_array_sum_after_k_negations.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

long long int maximizeSum(long long int a[],int n,int k)
{
    sort(a,a+n);
    long long int sum=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]<0 and k>0)
        {
            a[i] = -a[i];
            k--;
        }
    }
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
    }
    int x = *min_element(a,a+n);
    if(k&1) sum-=2*x;
    return sum;
}

int main()
{
    int n,k;
    cin>>n>>k;
    long long int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    long long int res= maximizeSum(a,n,k);
    cout<<"Maximum sum is : "<<res<<endl;
    return 0;
}
```

## 12. [Smallest subset with sum greater than all other elements](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Greedy/smallest_subset_with_sum_greater_than_all_other_elements.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    int s=0;
    for(int i=0;i<n;i++) s += a[i];
    int ans=0;
    int s2=0;
    int j=n-1;
    while(true)
    {
        s2 += a[j];
        s -= a[j];
        j--;
        ans++;
        if(s2>s) break;
    }
    cout<<ans;
    return 0;
}
```