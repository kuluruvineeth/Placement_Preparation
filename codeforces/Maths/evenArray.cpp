#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fastread() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define frn(i,n) for(int i=0;i<n;i++);

int main()
{
    fastread();
    int t,n,a[100];
    cin>>t;
    while(t--){
        int c=0,flag=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int odd=0,even=0;
        for(int i=0;i<n;i++){
            if(i%2!=a[i]%2){
                if(a[i]%2==1) odd++;
                else even++;
            }
        }
        if(odd!=even) cout<<"-1\n";
        else cout<<even<<"\n";
    }
    return 0;
}