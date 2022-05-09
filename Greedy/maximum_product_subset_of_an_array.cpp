#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int zero_count = 0;
    int negative_count = 0;
    int prod=1;
    int max_negative = INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            zero_count++;
            continue;
        }
        if(a[i]<0)
        {
            negative_count++;
            max_negative = max(max_negative,a[i]);
        }
        prod = prod*a[i];
    }
    if(zero_count==n)
    {
        cout<<"0";
        return 0;
    }
    else if(negative_count==1 and zero_count+negative_count==n)
    {
        cout<<"0";
        return 0;
    }
    else if(negative_count&1) //if negative count is odd
    {
        prod = prod/max_negative;
    }
    cout<<prod;
    return 0;
}