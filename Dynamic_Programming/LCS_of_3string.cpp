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