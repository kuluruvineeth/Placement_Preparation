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