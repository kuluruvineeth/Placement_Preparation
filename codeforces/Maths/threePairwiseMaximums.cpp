#include<bits/stdc++.h>
using namespace std;

#define fastread() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long

int main()
{
    fastread();
    ll t,x,y,z;
    cin>>t;
    while(t--){
        cin>>x>>y>>z;
        if(x>y)swap(x,y);
        if(x>z)swap(x,z);
        if(y>z)swap(y,z);
        if(y==z){
            cout<<"YES\n";
            cout<<x<<" "<<x<<" "<<z<<endl;
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}