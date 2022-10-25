#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        int jokers = min(m,(n/k));
        int left = m-jokers;
        left = ceil((double)left/(k-1));
        cout<<jokers-left<<"\n";
    }
    return 0;
}