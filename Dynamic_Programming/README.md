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