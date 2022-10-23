#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n,m,k;
    cin>>n>>m>>k;
    ll fmax=0,smax=0;
    for(int i=0;i<n;i++){
        ll temp;
        cin>>temp;
        if(temp>fmax){
            smax=max(fmax,smax);
            fmax=temp;
        }
        else{
            if(temp>smax){
                fmax=max(fmax,smax);
                smax=temp;
            }
        }
    }
    if(smax>fmax) swap(smax,fmax);
    ll ans=0,temp;
    temp=m/(k+1);
    ans+=(temp*smax);
    temp=m-temp;
    ans+=(temp*fmax);
    cout<<ans<<endl;
    return 0;
}