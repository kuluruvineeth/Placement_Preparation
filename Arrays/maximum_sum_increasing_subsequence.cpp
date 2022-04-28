/*
The Maximum Sum Increasing Subsequence problem is to find the maximum sum subsequence of a given sequence such that all elements of the subsequence are sorted in increasing order.

Examples: 

Input:  [1, 101, 2, 3, 100, 4, 5]
Output: [1, 2, 3, 100]

Input:  [3, 4, 5, 10]
Output: [3, 4, 5, 10]
*/
#include<bits/stdc++.h>
using namespace std;

int maximum_sum_increasing_subsequence(int a[],int n)
{
    int mx=-1;
    int dp[n+1];
    for(int i=0;i<n;i++)
    {
        dp[i] = a[i];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[j]<a[i] && a[i]+dp[j] > dp[i])
            {
                dp[i] = a[i] + dp[j];
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        mx = max(mx,dp[i]);
    }
    return mx;
}

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
        cout<<maximum_sum_increasing_subsequence(a,n)<<endl;
    }
}