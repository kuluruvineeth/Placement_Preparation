#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fastread() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int main()
{
    fastread();
    ll t;
    ll x,y,n;
    cin>>t;
    while(t--){
        cin>>x>>y>>n;
        ll cnt = n/x;
        ll ans = x*cnt + y;
        if(ans>n) ans -= x;
        cout<<ans<<"\n";
    }
    return 0;
}