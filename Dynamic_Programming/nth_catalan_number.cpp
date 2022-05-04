#include<bits/stdc++.h>
using namespace std;

long long nCr(int n,int r)
{
    long long int ans = 1;
    if(n<r)
    {
        return 0;
    }
    if(r>n-r)
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

int catalan(int n)
{
    int two_n_C_n = nCr(2*n,n);
    return two_n_C_n/(n+1);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<catalan(n)<<endl;
    }
    return 0;
}