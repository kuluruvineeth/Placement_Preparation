#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        int x = (a+b+c)/9;
        if(x<=min(a,min(b,c)) && (a+b+c)%9==0){
            cout<<"YES\n";
        }
        else cout<<"NO\n";
    }
    return 0;
}