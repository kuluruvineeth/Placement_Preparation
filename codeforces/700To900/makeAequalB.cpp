#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,d=0,x=0,y=0,pos=0;
        cin>>n;
        ll a[n],b[n],i,j;
        for(i=0;i<n;i++){
            cin>>a[i];
            if(a[i]==1) x++;
        }
        for(i=0;i<n;i++){
            cin>>b[i];
            if(b[i]==1) y++;
        }
        for(i=0;i<n;i++){
            if(a[i]!=b[i]) pos++;
        }
        d=abs(x-y);
        if(pos>0 && d!=pos) d++;
        cout<<d<<"\n";
    }
    return 0;
}