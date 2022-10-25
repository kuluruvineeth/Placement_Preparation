#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll a,cnt=0;
    cin>>a;
    for(int i=1;i<=a;i++){
        cnt += pow(2,i);
    }
    cout<<cnt;
    return 0;
}