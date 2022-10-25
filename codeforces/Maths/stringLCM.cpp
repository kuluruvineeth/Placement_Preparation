#include<bits/stdc++.h>
using namespace std;

#define ll long long

string check(string s, int k)
{
    string r="";
    while(k--){
        r+=s;
    }
    return r;
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        string s,t;
        cin>>s>>t;
        ll g = __gcd(s.length(),t.length());
        if(check(s,t.length()/g)==check(t,s.length()/g))
            cout<<check(s,t.length()/g)<<"\n";
        else
            cout<<"-1\n";
    }
    return 0;
}