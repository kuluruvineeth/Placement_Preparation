#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fastread() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int main()
{
    fastread();
    int t;
    double n;
    ll ans;
    cin>>t;
    while(t--){
        ans=0;
        cin>>n;
        ans=ceil((n/2)-1);
        cout<<ans<<endl;
    }
    return 0;
}