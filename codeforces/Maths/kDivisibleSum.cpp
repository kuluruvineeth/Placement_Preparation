#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;

        ll cf = (n+k-1)/k;
        k *= cf;

        cout<<(k+n-1)/n<<"\n";
    }
    return 0;
}