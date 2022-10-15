#include<bits/stdc++.h>
using namespace std;

#define pb push_back

void solve()
{
    int n, q;
    cin>>n>>q;
    vector<long long> pref;
    pref.pb(0);
    vector<int> prefmax;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        pref.pb(pref.back()+x);
        if(i==0){
            prefmax.pb(x);
        }
        else{
            prefmax.pb(max(prefmax.back(),x));
        }
    }
    for(int i=0;i<q;i++){
        int k;
        cin>>k;
        int ind = upper_bound(prefmax.begin(),prefmax.end(),k) - prefmax.begin();
        cout<<pref[ind]<<" ";
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();    
    }
}