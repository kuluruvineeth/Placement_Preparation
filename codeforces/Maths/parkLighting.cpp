#include<bits/stdc++.h>
using namespace std;

#define fastread() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long

int main()
{
    int t,n,m;
    cin>>t;
    while(t--){
        double A,B;
        cin>>n>>m;
        A=n,B=m;
        ll ans = 0;
        ans = ceil((A*B)/2);
        cout<<ans<<"\n";
    }
    return 0;
}