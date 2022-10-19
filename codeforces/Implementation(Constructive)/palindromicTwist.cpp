#include<bits/stdc++.h>
using namespace std;

#define fastread() ios_base::sync_with_stdio(false),cin.tie(0);

int main()
{
    int t,n,i,h,d;
    char str[105];
    bool k;

    cin>>t;
    while(t--)
    {
        cin>>n>>str;
        h=n/2;
        k=true;
        for(i=0;i<h;i++)
        {
            d = (int)(abs(str[i]-str[n-i-1]));
            if(!(d==0 || d==2))
            {
                k = false;
                cout<<"NO\n";
                break;
            }
        }
        if(k) cout<<"YES\n";
    }
    return 0;
}