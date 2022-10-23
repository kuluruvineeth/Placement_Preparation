#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n,m,a;
    cin>>n>>m>>a;
    ll x,y,sum;
    x = n/a;
    y = m/a;
    if(n%a!=0) x=x+1;
    if(m%a!=0) y=y+1;
    sum=x*y;
    cout<<sum;
    return 0;
}