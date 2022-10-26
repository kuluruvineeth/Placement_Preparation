#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fastread() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<ll> a(n);
        ll ss=0;
        int ee[] = {0,0};
        for(int i=0;i<n;i++){
            cin>>a[i];
            ss += a[i];
            ee[a[i]%2]++;
        }
        while(q--){
            int tt,xx;
            cin>>tt>>xx;
            int oo = ee[tt];
            ee[tt] = 0;
            ee[(xx%2)!=tt] += oo;
            ss += xx * oo;
            cout<<ss<<"\n";
        }
    }
    return 0;
}