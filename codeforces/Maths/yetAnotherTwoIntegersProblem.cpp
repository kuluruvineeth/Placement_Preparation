#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fastread() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int main()
{
    fastread();
    ll t,a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        if(b<a) swap(a,b);
        ll sub=0,div=0,mod=0,sum=0;
        sub=b-a;
        div=sub/10;
        mod=sub%10;
        sum=div;
        if(mod>0) sum++;
        cout<<sum<<"\n";
    }
    return 0;
}