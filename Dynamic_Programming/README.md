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

## 9. [Assembly line scheduling](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Dynamic_Programming/assembly_line_scheduling.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;
#define NUM_LINE 2
#define NUM_STATION 4

int carAssembly(int a[][NUM_STATION],int t[][NUM_STATION],int *e, int *x)
{
    int first,second,i;

    // Time taken to leave first 
    // station in line 1 
    first = e[0] + a[0][0];

    // Time taken to leave first
    // station in line 2
    second = e[1] + a[1][0];

    for(i=1;i<NUM_STATION;i++)
    {
        int up = min(first+a[0][i],second+t[1][i]+a[0][i]);
        int down = min(second+a[1][i],first+t[0][i]+a[1][i]);
        first = up;
        second = down;
    }
    // consider exit times and return minimum
    return min(first+x[0],second+x[1]);
}

int main()
{
    int a[][4] = {{4,5,3,2},{2,10,1,4}};
    int t[][4] = {{0,7,4,5},{0,9,2,8}};
    int e[] = {10,12}, x[]={18,7};
    cout<<carAssembly(a,t,e,x)<<endl;
    return 0;
}
```

## 10. [Longest common subsequence](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Dynamic_Programming/longest_common_subsequence.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;

class Solution
{
    public:
    int lcs(int x,int y,string s1,string s2)
    {
        int n=s1.size();
        int m=s2.size();
        int arr[n+1][m+1];
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<m+1;j++)
            {
                if(i==0 || j==0)
                {
                    arr[i][j]=0;
                }
            }
        }
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    arr[i][j] = arr[i-1][j-1] + 1;
                }
                else
                {
                    arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
                }
            }
        }
        return arr[n][m];
    }
};

int main()
{
    int t,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;
        string s1,s2;
        cin>>s1>>s2;
        Solution ob;
        cout<<ob.lcs(x,y,s1,s2)<<endl;
    }
    return 0;
}
```

## 11. [Longest Increasing Subsequence](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Dynamic_Programming/longest_increasing_subsequence.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int longestSubsequence(int n, int a[])
    {
        int dp[n];
        dp[0]=1;
        for(int i=1;i<n;i++)
        {
            dp[i]=1;
            for(int j=0;j<i;j++)
            {
                if(a[i]>a[j] && dp[i]<=dp[j])
                {
                    dp[i]=dp[j]+1;
                }
            }
        }
        return *max_element(dp,dp+n);
    }
};

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        Solution ob;
        cout<<ob.longestSubsequence(n,a)<<endl;
    }
}
```

## 12. [Maximize the cut segments](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Dynamic_Programming/maximize_the_cut_segments.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int maximizeTheCuts(int n,int x,int y,int z)
    {
        vector<int> arr(n+1,-1);
        arr[0]=0;
        for(int i=1;i<=n;i++)
        {
            int mnn = INT_MIN;
            if(x<=i && arr[i-x]!=-1)
            {
                mnn = max(mnn,arr[i-x]);
            }
            if(y<=i && arr[i-y]!=-1)
            {
                mnn = max(mnn,arr[i-y]);
            }
            if(z<=i && arr[i-z]!=-1)
            {
                mnn = max(mnn,arr[i-z]);
            }
            if(mnn != INT_MIN)
            {
                arr[i] = mnn+1;
            }
        }
        return (arr[n] == -1 ? 0 : arr[n]);
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
        int x,y,z;
        cin>>x>>y>>z;
        Solution ob;
        cout<<ob.maximizeTheCuts(n,x,y,z)<<endl;
    }
    return 0;
}
```

## 13. [LCS of 3strings](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Dynamic_Programming/LCS_of_3string.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

int LCSof3(string a, string b, string c,int m,int n,int o)
{
    int memo[n+1][m+1][o+1];
    memset(memo,-1,sizeof(memo));
    for(int i=0;i<m+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            for(int k=0;k<o+1;k++)
            {
                if(i==0 || j==0 || k==0)
                {
                    memo[i][j][k] = 0;
                }
            }
        }
    }
    for(int i=1;i<m+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            for(int k=1;k<o+1;k++)
            {
                if(a[i-1]==b[j-1] && b[j-1]==c[k-1])
                {
                    memo[i][j][k] = 1 + memo[i-1][j-1][k-1];
                }
                else
                {
                    memo[i][j][k] = max({memo[i-1][j][k],memo[i][j-1][k],memo[i][j][k-1]});
                }
            }
        }
    }
    return memo[m][n][o];
}

int main()
{
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    cout<<LCSof3(s1,s2,s3,s1.length(),s2.length(),s3.length())<<endl;
    return 0;
}
```