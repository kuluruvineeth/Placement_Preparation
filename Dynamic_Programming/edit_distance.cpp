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