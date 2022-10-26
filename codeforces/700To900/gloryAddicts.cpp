#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fastread() ios_base::sync_with_stdio,cin.tie(0),cout.tie(0);
int t,n,i,x,a[200001];
vector<int> v[2];
ll s;

int main()
{
    fastread();
    cin>>t;
    while(t--){
        cin>>n;s=0;v[0].clear(),v[1].clear();
        for(i=1;i<=n;i++) cin>>a[i];
        for(i=1;i<=n;i++) cin>>x,v[a[i]].push_back(x),s+=2*x;
        sort(v[0].begin(),v[0].end());
        sort(v[1].begin(),v[1].end());
        if(v[0].size()!=v[1].size()){
            if(v[0].size()<v[1].size()) swap(v[0],v[1]);
            for(i=0;i<(int)v[0].size()-(int)v[1].size();i++) s -= v[0][i];
        }else s -= min(v[0][0],v[1][0]);
        cout<<s<<"\n";
    }
    return 0;
}