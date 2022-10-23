#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fastread() ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define fr(i,n) for(ll i=0;i<n;i++)


int main()
{
    ll n,k;
    cin>>n>>k;
    ll a[n],b[n];
    fr(i,n) cin>>a[i];
    fr(i,n) cin>>b[i];

    ll l=0,r=2*1e9+10,cnt=0,ans=0;
    while(l<=r){
        ll mid = (l+r)/2;
        cnt=0;
        fr(i,n){
            cnt += max(0ll,a[i]*mid-b[i]);
            if(cnt>k) break;
        }
        if(cnt<=k) l=mid+1,ans=mid;
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}