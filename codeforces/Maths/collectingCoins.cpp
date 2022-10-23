#include<bits/stdc++.h>
using namespace std;

#define fastread() ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

int main()
{
    ll tc,n;
    cin>>tc;
    while(tc--){
        ll arr[3];
        cin>>arr[0]>>arr[1]>>arr[2]>>n;
        sort(arr,arr+3);
        ll diff = arr[2]-arr[0];
        diff += arr[2]-arr[1];

        if(n>=diff){
            n -= diff;
            if(n%3==0) cout<<"YES\n";
            else cout<<"NO\n";
        }
        else cout<<"NO\n";
    }
    return 0;
}