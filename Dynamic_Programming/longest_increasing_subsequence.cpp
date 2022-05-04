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