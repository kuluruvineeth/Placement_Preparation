# List of Dynamic Programming questions for Interview Preparation

## 1. [Coin change - Max number of ways](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Dynamic_Programming/coin_change_max_ways.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

int getMaxNumberOfWays(int coins[],int n,int sum)
{
    int t[n+1][sum+1];
    //initialization
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(i==0)
            {
                t[i][j] = 0;
            }
            if(j==0)
            {
                t[i][j] = 1;
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(coins[i-1] <= j)
            {
                t[i][j] = t[i-1][j] + t[i][j-coins[i-1]];
            }
            else
            {
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][sum];
}

int main()
{
    int n;
    cin>>n;
    int coins[n];
    for(int i=0;i<n;i++)
    {
        cin>>coins[i];
    }
    int sum;
    cin>>sum;
    cout<<getMaxNumberOfWays(coins,n,sum)<<endl;
    return 0;
}
```

## 2. [0-1 knapsack](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Dynamic_Programming/0-1knapsack.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

int knapsack(int wt[],int val[],int W,int n)
{
    int t[n+1][W+1]; //DP matrix

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            if(i==0 || j==0) //base case filling 1st row and 1st column of the matrix with zero.
            {
                t[i][j] = 0;
            }
            else if(wt[i-1]<=j) // current wt can fit in bag 
            {
                int val1 = val[i-1] + t[i-1][j-wt[i-1]]; // take current wt and after taking weight substract the inserted weight from the final weight
                int val2 = t[i-1][j]; // skip current weight
                t[i][j] = max(val1,val2);
            }
            else if(wt[i-1] > j) // current wt doesn't fit in bag
            {
                t[i][j] = t[i-1][j]; //move to next
            }
        }
        
    }
    return t[n][W];
}

int main()
{
    int n;
    cin>>n;
    int val[n],wt[n];
    for(int i=0;i<n;i++)
    {
        cin>>wt[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>val[i];
    }
    int W;
    cin>>W;
    cout<<knapsack(wt,val,W,n)<<endl;
    return 0;
}
```

## 3. [Binary Coefficient](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Dynamic_Programming/binary_coefficient.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

long long nCr(int n,int r)
{
    long long int ans = 1;
    if(n<r)
    {
        return 0;
    }

    if(r > n-r)
    {
        r = n-r;
    }
    for(int i=0;i<r;i++)
    {
        ans *= (n-i);
        ans /= (i+1);
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,r;
        cin>>n>>r;
        cout<<nCr(n,r)<<endl;
    }
    return 0;
}
```

## 4. [Nth catalan number](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Dynamic_Programming/nth_catalan_number.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

long long nCr(int n,int r)
{
    long long int ans = 1;
    if(n<r)
    {
        return 0;
    }
    if(r>n-r)
    {
        r = n-r;
    }
    for(int i=0;i<r;i++)
    {
        ans *= (n-i);
        ans /= (i+1);
    }
    return ans;
}

int catalan(int n)
{
    int two_n_C_n = nCr(2*n,n);
    return two_n_C_n/(n+1);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<catalan(n)<<endl;
    }
    return 0;
}
```

## 5. [Edit Distance](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Dynamic_Programming/edit_distance.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

long long memo[102][102];
long long findLCS(string &s,string &t,long long n, long long m)
{
    // base condition
    /* case 1: string s is empty but t is not then total insertion will be current length of string t.
       case 2: string s not empty but t is empty hence than total deletion will be current length of s.
       case 3: if both are empty then 0.
    */
   for(long long i=0;i<n+1;i++)
   {
       for(long long j=0;j<m+1;j++)
       {
           if(i==0)
           {
               memo[i][j] = j;
           }
           if(j==0)
           {
               memo[i][j] = i;
           }
       }
   }
   memo[0][0] = 0;

   for(long long i=1;i<n+1;i++)
   {
       for(long long j=1;j<m+1;j++)
       {
           if(s[i-1]==t[j-1])
           {
               memo[i][j] = memo[i-1][j-1];
           }
           else
           {
               memo[i][j] = min({1+memo[i-1][j],1+memo[i][j-1],1+memo[i-1][j-1]});
           }
       }
   }
   return memo[n][m];
}

long long editDistance(string s,string t)
{
    memset(memo,-1,sizeof(memo));
    long long n = s.size();
    long long m = t.size();
    long long ans = findLCS(s,t,n,m);
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s,t;
        cin>>s>>t;
        cout<<editDistance(s,t)<<endl;
    }
    return 0;
}
```

## 6. [Equal subset sum](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Dynamic_Programming/equal_subset_sum.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool subsetSum(int arr[],int n,int sum)
    {
        vector<vector<bool>> tabu(n+1,vector<bool>(sum+1));
        for(int i=0;i<n+1;i++)
        {
            tabu[i][0] = true;
        }
        for(int j=1;j<sum+1;j++)
        {
            tabu[0][j] = false;
        }

        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<sum+1;j++)
            {
                if(arr[i-1]<=j)
                {
                    tabu[i][j] = tabu[i-1][j-arr[i-1]] || tabu[i-1][j];
                }
                else
                {
                    tabu[i][j] = tabu[i-1][j];
                }
            }
        }
        return tabu[n][sum];
    }

    int equalPartition(int N,int arr[])
    {
        int sum=0;
        for(int i=0;i<N;i++)
        {
            sum += arr[i];
        }
        // this is crux of whole problem
        // if sum found is odd then its not possible to divide the array in 2 subset
        // and if sum found is even then we can use subset sum problem/implemetation to complete rest of the problem.
        if(sum%2)
        {
            return 0;
        }
        sum /= 2;
        return subsetSum(arr,N,sum);


    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        Solution ob;
        cout<<ob.equalPartition(n,a)<<endl;
    }
    return 0;
}
```

