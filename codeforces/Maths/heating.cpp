#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fastread() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int main()
{
    ll n;
    cin>>n;
    while(n--){
        ll cnt,s;
        cin>>cnt>>s;
        ll d = (s/cnt);
        ll m = (s%cnt);
        ll ans = (cnt-m)*d*d + m*(d+1)*(d+1);
        cout<<ans<<"\n";
    }
    return 0;
}