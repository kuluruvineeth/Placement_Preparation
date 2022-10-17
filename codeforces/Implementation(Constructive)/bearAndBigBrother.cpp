#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    int ans=0;
    while(a <= b){
        ans++;
        a = 3*a;
        b=2*b;
    }
    cout<<ans<<endl;
}