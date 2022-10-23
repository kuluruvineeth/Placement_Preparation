#include<bits/stdc++.h>
using namespace std;

#define fastread() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int main()
{
    fastread();
    int t,n;
    cin>>t;
    while(t--){
        int ans = 0;
        cin>>n;
        ans = n/2;
        if(n%2 == 1) ans++;
        cout<<ans<<endl;
    }
    return 0;
}