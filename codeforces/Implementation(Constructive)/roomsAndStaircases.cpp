#include<bits/stdc++.h>
using namespace std;

#define fastread() ios_base::sync_with_stdio(false),cin.tie(0);

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>n>>s;
        int mx=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1'){
                mx = max({mx,i+1,n-i});
            }
        }
        if(mx==0) cout<<n<<"\n";
        else cout<<2*mx<<"\n";
    }
    return 0;
}