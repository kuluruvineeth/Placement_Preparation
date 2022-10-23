#include<bits/stdc++.h>
using namespace std;

#define fastread() ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

void solve(){
    ll n,k;
    cin>>n>>k;
    if(n==1) cout<<"0\n";
    else if(n==2) cout<<k<<"\n";
    else cout<<2*k<<"\n";
}

int main()
{
    fastread();
    int testcase;
    cin>>testcase;
    while(testcase--){
        solve();
    }
    return 0;
}