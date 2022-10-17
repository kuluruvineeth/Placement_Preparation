#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,a;
    cin>>n;
    int m[n];
    for(int i=1;i<=n;i++){
        cin>>a;
        m[a] = i;
    }
    for(int i=1;i<=n;i++){
        cout<<m[i]<<" ";
    }
    return 0;
}