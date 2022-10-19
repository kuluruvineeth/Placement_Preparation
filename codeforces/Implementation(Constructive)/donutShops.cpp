#include<bits/stdc++.h>
using namespace std;

#define fastread() ios_base::sync_with_stdio(false),cin.tie(0);
#define ll long long

int main()
{
    fastread();
    int t;
    ll a,b,c,f,s;
    cin>>t;
    while(t--){
        f=-1,s=-1;
        cin>>a>>b>>c;

        if(a<c){
            f=1;
        }
        if(a*b > c){
            s=b;
        }
        cout<<f<<" "<<s<<endl;
    }
    return 0;
}