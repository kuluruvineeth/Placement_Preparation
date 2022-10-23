#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n,k,x;
    cin>>n;
    while(n--){
        cin>>k>>x;
        cout<<((k-1)*9)+x<<endl;
    }
    return 0;
}