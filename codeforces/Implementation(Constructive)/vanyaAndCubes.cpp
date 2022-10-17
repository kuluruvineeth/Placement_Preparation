#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin>>n;
    int ans=0;
    int i=1;
    int stop = i*(i+1)/2;
    while(n>=stop)
    {
        n -= stop;
        ans++;
        i++;
        stop = i*(i+1)/2;
    }
    cout<<ans<<"\n";
    return 0;
}