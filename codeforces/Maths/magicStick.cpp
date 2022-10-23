#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fastread() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int main()
{
    fastread();
    int t;
    cin>>t;
    ll x,y;
    while(t--){
        cin>>x>>y;
        if(x==1 && y>1) cout<<"NO\n";
        else{
            if(x<=3 && y>3) cout<<"NO\n";
            else cout<<"YES\n";
        }
    }
    return 0;
}