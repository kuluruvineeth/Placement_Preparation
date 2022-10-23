#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll x,cnt=0;
    string s;
    cin>>s;
    x=s.size();
    for(int i=1;i<x;i++) if(s[i]=='1') cnt=1;
    if(x%2==0){
        cout<<x/2<<"\n";
        return 0;
    }
    cout<<(x/2+cnt)<<"\n";
    return 0;
}