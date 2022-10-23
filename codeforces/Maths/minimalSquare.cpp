#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fastread() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int main()
{
    int t,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        if(a>b){
            swap(a,b);
        }
        cout<<max(a*2,b)*max(a*2,b)<<"\n";
    }
    return 0;
}