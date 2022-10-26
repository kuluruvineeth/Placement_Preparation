#include<bits/stdc++.h>
using namespace std;

#define fastread() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

enum{N=200009};
int a[N];
int main()
{
    fastread();
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int w=0,ans=0;
        for(int i=1;i<=n;i++) cin>>a[i], w+=a[i];
        for(int i=n-w+1;i<=n;i++) if(!a[i]) ans++;
        cout<<ans<<"\n";
    }
}