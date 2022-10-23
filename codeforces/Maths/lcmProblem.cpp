#include<bits/stdc++.h>
using namespace std;

#define fastread() ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

int main()
{
    fastread();
    ll t;
    ll l,r;
    cin>>t;
    while(t--){
        ll x=0,y=0;
        cin>>l>>r;
        if(l*2 <= r){
            x = l;
            y = l*2;
        }
        else{
            x=-1;
            y=-1;
        }
        cout<<x<<" "<<y<<endl;
    }
    return 0;
}