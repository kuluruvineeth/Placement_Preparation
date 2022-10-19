#include<bits/stdc++.h>
using namespace std;

#define fastread() ios_base::sync_with_stdio(false),cin.tie(0);

int main()
{
    int n,sum=0;
    cin>>n;
    for(int i=0;i<n;i++){
        sum += (i+1)*(n-i)-i;
    }
    cout<<sum<<endl;
    return 0;
}