#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fastread() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int main()
{
    int t;
    ll a,b;
    cin>>t;
    while(t--){
        int div=0,pls=0;
        cin>>a>>b;
        if(a%b==0){
            cout<<"0\n";
            continue;
        }
        div=a/b;
        pls=(div+1)*b;
        cout<<pls-a<<endl;
    }
    return 0;
}