## 7. [Friends pairing problem](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Dynamic_Programming/friend_pairing_problem.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9+7;
int countFriendsPairings(int n)
{
    long long dp[n+1];
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<n+1;i++)
    {
        if(i<=2)
        {
            dp[i]=i;
        }
        else
        {
            dp[i] = (dp[i-1] + ((i-1)*dp[i-2])%mod)%mod;
        }
    }
    return dp[n];
}

int main()
{
    int n;
    cin>>n;
    cout<<countFriendsPairings(n)<<endl;
    return 0;
}
```

## 8. [Gold mine](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Dynamic_Programming/gold_mine.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

const int MAX=100;
// Returns maximum amount of gold that can be collected 
// when journey started from first column and moves 
// allowed are right, right-up and right-down 
int getMaxGold(int gold[][MAX],int m,int n)
{
    int goldTable[m][n];
    memset(goldTable,0,sizeof(goldTable));

    for(int col=n-1;col>=0;col--)
    {
        for(int row=0;row<m;row++)
        {
            // Gold collected on going to the cell on the right(->) 
            int right = (col == n-1) ? 0 : goldTable[row][col+1];

            // Gold collected on going to the cell to right up (/) 
            int right_up = (row== 0 || col==n-1) ? 0 : goldTable[row-1][col+1];

            // Gold collected on going to the cell to right down(\)
            int right_down = (row== m-1 || col==n-1) ? 0 : goldTable[row+1][col+1];

            // Max gold collected from taking either of the above 3 paths
            goldTable[row][col] = gold[row][col] + max(right,max(right_up,right_down));
        }
    }
    // The max amount of gold collected will be the max 
    // value in first column of all rows 
    int res = goldTable[0][0];
    for(int i=1;i<m;i++)
    {
        res = max(res,goldTable[i][0]);
    }
    return res;
}

int main()
{
    int gold[MAX][MAX] = {{1,3,1,5},{2,2,4,1},{5,0,2,3},{0,6,1,2}};
    int m=4,n=4;
    cout<<getMaxGold(gold,m,n)<<endl;
    return 0;
}
```