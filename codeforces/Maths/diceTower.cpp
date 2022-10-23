#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll tc,num;
    cin>>tc;
    while(tc--){
        cin>>num;
        ll num14 = num%14;
        if((num>14) && (num14>=1 && num14 <= 6)){
            cout<<"YES\n";
        }
        else cout<<"NO\n";
    }
    return 0;
}