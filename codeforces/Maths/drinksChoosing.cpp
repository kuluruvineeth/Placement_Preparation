#include<bits/stdc++.h>
using namespace std;

int n,k,m,c=0;

int main()
{
    cin>>n>>k;
    int P[k];
    for(int i=0;i<k;i++) P[i]=0;
    for(int i=0;i<n;i++){
        cin>>m;
        P[m-1]=P[m-1]+1;
    }
    for(int i=0;i<k;i++){
        if(P[i]%2==1) c++;
    }
    cout<<(n-(c/2));
    return 0;
}