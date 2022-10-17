#include<bits/stdc++.h>
using namespace std;

int main()
{
    int k,n,w;
    cin>>k>>n>>w;
    int total = k * (w*(w+1)/2);
    if(total > n) cout<<(total-n)<<endl;
    else cout<<0<<endl;
    return 0;
}