#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fr(i,n) for(ll i=0;i<n;i++)
#define fr1(i,n) for(ll i=1;i<=n;i++)

int main()
{
    ll n,i;
    cin>>n;
    ll a[n];
    fr(i,n) cin>>a[i];
    sort(a,a+n);

    if(a[n-3]+a[n-2] <= a[n-1]) cout<<"NO\n";
    else{
        cout<<"YES\n";
        cout<<a[n-1]<<" ";
        for(i=n-3;i>=0;i--) cout<<a[i]<<" ";
        cout<<a[n-2]<<"\n";
    }
    return 0;
}