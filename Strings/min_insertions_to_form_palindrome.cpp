/*
Given string str, the task is to find the minimum number of characters to be inserted to convert it to a palindrome.
ab: Number of insertions required is 1 i.e. bab
*/
#include<bits/stdc++.h>
using namespace std;

int LCS(string s1,string s2,int m,int n)
{
    int dp[m+1][n+1];
    int result = 0;
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j] = 0;
            }
            else if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
                result = max(result,dp[i][j]);
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return result;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1,s2;
        int n;
        cin>>s1;
        n = s1.size();
        s2 = s1;
        reverse(s2.begin(),s2.end());
        cout<<n - LCS(s1,s2,n,n) << endl;
    }
}