#include<bits/stdc++.h>
using namespace std;

#define fastread() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int main()
{
    fastread();
    int t,n,x;
    cin>>t;
    while(t--){
        cin>>n>>x;
        int c=2,ans=1;
        while(c<n){
            c += x;
            ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}