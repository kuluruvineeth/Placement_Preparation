#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i,n,m) for(ll i=n;i<(ll)m;i++)
#define fastread() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
template<typename T>T acc(const vector<T> &v){return accumulate(v.begin(),v.end(),T(0));};
template<typename T>T max(const vector<T> &v){return *max_element(v.begin(),v.end());}


int main()
{
    fastread();
    ll t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<ll> a(n),b(n);
        rep(i,0,n) cin>>a[i];
        rep(i,0,n) cin>>b[i];
        cout<<acc(a)+acc(b)-max(b)<<endl;
    }
    return 0;
}