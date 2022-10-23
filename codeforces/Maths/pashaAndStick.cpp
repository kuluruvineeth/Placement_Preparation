#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll t;
    cin>>t;
    if(t%2!=0) cout<<"0\n";
    else{
        if(t%4==0) cout<<(t/4-1)<<"\n";
        else cout<<t/4<<"\n";
    }
    return 0;
}