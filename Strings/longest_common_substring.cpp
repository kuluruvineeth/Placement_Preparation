/*
Given two strings ‘X’ and ‘Y’, find the length of the longest common substring. 
Input : X = “abcdxyz”, y = “xyzabcd” 
Output : 4 
Explanation:
The longest common substring is “abcd” and is of length 4.
*/
#include<bits/stdc++.h>
using namespace std;

int LCStr(string s1,string s2,int m,int n)
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
                dp[i][j] = 0;
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
        int m,n;
        cin>>m>>n;
        cin>>s1>>s2;
        cout<<LCStr(s1,s2,m,n)<<endl;
    }
}