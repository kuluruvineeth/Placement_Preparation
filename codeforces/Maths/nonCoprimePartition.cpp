#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> f1;
vector<ll> f2;

int main()
{
    ll n,jor=0,bijor=0,ok=0,ok1=0,i,ans;
    cin>>n;
    if(n==1){
        cout<<"No\n"; 
        return 0;
    }
    else{
        for(i=1;i<=n;i++){
            if(i%2==0){
                jor+=i;
                f1.push_back(i);
                ok++;
            }
            else{
                bijor+=i;
                f2.push_back(i);
                ok1++;
            }
        }
        ans = __gcd(jor,bijor);
        if(ans>1){
            cout<<"Yes\n";
            cout<<ok<<" ";
            for(i=0;i<f1.size();i++) cout<<f1[i]<<" ";
            cout<<"\n";
            cout<<ok1<<" ";
            for(i=0;i<f2.size();i++) cout<<f2[i]<<" ";
        }
        else{
            cout<<"No\n";
        }
        return 0;
    }
}