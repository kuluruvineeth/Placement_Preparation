#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int nsev=0;
    int nfr=0;
    while(n>=0){
        if(n%7==0){
            nsev=n/7;
            n=0;
            break;
        }
        nfr++;
        n=n-4;
    }
    if(n==0){
        while(nfr--) cout<<"4";
        while(nsev--) cout<<"7";
    }
    else cout<<"-1\n";
    return 0;
}