#include<bits/stdc++.h>
using namespace std;

#define fastread() ios_base::sync_with_stdio(0),cin.tie(0);

int main()
{
    int n,c(0),a[7];
    cin>>n;
    for(int i=0;i<7;i++) cin>>a[i];
    int p=a[0];
    while(p<n){
        c++;
        c %= 7;
        p += a[c];
    }
    cout<<c+1<<"\n";
    return 0;
}