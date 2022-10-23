#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fastread() ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

int main()
{
    fastread();
    string s;
    ll money;
    cin>>s;
    vector<ll> need(3),have(3),cost(3);

    for(int i=0;i<s.size();i++){
        if(s[i]=='B') need[0]++;
        if(s[i]=='S') need[1]++;
        if(s[i]=='C') need[2]++;
    }
    for(int i=0;i<3;i++) cin>>have[i];
    for(int i=0;i<3;i++) cin>>cost[i];
    cin>>money;
    ll minBurger=0,maxBurger=100000000000000ll,middle,din=0ll,ans=0ll,aux=0;

    while(minBurger <= maxBurger){
        din=0ll;
        middle = (minBurger + maxBurger) / 2ll;
        for(int i=0;i<3;i++){
            aux = need[i]*middle;
            aux = have[i] - aux;
            if(aux<0){
                din += abs(aux)*cost[i];
            }
        }
        if(din<=money){
            ans = middle;
            minBurger = middle + 1ll;
        }
        else{
            maxBurger = middle - 1ll;
        }
    }
    cout<<ans;
    return 0;
}