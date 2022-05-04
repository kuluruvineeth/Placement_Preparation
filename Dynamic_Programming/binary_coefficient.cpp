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