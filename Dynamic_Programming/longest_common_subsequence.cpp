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