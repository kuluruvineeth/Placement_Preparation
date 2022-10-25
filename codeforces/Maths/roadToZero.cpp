#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fastread() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int main()
{
    fastread();
    int t;
    ll x,y,a,b;
    cin>>t;
    while(t--){
        cin>>x>>y>>a>>b;
        if(x>y) swap(x,y);
        ll ans1=0,ans2=0;
        ans1 = x*a + y*a;
        ll z = y-x;
        ans2 = z*a + x*b;
        cout<<min(ans1,ans2)<<"\n";
    }
    return 0;
}